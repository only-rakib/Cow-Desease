#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10); // RX, TX

void setup() {
  mySerial.begin(9600);
  pinMode(9,OUTPUT);
  
}

void loop() { // run over and over
  digitalWrite(9,HIGH);
  mySerial.println("test data");
  delay(1000);
}
