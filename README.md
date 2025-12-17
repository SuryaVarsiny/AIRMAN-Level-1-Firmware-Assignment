# AIRMAN-Level-1-Firmware-Assignment
Level 1 UART telemetry pipeline for AIRMAN firmware assessment. Simulates IMU and environmental sensor data using sine/cosine, linear motion, and noise. Transmits at 20 Hz with XOR checksum. Python receiver validates frames and logs data to CSV.


How to Compile and Run:
gcc telemetry_tx.c -lm -o telemetry_tx
./telemetry_tx | python uart_rx.py

The C program generates simulated sensor telemetry at 20 Hz.
The Python script receives the data, validates the checksum, prints formatted output, and logs valid frames to a CSV file.

AI Tools Used:

ChatGPT was used to assist with understanding the assignment requirements, designing the telemetry frame format and implementing the XOR checksum logic.

Assumptions and Simplifications:

Sensor data is simulated using mathematical functions instead of real hardware sensors.
UART communication is simulated using standard input/output piping rather than a physical serial port.
Timing accuracy is approximate and sufficient for demonstrating the required 20 Hz telemetry rate.
Sensor values are assumed to be ideal, without modeling noise or calibration errors.
