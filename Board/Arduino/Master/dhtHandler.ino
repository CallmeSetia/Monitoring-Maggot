#include <DHT.h>
#define dht_type DHT22

DHT dht_1(pinDht[0], dht_type); // Bawah
DHT dht_2(pinDht[1], dht_type); // Atas
DHT dht_3(pinDht[2], dht_type); // Tengah

void Dht_Init() {
  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
}

void bacaTemperature() {
  suhu_value[0] = dht_2.readTemperature();
  suhu_value[1] = dht_3.readTemperature();
  suhu_value[2] = dht_1.readTemperature();
  if (DEBUG) {
    Serial.println("Suhu 1 = " + String(dht_1.readTemperature()) + " C");
    Serial.println("Suhu 2 = " + String(dht_2.readTemperature()) + " C");
    Serial.println("Suhu 3 = " + String(dht_3.readTemperature()) + " C");
  }
  delay(1000);
}

void bacaKelembapan() {
  if (DEBUG) {
    Serial.println("Kelembapan 1 = " + String(dht_1.readHumidity()));
    Serial.println("Kelembapan 2 = " + String(dht_2.readHumidity()));
    Serial.println("Kelembapan 3 = " + String(dht_3.readHumidity()));
  }
  delay(1000);
}
