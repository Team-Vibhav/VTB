
#define motor1a 9
#define motor1b 10
#define motor2a 11
#define motor2b 12

void setup()
{
  pinMode(motor1a,OUTPUT);
  pinMode(motor1b,OUTPUT);
  pinMode(motor2a,OUTPUT);
  pinMode(motor2b,OUTPUT);
  Serial.begin(9600);
}

void juststop()
{
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, LOW);
}

void gofront()
{
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
}
void goleft()
{
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, HIGH);
}
void goright()
{
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, HIGH);
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
}

void loop()
{
  char input;
  if(Serial.available()>0)
  {
    input = Serial.read();
    Serial.println(input);
  }
  if(input=='F')
  {
    while(input=='F')
    {
     gofront();
     input = Serial.read();
     Serial.println(input);
    }
  }
  if(input=='B')
  {
    while(input=='B')
    {
     juststop();
     input = Serial.read();
     Serial.println(input);
    }
  }
  if(input=='L')
  {
    while(input=='L')
    {
     goleft();
     input = Serial.read();
     Serial.println(input);
    }
    
  }
  
  if(input=='R')
  {
    while(input=='R')
    {
     goright();
     input = Serial.read();
     Serial.println(input);
    }
    
  }
}
