float kfSensorVolts = 0.0048828125;
void bacaMoisture() {
  moisture_value[0] = analogRead(pinMoisture[1]);
  moisture_value[1] = analogRead(pinMoisture[2]);
  moisture_value[2] = analogRead(pinMoisture[0]);
  
  if (DEBUG) {
    Serial.println("Moisture Bawah = " + String(analogRead(pinMoisture[0])));
    Serial.println("Moisture Atas = " + String(analogRead(pinMoisture[1])));
    Serial.println("Moisture Tengah = " + String(analogRead(pinMoisture[2])));
  }
  delay(1000);
}
void bacaTeganganMoisture() {

}
