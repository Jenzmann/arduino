bool act;
int countr = 0;
int countg = 0;
int countb = 0;
int actLed = 0;

bool butPress = false;
void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(10,INPUT_PULLUP);
pinMode(12,INPUT_PULLUP);
pinMode(2,OUTPUT);
pinMode(6,INPUT_PULLUP);

digitalWrite(8,LOW);
Serial.begin(250000);

}
void loop() {
  // put your main code here, to run repeatedly:
//Serial.print(digitalRead(10));
//Serial.print("    ");
//Serial.println(digitalRead(12));
bool a = digitalRead(10);
bool b = digitalRead(12);

if((!digitalRead(6))&&(!butPress)){
  butPress = true;
  if(actLed == 3){actLed = 0;}
  else{
    Serial.println(actLed);
    actLed ++;}
  }

if(digitalRead(6)&&butPress){
  butPress = false;
}


if(a&&b){
  act = false;}


if(a&&(!b)&&(!act)){
  act = true;
  switch(actLed){
  case 0: countr +=3;break;
  case 1: countg +=3;break;
  case 2: countb +=3;break;
 }
}
if((!a)&&b&&(!act)){
  act = true;
  switch(actLed){
  case 0: countr -=3;break;
  case 1: countg -=3;break;
  case 2: countb -=3;break;
  }
}
Serial.print(countr);
Serial.print("  ");
Serial.print(countg);
Serial.print("  ");
Serial.println(countb);
analogWrite(2,countr);
analogWrite(3,countg);
analogWrite(4,countb);
}
