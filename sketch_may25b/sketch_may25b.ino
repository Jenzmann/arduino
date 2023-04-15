void setup() {
  // put your setup code here, to run once:
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);

    digitalWrite(10,LOW);
    digitalWrite(2,LOW);
    digitalWrite(11,HIGH);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
}
