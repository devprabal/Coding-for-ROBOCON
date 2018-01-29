volatile long encoderPos = 0;
unsigned long prior_count=0;
unsigned int duty=127;   //50%
#define encoderA 3
#define encoderB 2
#define motorSpeed 9
#define motorDirection 8
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
 pinMode(motorSpeed, OUTPUT);
 pinMode(motorDirection, OUTPUT);
 attachInterrupt(digitalPinToInterrupt(encoderA),doEncoderA,CHANGE);
 attachInterrupt(digitalPinToInterrupt(encoderB),doEncoderB,CHANGE);
  Serial.begin(9600);
}
void loop() {
  while(Serial.available()>0){
    duty=Serial.parseInt();
  }
  digitalWrite(motorDirection,HIGH);
  analogWrite(motorSpeed,duty);
  unsigned long new_count=(encoderPos);
  if (new_count != prior_count){
    Serial.println((new_count%12000)*0.03);
    prior_count=new_count;
  }
  Serial.print("Duty: ");
  Serial.println(duty);
  delay(100);
}
