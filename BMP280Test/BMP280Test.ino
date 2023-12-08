#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"


Adafruit_BME280 bme;

void setup() {
  // put your setup code here, to run once:
// BMP280 starten

unsigned status;
  Serial.begin(9600);
  status = bme.begin();

    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        while (1) delay(10);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(bme.readTemperature());

}
