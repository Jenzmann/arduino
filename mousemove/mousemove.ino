#include <Mouse.h>;
void setup() {
  // put your setup code here, to run once:
  Mouse.begin();
  pinMode(2,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
if(!digitalRead(2)){
  
for(int i=0;i<4;i++){
  Mouse.move(random(-300,300),random(-300,300),0);
  delay(random(100,1000));
}
}

}
