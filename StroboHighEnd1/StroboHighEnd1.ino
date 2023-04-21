#include <DMXSerial.h>

int brig;
int del = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);

  DMXSerial.init(DMXReceiver);
}

void loop() {
  // put your main code here, to run repeatedly:
  brig = DMXSerial.read(1);
  del = (255-DMXSerial.read(2))*1.5;
  if(del > 380){
    analogWrite(3,brig);
  analogWrite(5,brig);
  analogWrite(6,brig);
  delay(40);
  }
  if(del > 2){
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(del);
  }
  
}
