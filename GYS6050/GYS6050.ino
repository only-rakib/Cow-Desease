#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
SoftwareSerial mySerial(11, 10); // RX, TX

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(57000);
  mySerial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    
    mySerial.print("temp ");mySerial.print(mpu6050.getTemp());
    mySerial.print(" humid na");
    mySerial.print(" x ");mySerial.print(mpu6050.getAccX());
    mySerial.print(" y ");mySerial.print(mpu6050.getAccY());
    mySerial.print(" z ");mySerial.print(mpu6050.getAccZ());
    mySerial.println(" end");
  
    /*Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("\taccAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("\tangleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("\tangleZ : ");Serial.println(mpu6050.getAngleZ());*/
    timer = millis();
    
  }

}
