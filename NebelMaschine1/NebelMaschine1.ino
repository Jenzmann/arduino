#include <DMXSerial.h>


void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT);
digitalWrite(4,LOW);
DMXSerial.init(DMXReceiver);

}

void loop() {
  // put your main code here, to run repeatedly:
if(DMXSerial.read(11)<150){
  digitalWrite(4,HIGH);
}
else{
  digitalWrite(4,LOW);
}
}
