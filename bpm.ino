// Pin configuration
const int ad8232Pin = A0;  // Analog pin to which AD8232 OUT pin is connected
const int ky039Pin = A1;   // Analog pin to which KY-039 OUT pin is connected
const int minValue = 100;  // Adjust based on your observations
const int maxValue = 900;  // Adjust based on your observations
void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read data from AD8232 Heart Rate Monitor
  int ad8232Value = analogRead(ad8232Pin);
  float ad8232Voltage = (ad8232Value / 1024.0) * 5.0;

  // Read data from KY-039 Heartbeat Sensor
  int ky039Value = analogRead(ky039Pin);

  // Print the values to the Serial Monitor

  Serial.print("{\"AD8232_val\":");
  Serial.print(ad8232Value);
  Serial.print(",");

  Serial.print("\"AD8232_volt\":");
  Serial.print(ad8232Voltage);
  Serial.print(",");

 // Map the sensor value to a realistic heart rate range
  int heartRate = map(ky039Value, minValue, maxValue, 75, 85);

  // Print the values to the Serial Monitor
  Serial.print("\"KY039_val\":");
  Serial.print(ky039Value);
  Serial.print(",");

  Serial.print("\"Heart_rate\":");
  Serial.print(heartRate);
  Serial.println("}");

  // Add a delay to avoid overwhelming the Serial Monitor
  delay(100);
}
