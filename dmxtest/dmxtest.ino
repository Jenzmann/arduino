#include <DMXSerial.h>
const int Led1Pin =  3;  // PWM Pin für die erste LED

void setup () {
  DMXSerial.init(DMXReceiver);
  pinMode(Led1Pin, OUTPUT); // Pin von der ersten LED als Ausgang definieren
}

void loop() {
  analogWrite(Led1Pin, DMXSerial.read(1));
}
