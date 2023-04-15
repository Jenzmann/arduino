int del = 30;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  
}
void loop() {
  // put your main code here, to run repeatedly:
  
    analogWrite(3,180);
    delay(del);
    analogWrite(3,0);
    delay(del);
    analogWrite(5,255);
    delay(del);
    analogWrite(5,0);
    delay(del);
    analogWrite(6,255);
    delay(del);
    analogWrite(6,0);
    delay(del);
  
  
}
void r(){
   //b
}
void g(){
  analogWrite(5,255); //b
}
void b(){
  analogWrite(6,255); //b
}
