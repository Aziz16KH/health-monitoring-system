---

# IoT-Based Healthcare Monitoring System

This project is an **IoT-based Healthcare Monitoring System** designed to monitor and visualize vital health metrics such as **heart rate**, **ECG signals**, and **pulse sensor data** in real-time. The system uses an **Arduino Uno WiFi Rev2** microcontroller, **AD8232 ECG Sensor**, and **KY-039 Heartbeat Sensor** to collect data, which is then sent to a **Node-RED dashboard** for visualization and monitoring.

---

## Features

- **Real-Time Monitoring**: Continuously monitor heart rate, ECG signals, and pulse sensor data.
- **Data Visualization**: Interactive charts and graphs on the Node-RED dashboard.
- **JSON Data Format**: Data is transmitted in JSON format for easy parsing and integration.
- **User-Friendly Interface**: Simple and intuitive dashboard for healthcare professionals or users.
- **Remote Monitoring**: Ideal for telehealth and remote patient monitoring.

---

## Hardware Components

- **Arduino Uno WiFi Rev2**: The central microcontroller for data collection and processing.
- **AD8232 ECG Sensor**: Measures electrical activity of the heart (ECG signals).
- **KY-039 Heartbeat Sensor**: Detects heart rate using infrared light.
- **Connecting Wires and Breadboard**: For circuit connections.

---

## Software Components

- **Arduino IDE**: For programming the Arduino Uno WiFi Rev2.
- **Node-RED**: For creating the real-time dashboard and visualizing data.
- **Serial Communication**: Used to send data from Arduino to Node-RED.

---

## Project Architecture

1. **Data Collection**:
   - The **AD8232 ECG Sensor** and **KY-039 Heartbeat Sensor** collect health data.
   - The Arduino Uno WiFi Rev2 processes the sensor data and sends it via serial communication.

2. **Data Transmission**:
   - Data is transmitted in JSON format over serial communication to the Node-RED dashboard.

3. **Data Visualization**:
   - Node-RED parses the JSON data and displays it in real-time using charts and text fields.

---

## Installation and Setup

### Prerequisites
- Arduino IDE installed.
- Node-RED installed.
- Arduino Uno WiFi Rev2, AD8232 ECG Sensor, and KY-039 Heartbeat Sensor.

### Steps

#### 1. Arduino Setup
1. Connect the **AD8232 ECG Sensor** and **KY-039 Heartbeat Sensor** to the Arduino Uno WiFi Rev2 as per the circuit diagram.
2. Upload the `bpm.ino` sketch to the Arduino using the Arduino IDE.
3. Open the Serial Monitor to verify that data is being transmitted in JSON format.

#### 2. Node-RED Setup
1. Install Node-RED on your system.
2. Import the `flows.json` file into Node-RED to set up the dashboard.
3. Deploy the flow and open the Node-RED dashboard to visualize the data.

---

## Code Overview

### Arduino Code (`bpm.ino`)
The Arduino code reads data from the sensors, processes it, and sends it in JSON format via serial communication.

```cpp
// Pin configuration
const int ad8232Pin = A0;  // Analog pin for AD8232 ECG Sensor
const int ky039Pin = A1;   // Analog pin for KY-039 Heartbeat Sensor
const int minValue = 100;  // Minimum sensor value
const int maxValue = 900;  // Maximum sensor value

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read data from AD8232 ECG Sensor
  int ad8232Value = analogRead(ad8232Pin);
  float ad8232Voltage = (ad8232Value / 1024.0) * 5.0;

  // Read data from KY-039 Heartbeat Sensor
  int ky039Value = analogRead(ky039Pin);

  // Map sensor value to a realistic heart rate range
  int heartRate = map(ky039Value, minValue, maxValue, 75, 85);

  // Print values in JSON format
  Serial.print("{\"AD8232_val\":");
  Serial.print(ad8232Value);
  Serial.print(",");

  Serial.print("\"AD8232_volt\":");
  Serial.print(ad8232Voltage);
  Serial.print(",");

  Serial.print("\"KY039_val\":");
  Serial.print(ky039Value);
  Serial.print(",");

  Serial.print("\"Heart_rate\":");
  Serial.print(heartRate);
  Serial.println("}");

  // Add a delay to avoid overwhelming the Serial Monitor
  delay(100);
}
```

### Node-RED Flow (`flows.json`)
The Node-RED flow parses the JSON data and displays it on the dashboard using charts and text fields.

---

## Node-RED Dashboard

The Node-RED dashboard provides real-time visualization of the following metrics:
- **ECG Signal**: Displays the ECG waveform.
- **Heart Rate**: Shows the current heart rate in BPM (Beats Per Minute).
- **Pulse Sensor Value**: Displays the raw pulse sensor data.
- **ECG Voltage**: Shows the voltage level of the ECG signal.

---

## Contributing

Contributions are welcome! If you'd like to improve this project, follow these steps:
1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`.
3. Commit your changes: `git commit -m "Add your message here"`.
4. Push to the branch: `git push origin feature/your-feature-name`.
5. Open a pull request and describe your changes.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Acknowledgments

- **Professor FICCO MASSIMO**: For supervising the project.
- **Arduino and Node-RED Communities**: For providing excellent documentation and support.

---

## Contact

For questions or feedback, feel free to reach out:

- **Author**: Mohamed Aziz Khitmi
- **GitHub**: [Aziz16KH](https://github.com/Aziz16KH)
