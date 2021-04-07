#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Servo.h>

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

Servo servo1;
Servo servo2;

int val1;
int val2;

void setup() {
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
Serial.begin(115200);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
radio.startListening();           

servo1.attach(5); 
servo2.attach(6);
}


void loop()
{
if (radio.available())              
{
char text1[32] = "";   
radio.read(&text1, sizeof(text1));
radio.read(&val1, sizeof(val1));
servo1.write(val1);

char text2[32] = "";
radio.read(&text2, sizeof(text2));
radio.read(&val2, sizeof(val2));
servo2.write(val2);
}
}
