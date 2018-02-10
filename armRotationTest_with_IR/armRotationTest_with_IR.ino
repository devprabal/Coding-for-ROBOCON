#include <Servo.h>
#define IR 2
#define dirPin 3 // motor driver
#define pwmPin 5 // motor driver

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int open_position = 45;    // variable to store the servo position
int close_position = 0;    // variable to store the servo position
int count_rotation = 0;
int speed_arm = 60; // 255 is maximum
void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  digitalWrite(dirPin, HIGH);
  myservo.attach(9);
  myservo.write(close_position);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(close_position);
  digitalWrite(dirPin, HIGH);
  analogWrite(pwmPin, speed_arm);
  if (digitalRead(IR) == 1)
  {
    count_rotation ++;
    if (count_rotation == 6)
    {
      myservo.write(open_position);
      delay(15);
      myservo.write(close_position);
      /* arm stopping mechanism
        if(digitalRead(IR)==1)
        {
        digitalWrite(dirPin, LOW);
        analogWrite(pwmPin, speed_arm/2);
        delay(10);
        digitalWrite(dirPin, HIGH);
        analogWrite(pwmPin, speed_arm/2);
        delay(10);
        }
      */
    }

  }
  else
  {
    myservo.write(close_position);
    delay(15);
  }
}

