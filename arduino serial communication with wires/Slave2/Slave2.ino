//i2c Slave Code(Leonardo)
#include <Wire.h>

void setup()
{
  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop()
{
}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    char c = Wire.read();
    
    if(c == 'H')
    {
      digitalWrite(13,HIGH);
    }
    else if(c == 'L')
    {
      digitalWrite(13,LOW);
    }
  }
}
