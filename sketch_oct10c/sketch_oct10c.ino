#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void receiveEvent(){
  char tmp[3];
  if(Wire.available()){
    char a = Wire.read();
    char col = Wire.read();
    tmp[0] = Wire.read();
    tmp[1] = Wire.read();
    tmp[2] = Wire.read();
    if(a== '1'){
      switch(col){
        case 'r':
        analogWrite(3,atoi(tmp));
        break;
        case 'g':
        analogWrite(5,atoi(tmp));
        break;
        case 'b':
        analogWrite(6,atoi(tmp));
        break;
        default:
        break;
      }
    }
    else if(a== '2'){
     switch(col){
        case 'r':
        analogWrite(9,atoi(tmp));
        break;
        case 'g':
        analogWrite(10,atoi(tmp));
        break;
        case 'b':
        analogWrite(11,atoi(tmp));
        break;
        default:
        break;
      }
    }
  }
}
