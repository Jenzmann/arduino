
//9 Blue
//10 Red
//11 Green

#include <DMXSerial.h>
int brightness;

void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);

DMXSerial.init(DMXReceiver);
}

void loop() {
  //brightness = DMXSerial.read(6);
  //analogWrite(10,map(DMXSerial.read(3)*brightness, 0,65025, 0,180));
  //analogWrite(11,map(DMXSerial.read(4)*brightness, 0,65025, 0,255));
  //analogWrite(9,map(DMXSerial.read(5)*brightness, 0,65025, 0,255));

  analogWrite(9,DMXSerial.read(3));
  analogWrite(10,DMXSerial.read(4));
  analogWrite(11,DMXSerial.read(5));
}
