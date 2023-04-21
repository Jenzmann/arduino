#include <DMXSerial.h>


void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
digitalWrite(9,LOW);
DMXSerial.init(DMXReceiver);

}

void loop() {
  // put your main code here, to run repeatedly:
if(DMXSerial.read(11)>150){
  digitalWrite(9,HIGH);
}
else{
  digitalWrite(9,LOW);
}
}
