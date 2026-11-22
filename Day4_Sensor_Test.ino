#include <DHT.h>

// =========================
// PIN SENSOR
// =========================
#define DHTPIN D5
#define DHTTYPE DHT11

#define LDR_PIN A0

// =========================
// DHT OBJECT
// =========================
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  Serial.println();
  Serial.println("================================");
  Serial.println("     MINI TELEMETRY SYSTEM");
  Serial.println("     SENSOR TEST - DAY 4");
  Serial.println("================================");
  Serial.println("DHT11 + LDR");
  Serial.println();
}

void loop() {

  // =========================
  // BACA DHT11
  // =========================
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // =========================
  // BACA LDR
  // =========================
  int light = analogRead(LDR_PIN);

  // =========================
  // CEK DHT11
  // =========================
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("ERROR: DHT11 tidak terbaca!");
  } 
  else {
    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity    : ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // =========================
  // TAMPILKAN LDR
  // =========================
  Serial.print("Light (LDR) : ");
  Serial.println(light);

  Serial.println("-------------------------------");

  // Update setiap 1 detik
  delay(1000);
}