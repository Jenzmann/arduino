

//9 Blue
//10 Red
//11 Green

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(11,255);
}
