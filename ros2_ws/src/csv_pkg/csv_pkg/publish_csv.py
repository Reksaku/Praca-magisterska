#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import csv
import math
from pathlib import Path
from typing import List, Optional

import rclpy
from rclpy.node import Node
from rclpy.time import Time

from std_msgs.msg import UInt64
from std_msgs.msg import Float64MultiArray

class CsvPlayer(Node):
    """
    Odtwarza w czasie rzeczywistym rekordy z pliku CSV na podstawie znaczników czasu
    (mikrosekundy od uruchomienia urządzenia). Publikuje:
      - timestamps_us: std_msgs/UInt64 (oryginalny timestamp z CSV)
      - row_data: std_msgs/Float64MultiArray (pozostałe kolumny jako floaty)
    """

    def __init__(self):
        super().__init__('csv_player')

        # --- Parametry konfiguracyjne ---
        self.declare_parameter('csv_path', '/home/dron/Praca-magisterska/log_data/dane-fc-24_09_25-14_30_10.csv')
        self.declare_parameter('delimiter', ',')
        self.declare_parameter('has_header', True)
        self.declare_parameter('timestamp_col', 0)           # indeks kolumny z timestampem
        self.declare_parameter('publish_nan_on_non_numeric', False)
        self.declare_parameter('playback_speed', 1.0)        # >1.0 przyspiesza; <1.0 spowalnia
        self.declare_parameter('loop', False)                # zapętlaj po dojściu do końca?
        self.declare_parameter('skip_empty_rows', True)

        # Pobranie parametrów
        self.csv_path: str = self.get_parameter('csv_path').get_parameter_value().string_value
        self.delimiter: str = self.get_parameter('delimiter').get_parameter_value().string_value
        self.has_header: bool = self.get_parameter('has_header').get_parameter_value().bool_value
        self.timestamp_col: int = self.get_parameter('timestamp_col').get_parameter_value().integer_value
        self.publish_nan_on_non_numeric: bool = self.get_parameter('publish_nan_on_non_numeric').get_parameter_value().bool_value
        self.playback_speed: float = float(self.get_parameter('playback_speed').get_parameter_value().double_value)
        self.loop: bool = self.get_parameter('loop').get_parameter_value().bool_value
        self.skip_empty_rows: bool = self.get_parameter('skip_empty_rows').get_parameter_value().bool_value

        # Publisher’y
        self.pub_ts = self.create_publisher(UInt64, 'timestamps_us', 10)
        self.pub_row = self.create_publisher(Float64MultiArray, 'row_data', 10)

        # Stan odtwarzania
        self.rows: List[List[str]] = []
        self.ts_us: List[int] = []
        self.i: int = 0
        self._timer = None

        try:
            self._load_csv()
        except Exception as e:
            self.get_logger().error(f'Nie udało się wczytać CSV: {e}')
            raise

        if len(self.rows) == 0:
            self.get_logger().error('CSV nie zawiera danych do odtworzenia.')
            raise RuntimeError('CSV empty')

        # Normalizacja – upewnij się, że timestampy są niemalejące (nie wymagane, ale pomocne)
        # oraz że są typu int (mikrosekundy)
        for k in range(len(self.ts_us)):
            if self.ts_us[k] is None:
                raise ValueError(f'Wiersz {k}: brak poprawnego timestampu.')
        if any(self.ts_us[k] < self.ts_us[k-1] for k in range(1, len(self.ts_us))):
            self.get_logger().warn('Wykryto malejące timestampy – opóźnienia mogą wyjść ujemne. Zostaną ścięte do 0.')

        # Start
        self.get_logger().info(
            f'CSV załadowany: {self.csv_path} | rekordów: {len(self.rows)} | speed={self.playback_speed} | loop={self.loop}'
        )
        self._schedule_next(initial=True)

    # ----------------- Ładowanie CSV -----------------
    def _load_csv(self):
        path = Path(self.csv_path)
        if not path.exists():
            raise FileNotFoundError(f'Plik nie istnieje: {path}')

        with path.open('r', newline='') as f:
            reader = csv.reader(f, delimiter=self.delimiter)
            # Pomijanie nagłówka
            if self.has_header:
                try:
                    next(reader)
                except StopIteration:
                    return

            for row_idx, row in enumerate(reader):
                if row is None:
                    continue
                row = [cell.strip() for cell in row]
                if self.skip_empty_rows and all(c == '' for c in row):
                    continue

                # Timestamp w mikrosekundach
                try:
                    ts_val = int(row[self.timestamp_col])
                except (IndexError, ValueError) as e:
                    raise ValueError(f'Wiersz {row_idx}: problem z timestampem w kolumnie {self.timestamp_col}: {e}')

                # Pozostałe kolumny -> float (jeśli się da)
                payload = []
                for j, cell in enumerate(row):
                    if j == self.timestamp_col:
                        continue
                    if cell == '':
                        payload.append(math.nan)
                        continue
                    try:
                        payload.append(float(cell))
                    except ValueError:
                        if self.publish_nan_on_non_numeric:
                            payload.append(math.nan)
                        else:
                            # Pomijamy nienumeryczne – nadal publikujemy to, co liczby
                            # (możesz zmienić logikę, jeśli chcesz wymusić wszystkie liczby)
                            pass

                self.ts_us.append(ts_val)
                self.rows.append(payload)

        if len(self.rows) != len(self.ts_us):
            raise RuntimeError('Niespójne dane: liczba wierszy i timestampów różna.')

    # ----------------- Harmonogram publikacji -----------------
    def _schedule_next(self, initial: bool = False):
        """Tworzy "jednorazowy" timer o opóźnieniu wynikającym z różnicy timestampów."""
        if self.i >= len(self.rows):
            if self.loop:
                self.i = 0
            else:
                self.get_logger().info('Odtwarzanie zakończone.')
                # Zakończ łagodnie node zamiast killować proces
                rclpy.shutdown()
                return

        # Dla pierwszego rekordu – publikuj od razu
        delay_s = 0.0
        if not initial and self.i > 0:
            dt_us = max(0, self.ts_us[self.i] - self.ts_us[self.i - 1])
            # playback_speed: 2.0 -> dwa razy szybciej, więc krótsze opóźnienie
            delay_s = (dt_us / 1e6) / max(self.playback_speed, 1e-12)

        # Tworzymy nowy jednorazowy timer
        if self._timer is not None:
            try:
                self._timer.cancel()
            except Exception:
                pass
            self._timer = None

        # Minimalne opóźnienie, żeby nie "zalać" pętli przy zerowych dt
        delay_s = max(0.0, float(delay_s))
        self._timer = self.create_timer(delay_s, self._on_timer)

    def _on_timer(self):
        """Publikacja bieżącego wiersza i zaplanowanie następnego."""
        # Unieważnij timer (zachowujemy się jak one-shot)
        if self._timer is not None:
            try:
                self._timer.cancel()
            except Exception:
                pass
            self._timer = None

        # Publikacja aktualnego rekordu
        try:
            self._publish_row(self.i)
        except Exception as e:
            self.get_logger().error(f'Błąd publikacji wiersza {self.i}: {e}')

        # Przesuwamy indeks i planujemy kolejny
        self.i += 1
        self._schedule_next(initial=False)

    def _publish_row(self, idx: int):
        # timestamp
        ts_msg = UInt64()
        ts_msg.data = int(self.ts_us[idx])
        self.pub_ts.publish(ts_msg)

        # dane numeryczne
        row_msg = Float64MultiArray()
        row_msg.data = [float(v) for v in self.rows[idx]]
        self.pub_row.publish(row_msg)

        # (opcjonalnie) log do debugowania co N rekordów
        if idx % 1000 == 0 or idx == len(self.rows) - 1:
            self.get_logger().debug(f'Published idx={idx}, ts_us={ts_msg.data}, len(row)={len(row_msg.data)}')


def main():
    rclpy.init()
    node = None
    try:
        node = CsvPlayer()
        rclpy.spin(node)
    except Exception as e:
        if node:
            node.get_logger().error(str(e))
        else:
            print(f'CSV Player error: {e}')
    finally:
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()
