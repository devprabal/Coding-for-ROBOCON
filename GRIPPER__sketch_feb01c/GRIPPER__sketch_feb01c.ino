#include<Servo.h>
Servo gripper;
volatile long encoderPos = 0;
volatile long countRotation = 0;
unsigned long prior_count = 0;
#define encoderA 2
#define encoderB 3

void doEncoderA() {
  // look for a low-to-high on channel A
  if (digitalRead(encoderA) == HIGH) {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoderB) == LOW) {
      encoderPos = encoderPos + 1;         // CW
    }
    else {
      encoderPos = encoderPos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoderB) == HIGH) {
      encoderPos = encoderPos + 1;          // CW
    }
    else {
      encoderPos = encoderPos - 1;          // CCW
    }
  }
}

void doEncoderB() {
  // look for a low-to-high on channel B
  if (digitalRead(encoderB) == HIGH) {
    // check channel A to see which way encoder is turning
    if (digitalRead(encoderA) == HIGH) {
      encoderPos = encoderPos + 1;         // CW
    }
    else {
      encoderPos = encoderPos - 1;         // CCW
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoderA) == LOW) {
      encoderPos = encoderPos + 1;          // CW
    }
    else {
      encoderPos = encoderPos - 1;          // CCW
    }
  }
}
void setup() {
  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderA), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB), doEncoderB, CHANGE);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  gripper.attach(9);
}
void loop() {
  gripper.write(180);
  int deg = (((encoderPos) % 12000) * 0.03);
  unsigned long new_count = (encoderPos);
  if (new_count != prior_count) {
    if (deg > 360 && deg < 1)
    {
      countRotation++;
      if (countRotation == 3)
      {
        if (deg > 360)

        {
          digitalWrite(8, LOW);
          analogWrite(10, HIGH);
        }
        if (deg < 1)
        {
          digitalWrite(8, HIGH);
          analogWrite(10, HIGH);
        }
      }
    }
    if ((deg < 301 && deg > 299) && countRotation == 2)
    {
      gripper.write(120);
      delay(10);
    }
    else
    {
      gripper.write(180);
    }
    Serial.println(deg);
    prior_count = new_count;
    delay(10);
  }
}

