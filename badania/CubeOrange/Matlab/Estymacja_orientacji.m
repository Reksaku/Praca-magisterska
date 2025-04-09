% Wczytanie danych z pliku CSV
data = readtable(['dane_cyklista.csv']);

% Ekstrakcja danych z tabeli
time = data.Timestamp;               % Czas 
accel_x = data.Accelerometer_X;      % Akcelerometr X
accel_y = data.Accelerometer_Y;      % Akcelerometr Y
accel_z = data.Accelerometer_Z;      % Akcelerometr Z
gyro_x = data.Gyroscope_X;           % Żyroskop X (prędkość kątowa wokół X)
gyro_y = data.Gyroscope_Y;           % Żyroskop Y (prędkość kątowa wokół Y)
gyro_z = data.Gyroscope_Z;           % Żyroskop Z (prędkość kątowa wokół Z)
simx = data.Sim_Location_X; %walidacja
simy = data.Sim_Location_Y;%walidacja
velox = data.Sim_Speed_X;%walidacja
veloy = data.Sim_Speed_Y;%walidacja
obrotz = data.Sim_Rotation_yaw(1);

% Obliczenie różnic czasowych
dt = diff(time); 
dt = [dt; dt(end)]; % Uzupełnienie ostatniego elementu, aby zachować wymiary

% Inicjalizacja zmiennych do przechowywania prędkości, pozycji oraz orientacji
N = length(time);
velocity_x = zeros(1, N); % Prędkość w osi x
velocity_y = zeros(1, N); % Prędkość w osi y
position_x = zeros(1, N); % Pozycja w osi x
position_y = zeros(1, N); % Pozycja w osi y

% Inicjalizacja kąta orientacji
angle_z = obrotz * pi / 180; % Początkowy kąt obrotu wokół osi Z (radiany)


accel_z = accel_z - 9.81;


accel = [accel_x,accel_y,accel_z]; % Przyspieszenie
gyro = [gyro_x,gyro_y,gyro_z]; % Prędkość kątowa


n = length(accel); % liczba próbek
alpha = 0.98; % Współczynnik komplementarnego filtru (zwykle blisko 1)

% Inicjalizacja wektorów do przechowywania wyników
roll = zeros(n, 1);
pitch = zeros(n, 1);

% Inicjalizacja kątów na podstawie pierwszego pomiaru (lub można założyć 0)
roll(1) = atan2(accel(1, 2), accel(1, 3));
pitch(1) = atan2(-accel(1, 1), sqrt(accel(1, 2)^2 + accel(1, 3)^2));

% Główna pętla obliczająca orientację
for i = 2:n
    % Akcelerometr: obliczenie kątów pitch i roll
    roll_accel = atan2(accel(i, 2), accel(i, 3));
    pitch_accel = atan2(-accel(i, 1), sqrt(accel(i, 2)^2 + accel(i, 3)^2));
    
    % Żyroskop: obliczenie zmiany orientacji
    dt = 1/400; % Zakładając 100 Hz
    roll_gyro = roll(i-1) + gyro(i, 1) * dt;
    pitch_gyro = pitch(i-1) + gyro(i, 2) * dt;
    
    % Komplementarny filtr
    roll(i) = alpha * roll_gyro + (1 - alpha) * roll_accel;
    pitch(i) = alpha * pitch_gyro + (1 - alpha) * pitch_accel;
end

% Wizualizacja w 3D
figure;
grid on;
axis equal;
xlabel('X');
ylabel('Y');
zlabel('Z');

% Tworzymy obiekt, który będziemy obracać zgodnie z obliczoną orientacją
[x, y, z] = cylinder([0.01, 0]); % Prosta reprezentacja strzałki
h = surf(x, y, z); % Wyświetlenie obiektu

% Animacja
for i = 500:n
    % Utwórz macierz rotacji z kątów Eulera (roll, pitch, yaw)
    % W tym przypadku używamy tylko roll i pitch, a yaw ustawiamy na 0
    R = eul2rotm([0, roll(i), pitch(i)], 'ZYX'); % Zmodyfikowane: yaw = 0
    
    % Obróć obiekt
    tform = hgtransform('Matrix', [R, [0; 0; 0]; 0 0 0 1]);
    set(h, 'Parent', tform);
    
    % Odśwież wizualizację
    drawnow;
    pause(1/800);
end