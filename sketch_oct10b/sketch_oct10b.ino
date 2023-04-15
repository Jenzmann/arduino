#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(1);
  Wire.write("1r255");
  Wire.endTransmission();
  delay(1000);
  Wire.beginTransmission(1);
  Wire.write("1g255");
  Wire.endTransmission();
  delay(1000);
  Wire.beginTransmission(1);
  Wire.write("1r010");
  Wire.endTransmission();
  delay(1000);
  Wire.beginTransmission(1);
  Wire.write("1g020");
  Wire.endTransmission();
  delay(1000);
}
