//i2c Master Code(UNO)
#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  
  Wire.begin();
}

void loop()
{
  while(Serial.available())
  {
    char c = Serial.read();
    
    if(c == 'H')
    {
      Wire.beginTransmission(5);
      Wire.write('H');
      Wire.endTransmission();
    }
    else if(c == 'L')
    {
      Wire.beginTransmission(5);
      Wire.write('L');
      Wire.endTransmission();
    }
  }
}
