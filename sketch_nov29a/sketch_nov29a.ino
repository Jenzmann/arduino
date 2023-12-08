void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
analogWrite(3,0);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0;i<255;i+=20){
    Serial.println(i);
analogWrite(3,i);
delay(500);
  }

}
