void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(4));
  if(digitalRead(4) == 0){
    //analogWrite(3,180);//r
//analogWrite(6,20*0.5);//g
//analogWrite(5,147*0.5);//b

analogWrite(5,255);//b
  }
  else{
    digitalWrite(3,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
  }

}
