#include <GY6050.h>          
#include <Wire.h>
#include <Servo.h>

Servo myservo; 

int X = 0;
int Y = 0;
GY6050 gyro(0x68);              


void setup() {
  Serial.begin(9600);
  Wire.begin();           
  gyro.initialisation();
  delay(100);
  myservo.attach(9);
}

void loop() {
  X = map(gyro.refresh('A', 'X'), -90, 90, 0, 180);                 
  Y = map(gyro.refresh('A', 'Y'), -90, 90, 0, 180);
  myservo.write(Y);                                               
  Serial.println(X);
  Serial.println(Y);
 delay(1000);

}
