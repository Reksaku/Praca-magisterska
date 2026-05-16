# Inertial Navigation System for Multirotor UAV — Master's Thesis
 
**"Verification of the Effectiveness of an Inertial Navigation Algorithm on the Example of a Selected Flying Platform"**  
Warsaw University of Technology · Faculty of Electrical Engineering · Institute of Control  
Specialisation: Automation and Applied Robotics · 2026
 
> Author: **Mateusz Wyrzykowski** · Supervisor: dr inż. Michał Macias
 
---
 
## Overview
 
This project presents the development, implementation, and experimental verification of a standalone **Inertial Navigation System (INS)** for a multirotor Unmanned Aerial Vehicle (UAV). The system estimates orientation, velocity, and position exclusively from on-board IMU data — without GPS, vision, or any other external correction source.
 
The work covers the full research cycle: mathematical algorithm design → Python implementation → validation in the CARLA simulation environment → real-world flight tests on a custom-built quadrotor named **Dedal**.
 
---
 
## Key Results
 
| Metric | Result |
|---|---|
| Simulation position error (700 m route) | < ±2 m (~0.3% of total distance) |
| Orientation estimation accuracy (real flight) | < 0.5 rad error outside magnetic disturbance zones |
| SNR improvement after FIR filtering | +33–34 dB (99.97% noise power reduction) |
| Position error at t = 10 s (best cases) | < 1 m (7 out of 30 measurements) |
| Hypothesis H1 (< 1 m error in 10 s) | **Not confirmed** for MEMS-grade sensors without correction |
| Hypothesis H2 (filtering reduces drift) | **Confirmed** — significant stability improvement |
| Hypothesis H3 (dynamics affect accuracy) | **Partially confirmed** — non-linear relationship observed |
 
---
 
## Algorithm Architecture
 
The INS pipeline executes the following steps on every sample:
 
```
IMU raw data
    │
    ▼
[1] FIR low-pass + FIR high-pass filtering  (delay ≤ 200 ms)
    │
    ▼
[2] Orientation estimation                  (complementary filter, α = 0.998)
    │   gyroscope integration + accelerometer correction
    ▼
[3] Gravity compensation                    (Euler rotation matrix R = Rz·Ry·Rx)
    │
    ▼
[4] Velocity estimation                     (numerical integration, threshold 0.05 m/s²)
    │
    ▼
[5] Position estimation                     (numerical integration)
    │
    ▼
Estimated state: [x, y, z, vx, vy, vz, roll, pitch, yaw]
```
 
### Estimation variants tested
 
| Variant | Processing pipeline |
|---|---|
| 1 | Raw IMU data — no filtering |
| 2 | FIR low-pass + high-pass filtering |
| 3 | FIR filtering + Extended Kalman Filter (EKF) for accelerometer bias correction |
| 4 | FIR filtering + acceleration thresholding |
 
---
 
## Hardware Platform — UAV "Dedal"
 
A custom quadrotor was designed and built specifically for this research within the Student Astronautics Club at Warsaw University of Technology.
 
| Component | Specification |
|---|---|
| Frame | ZD-550 quadrotor, 9" propellers |
| Flight controller | **CubeOrange+** (ICM-42688-P IMU) |
| Onboard computer | **Nvidia Orin Development Kit** |
| Secondary IMU | **Redshift Labs UM7** (via CP2102 serial adapter) |
| GNSS (reference) | RadioLink TS-100 (±1 m HDOP) |
| Rangefinder | Garmin LIDAR-Lite 3 |
| Take-off weight | 3.5 kg · Max payload: 2 kg · Flight time: ~10 min |
 
The two independent IMUs enabled direct comparison of sensor quality and estimation repeatability under real flight conditions.
 
---
 
## Research Methodology
 
**Phase I — Simulation (CARLA)**  
Tests in the CARLA autonomous driving simulator using a noise-free virtual IMU at 400 Hz. This validated the mathematical correctness and numerical stability of the algorithm under ideal conditions.
 
**Phase II — Real flight tests**  
Five flight trajectories of increasing complexity were executed autonomously:
 
