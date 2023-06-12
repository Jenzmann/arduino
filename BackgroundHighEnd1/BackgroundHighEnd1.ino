
//9 Red
//10 Blue
//11 Green

//11 Red
//10 Green
// 9 BLue

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
  brightness = DMXSerial.read(10);
  analogWrite(11,map(DMXSerial.read(7)*brightness, 0,65025, 0,120));
  analogWrite(10,map(DMXSerial.read(8)*brightness, 0,65025, 0,255));
  analogWrite(9,map(DMXSerial.read(9)*brightness, 0,65025, 0,255));

}
