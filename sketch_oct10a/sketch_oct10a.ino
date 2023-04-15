

bool isNew = false;
void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>4){
  char tmp[3];
  char channel = Serial.read();
  switch(channel){
    case '4':
    tmp[0] = Serial.read();
    tmp[1] = Serial.read();
    tmp[2] = Serial.read();
    analogWrite(3,atoi(tmp));
    break;
    case '5':
    tmp[0] = Serial.read();
    tmp[1] = Serial.read();
    tmp[2] = Serial.read();
    analogWrite(5,atoi(tmp));
    break;
    default:
    break;
  }
  Serial.read();
  
  
  
}
}
