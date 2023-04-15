void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,INPUT_PULLUP);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(11)){
    delay(400);
    if(!digitalRead(11)){
      delay(400);
      if(!digitalRead(11)) {
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        delay(3500);
        for(int i=0;i<50;i++){
          if(!digitalRead(11)){
            delay(3500);
            while(digitalRead(11)){
             delay(200);
            }
            break;
          }
          delay(200);
        }
        digitalWrite(13,LOW);
        digitalWrite(12,HIGH);
      }
    }
  }
  delay(1000);
}
