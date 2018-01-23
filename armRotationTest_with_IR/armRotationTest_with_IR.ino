#include <Servo.h> 
#define IR 2
#define dir 3
#define pwmPin 5
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(dir, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  digitalWrite(dir, HIGH);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(IR))
  {
    //digitalWrite(pwmPin, LOW);
    for (pos = 0; pos <= 90; pos += 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
  else
  {
    //digitalWrite(pwmPin, HIGH);
    for (pos = 90; pos >= 90; pos -= 1) // goes from 0 degrees to 180 degrees
    { // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
}