| Route | Shape | Key challenge |
|---|---|---|
| 1 | Arc (C-shape) | Baseline — smooth manoeuvres |
| 2 | Circle | Long trajectory, cumulative drift |
| 3 | Vertical (up/down) | Vibration during throttle changes |
| 4 | Point-to-point (M-shape) | Combined axes, takeoff excluded |
| 5 | Advanced multi-directional | All manoeuvre types combined |
 
---
 
## Software Stack
 
- **Python** — NumPy, pandas, SciPy, matplotlib, scikit-learn
- **ROS 2 (Ubuntu 24)** — modular node architecture:
  - `flight_controller_node` — MAVLink communication with CubeOrange+ via pymavlink
  - `imu_reader_node` — serial data acquisition from UM7
  - `estimator_node` — full INS pipeline (filter → orientation → gravity compensation → velocity → position)
  - `logger_node` — CSV data logging
  - `flask_control_node` — web-based in-flight control interface
- **MATLAB / Simulink** — supplementary signal analysis
---
 
## Project Structure
 
```
├── badania/
│   ├── CubeOrange/
│   │   ├── Estymator G.py          # Main INS estimator (all 4 variants)
│   │   ├── dataVisualize.py        # Raw IMU data visualisation
│   │   ├── estimationVisualize.py  # Estimation results visualisation
│   │   ├── imu_data.csv            # Recorded IMU data — sensor 1 (FC)
│   │   ├── imu2_data.csv           # Recorded IMU data — sensor 2 (UM7)
│   │   ├── imu3_data.csv           # Recorded IMU data — sensor 3
│   │   ├── estimations/            # Output CSV files per variant
│   │   ├── ros2_ws/                # ROS 2 workspace (CubeOrange)
│   │   └── Matlab/                 # MATLAB signal analysis scripts
│   └── UM7_serial.py               # UM7 IMU serial reader
├── ros2_ws/
│   └── src/
│       ├── estimator_pkg/          # Estimator ROS 2 node
│       ├── flight_controller_pkg/  # MAVLink flight controller node
│       ├── csv_pkg/                # CSV data publisher / saver
│       ├── log_data_pkg/           # Data logging node
│       ├── um7_pkg/                # UM7 IMU reader node
│       └── custom_msgs/            # Custom ROS 2 message definitions
└── requirements.txt
```
 
---
 
## Quick Start
 
### Standalone estimator (no ROS 2 required)
 
```bash
pip install -r requirements.txt
cd badania/CubeOrange
python "Estymator G.py"
```
 
Runs all four estimation variants sequentially and displays a 3D trajectory comparison plot.  
Results are saved to `estimations/estimation{1..4}.csv`.
 
### Full ROS 2 stack
 
```bash
cd ros2_ws
colcon build
source install/setup.bash
bash flight_controller.sh   # Launch flight controller + estimator nodes
bash server.sh              # Launch Flask visualisation server
```
 
---
 
## Conclusions
 
The experiments confirmed that a standalone MEMS-based INS is capable of **accurate short-term orientation tracking** but suffers from rapid position drift without external correction — a characteristic limitation of open-loop integration systems.
 
**What works well:**
- Orientation estimation performs on par with the on-board magnetometer
- FIR filtering reduces noise power by ~99.97%, strongly stabilising the estimator
- Position error remains manageable in the first few seconds of smooth flight
**Primary limitation:**
- Position drift becomes significant within 10–15 seconds, consistent with the theoretical properties of standalone MEMS INS
**Recommended next steps:**
- INS/GNSS loosely-coupled fusion (EKF-based)
- Barometer integration for vertical axis stabilisation
- Visual-Inertial Odometry (VIO) for GPS-denied environments
- Industrial-grade IMU with hardware vibration damping
---
 
## References
 
Key literature underpinning this work includes research on MEMS gyroscope noise modelling under temperature and helium exposure (Sierociuk, Macias et al., *Sensors* 2025), ring laser gyroscope theory (Chow et al., *Rev. Mod. Phys.* 1985), and vibration rectification error in capacitive MEMS accelerometers (Zhang et al., *Micromachines* 2024). Full bibliography available in the thesis PDF.
 
---
 
## Academic Context
 
| Field | Detail |
|---|---|
| University | Warsaw University of Technology |
| Faculty | Faculty of Electrical Engineering |
| Institute | Institute of Control |
| Degree programme | Automation and Applied Robotics |
| Specialisation | Automation |
| Year | 2026 |