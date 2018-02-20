/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int irPin = 7;
int prev=0,a;
int count  = 0;
int motorPin1 =3 ;
int motorPin2 = 4;
 
void setup() 
{ 
  pinMode(irPin,INPUT);
   pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
   Serial.begin(9600);
} 
 
void loop() 
{
  
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    delay(1000);
    digitalWrite(motorPin1,1);
    digitalWrite(motorPin2,0);
    delay(1000);
    
} 

