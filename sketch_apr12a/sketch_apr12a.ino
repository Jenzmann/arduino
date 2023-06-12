
//9 Blue
//10 Red
//11 Green

#include <DMXSerial.h>
int brightness;

void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);


digitalWrite(4,LOW);
}

void loop() {
 delay(1000);
 digitalWrite(4,HIGH);
delay(1000);
 digitalWrite(4,LOW);
}
