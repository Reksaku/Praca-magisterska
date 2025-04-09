% Wczytanie danych z pliku CSV
data = readtable(['D:\OneDrive\Mavlink\imu_data.csv']);

%data = data(13800:end,1:end);

Time = data.Timestamp;
data.Timestamp = data.Timestamp - data.Timestamp(1);

for i = 2:size(Time)-1
    data.Timestamp(i) = data.Timestamp(i+1) - data.Timestamp(i);
    data.Timestamp(i) = data.Timestamp(i-1) + data.Timestamp(i);
end
data.Timestamp = data.Timestamp / 1000000;
Time = data.Timestamp;
