#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>6){
    
    int id = Serial.parseInt();
    char msg[5];
    msg[0] = Serial.read();
    msg[1] = Serial.read();
    msg[2] = Serial.read();
    msg[3] = Serial.read();
    msg[4] = Serial.read();
    
    Wire.beginTransmission(id);
    Wire.write(msg);
    Wire.endTransmission();
    Serial.read();
  }
}
