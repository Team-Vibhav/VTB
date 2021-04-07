#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <GY6050.h>

#include "Wire.h"
#include "I2Cdev.h"


GY6050 gyro(0x68);
int X = 0;
int Y = 0;


RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";



void setup() {
//Wire.begin();
Serial.begin(115200);
Serial.println("Initialize MPU");
gyro.initialisation();

radio.begin();                  
radio.openWritingPipe(address); 
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();          
}


void loop()
{
X = map(gyro.refresh('A', 'X'), -90, 90, 0, 180);                 
Y = map(gyro.refresh('A', 'Y'), -90, 90, 0, 180);

const char text1[] = "New value for servo 1 is:";
radio.write(&text1, sizeof(text1));                 
radio.write(&X, sizeof(X)); 

const char text2[] = "New value for servo 2 is:";
radio.write(&text2, sizeof(text2));                 
radio.write(&Y, sizeof(Y)); 
}
}
