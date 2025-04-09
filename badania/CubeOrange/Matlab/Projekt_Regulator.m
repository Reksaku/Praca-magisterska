%% Punkt a) Projekt regulatora
clear;
close all;
clc;

% Definiujemy model rośliny (plant) podany w zadaniu
s = tf('s');
G = 1 / (s * (s + 1) * (s + 10));

% Projektujemy kompensator GC na podstawie podanego rozwiązania
K = 450;
Gc = K * (s + 0.5) / (s + 10);

% Tworzymy zamkniętą pętlę z regulatorem
T_open = Gc * G;
T_closed = feedback(T_open, 1);

Cl_poles = pole(T_closed);
disp('Bieguny układu zamknietego: ');
disp(Cl_poles(1:4))

% Dodaje do układu prefilter
Gp = 0.5 / (s + 0.5);
T_closed_Gp = Gp * T_closed;

% Wyświetlamy charakterystyki Bodego układu otwartego
figure;
bode(T_open, 'r', T_closed, 'b');
legend('Otwarta', 'Zamknieta');
title('Charakterystyka Bodego dla układu otwartego');


%
% Punkt b) Analiza za pomocą systune()
%

Gp = tf(1);  % Gp(s) = 1 !!! co to jest to ja nie wiem !!!
H = tf(1);   % H(s) = 1 To jest chyba coś od sprzężenia

% Tworzenie modelu strojenia
T0 = tunableTF('PI', 2, 2); % Strojenie jednowymiarowej transmitancji

% Zdefiniowanie struktury zamkniętej pętli
CL = feedback(T_open * T0, H);

CL.InputName = 'r';
CL.OutputName = 'y';

% Specyfikacja strojenia
Req1 = TuningGoal.StepTracking('r', 'y', 1);
Req1.InputScaling = 20;

% Wykonanie strojenia
[CL_tuned, info] = systune(CL, Req1);

% Wyświetlenie wyników
disp('Parametry regulatora:');
showTunable(CL_tuned)

% Rysowanie charakterystyki Bodego przed i po strojeniu
figure;
bode(T_open, 'r', T_closed, 'b', CL_tuned, 'g');
xlabel('Czas [s]');
ylabel('Sygnał');
legend('Closed loop','Z prefiltrowaniem', 'Regulator ciągły');
title('Charakterystyka Bodego dla układu z regulatorem');

figure;
step(T_closed, 10)
hold on
step(T_closed_Gp, 10)
hold on
step(CL_tuned, 10)
grid on;
legend('Closed loop','Z prefiltrowaniem', 'Strojona "systune"');
xlabel('Czas [s]');
ylabel('Sygnał');
title('Odpowiedź skokowa');


%
% Punkt d) Konwersja do regulatora dyskretnego
%

% Odczyt wartości bloku regulatora PID
PI_tuned = getBlockValue(CL_tuned, 'PI');
poles = pole(PI_tuned);

% Obliczenie częstotliwości dynamicznych
frequencies = abs(poles);

% Maksymalna częstotliwość dynamiczna
max_frequency = max(frequencies);

% Wyświetlenie wyniku
disp(['Maksymalna częstotliwość dynamiczna: ', num2str(max_frequency), ' rad/s']);

% Przeliczenie na Hz
max_frequency_Hz = max_frequency / (2 * pi);

% Wyświetlenie wyniku
disp(['Maksymalna częstotliwość dynamiczna: ', num2str(max_frequency_Hz), ' Hz']);

% Zastosowanie Reguły Nyquista-Shannona
T_dys = 1/(2*max_frequency_Hz);

% Wyświetlenie wyniku
disp(['Okres próbkowania regulatora teoretycznego: ', num2str(T_dys*1000), ' ms']);

Cd = c2d(PI_tuned, T_dys);

% Prezentacja rzeczywistej dyskretyzacji - 5 razy szybszy regulator
devider = 5;
T_dys = 1/(2*max_frequency_Hz) / devider;

% Wyświetlenie wyniku
disp(['Okres próbkowania regulatora żeczywistego: ', num2str(T_dys*1000), ' ms']);

Cd_real = c2d(PI_tuned, T_dys);

% Wyświetlamy charakterystykę Bodego dla regulatora dyskretnego
%figure;
%bode(Cd);
%title('Charakterystyka Bodego regulatora dyskretnego');

%%

%
% Punkt e) Przeprowadzenie symulacji w Simulink
%

% Otwórz model Simulinka
model = 'Projekt';
load_system(model);

% Uruchom symulację
simOut = sim(model);

% Pobierz dane z workspace (np. ze Scope)
u_Data = simOut.get('u');
ClosedLoop_Data = simOut.get('closed_loop');
Prefiltered_Data = simOut.get('prefiltered');
Regulator_Data = simOut.get('regulator');
Disc_regulator_Data = simOut.get('disc_regulator');
Real_Disc_Regulator_Data = simOut.get('real_disc_regulator');

% Wyciągnij czas
czas = ClosedLoop_Data.time;

% Narysuj wykres wyników
figure;
plot(czas, u_Data.signals.values, "Color",[0, 0, 0],'LineStyle',':');
hold on
plot(czas, ClosedLoop_Data.signals.values);
hold on
plot(czas, Prefiltered_Data.signals.values);
hold on
plot(czas, Regulator_Data.signals.values);
hold on
plot(czas, Disc_regulator_Data.signals.values);
hold on
plot(czas, Real_Disc_Regulator_Data.signals.values);
xlabel('Czas [s]');
ylabel('Sygnał');
title('Symulacja w Simulink');
legend('Wymuszenie', 'Closed loop','Z prefiltrowaniem', 'Regulator ciągły', 'Regulator dyskretny', 'Szybki regulator dyskretny');
grid on;