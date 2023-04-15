
//2 REL Bottom
//3 REL Top

//5 SIM On Switch
//10,11 SERIAL Sim Module

//6 Signal TempSensorWhite

//A4 SCL
//A5 SDA

#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

DHT dht(8,DHT22);
OneWire wire(6);
DallasTemperature sens(&wire);
SoftwareSerial SIM900(10,11);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  sens.begin();
  
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);

  delay(500);

  SIM900.begin(19200);
 Serial.begin(9600);
  delay(20000);   
  
  // Send the SMS

 SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  Serial.println("Start");
}
void loop() {
  // put your main code here, to run repeatedly:
 if(SIM900.available()>0){
  
  String a = SIM900.readString();
  Serial.println(a);
  SIM900.println("ATH");
  if(a.indexOf("+CLIP: \"+4915730496739\"")!= -1){
    Serial.println("send");
    sendSMS();
  }
  }
  delay(500);
 }


void sendSMS() {
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT+CMGS=\"+4915730496739\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println("testststs."); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  SIM900.println((char)26); 
  delay(100);
  SIM900.println();
  // Give module time to send SMS
  delay(5000); 
}

String split(String s, char parser, int index) {
  String rs="";
  int parserIndex = index;
  int parserCnt=0;
  int rFromIndex=0, rToIndex=-1;
  while (index >= parserCnt) {
    rFromIndex = rToIndex+1;
    rToIndex = s.indexOf(parser,rFromIndex);
    if (index == parserCnt) {
      if (rToIndex == 0 || rToIndex == -1) return "";
      return s.substring(rFromIndex,rToIndex);
    } else parserCnt++;
  }
  return rs;
}
