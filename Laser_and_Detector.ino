/*

Code for KY-008 Laser and Laser Detector
by eLab Peers (C) 2014.

Visit us at:
http://www.elabpeers.com

All rights reserved.

Wiring:
1.  VCC to 5V on Arduino board
2.  GND to GND on Arduino board
3.  S on KY-008 Laser to Pin 6 on Arduino board
4.  OUT on Laser Dector to Pin 7 on Arduino board

*/

int Laser = 6;
int Detector = 7;

void setup()
{ 
  Serial.begin (9600);
  pinMode(Laser, OUTPUT);
  pinMode(Detector, INPUT);
}

void loop()
{
  digitalWrite(Laser, HIGH);
  boolean val = digitalRead(Detector);
  Serial.println(val);
}  
