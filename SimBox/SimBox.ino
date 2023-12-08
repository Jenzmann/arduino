
//2 REL Bottom
//3 REL Top

//5 SIM On Switch
//10,11 SERIAL Sim Module

//6 Signal TempSensorWhite

//A4 SCL
//A5 SDA

//Dallas
// 0 water
// 1 innen
// 2 draussen

#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

OneWire wire(6);
DallasTemperature sens(&wire);
Adafruit_BME280 bme; // I2C
SoftwareSerial SIM900(10,11);


void setup() {
Serial.begin(19200);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
  //SENSOREN
  unsigned statusBme;
  unsigned statusSens;
  
  bme.begin(0x76);
  
  sens.begin();
  

  //SIM MODULE STARTUP
  pinMode(5,OUTPUT);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);

  delay(5000);

  SIM900.begin(19200);
  
  delay(20000);   
  
  // Set SIM to send mode
 SIM900.print("AT+CMGF=1\r"); 
  delay(100);
  //SIM900.print("AT+CNMI=2,2,0,0,0\r");
  //delay(2000);
  
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  Serial.println("Start success");

}
void loop() {
  // put your main code here, to run repeatedly:
 if(SIM900.available()>0){
  String a = SIM900.readString();
  Serial.println(a);
  //SIM900.println("ATH");
  if(a.indexOf("+491637679323")!= -1){
    bme.begin(0x76);
    
    if(a.indexOf("relon1") != -1){
      digitalWrite(3,HIGH);
      sendSMS("Relay 1 ON");
    }
    if(a.indexOf("relon2") != -1){
      digitalWrite(2,HIGH);
      sendSMS("Relay 2 ON");
    }
    if(a.indexOf("reloff1") != -1){
      digitalWrite(3,LOW);
      sendSMS("Relay 1 OFF");
    }
    if(a.indexOf("reloff2") != -1){
      digitalWrite(2,LOW);
      sendSMS("Relay 2 OFF");
    }
    if(a.indexOf("sensoren") != -1){
      sens.requestTemperatures();
      String msg = "draussen: ";
      msg += String(sens.getTempCByIndex(2));
      msg += "\nwasser: ";
      msg += String(sens.getTempCByIndex(0));
      msg += "\ninnen: ";
      msg += String(sens.getTempCByIndex(1));
      msg += "\nfeuchte: ";
      msg += String(bme.readHumidity());
      msg += "\ndruck: ";
      msg += String(bme.readPressure() / 100.0F);
      msg += "\ntemp: ";
      msg += String(bme.readTemperature());
      sendSMS(msg);
    }
  }
  }
  delay(1000);
 }


void sendSMS(String text) {
  Serial.println("Sending SMS");
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  SIM900.println("AT+CMGS=\"+491637679323\""); 
  delay(100);
  
  // REPLACE WITH YOUR OWN SMS MESSAGE CONTENT
  SIM900.println(text); 
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
