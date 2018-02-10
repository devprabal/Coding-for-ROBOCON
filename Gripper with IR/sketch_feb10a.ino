/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int irPin = 7;
int prev=0,a;
int count  = 0;
 
void setup() 
{ 
  pinMode(irPin,INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   myservo.write(41);
   Serial.begin(9600);
} 
 
void loop() 
{
  prev = a;
  a = digitalRead(irPin);
  
 // Serial.println(a);
  if (prev!=a && a==HIGH){
    count++;
  }
  Serial.println(count);
  if (a == HIGH && count==6)
  {
    myservo.write(41);
    delay(5000);
    count = 0;
  }
  else{
    myservo.write(65);
  }
} 

