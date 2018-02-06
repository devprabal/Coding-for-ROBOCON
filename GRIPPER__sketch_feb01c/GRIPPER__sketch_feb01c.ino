/////////////////////////XBEE Transmitter and Encoder Part on Gripper/////////////////////////
volatile long encoderPos = 0;
volatile long countRotation = 0;
unsigned long prior_count = 0;
#define encoderA 2
#define encoderB 3
#define pwmPin 10
#define dirPin 8
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
  pinMode(dirPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  gripper.attach(9);
}
void loop() {
  //send command to XBee receiver on servo
  Serial.print('<');  //Starting symbol
  Serial.print(0);//Value to say close the gripper
  Serial.println('>');//Ending symbol
  //gripper.write(180);//write initial close value (it may be 0 or 180)
  int deg = (((encoderPos) % 12000) * 0.03);
  unsigned long new_count = (encoderPos);
  if (new_count != prior_count) {
    if (deg > 359 && deg < 1) //zero position : reference line
    {
      countRotation++;
      if (countRotation == 3) // hold in position of reference line when 3rd rotation completes
      {
        if (deg > 359)

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
    if ((deg < 301 && deg > 299) && countRotation == 2) //angle to throw : just now 60 deg
    {
      //send command to XBee receiver on servo
      Serial.print('<');  //Starting symbol
      Serial.print(1);//Value to say open the gripper
      Serial.println('>');//Ending symbol
      //gripper.write(120);
      delay(10);
    }
    else
    {
      //send command to XBee receiver on servo
      Serial.print('<');  //Starting symbol
      Serial.print(0);//Value to say close the gripper
      Serial.println('>');//Ending symbol
      //gripper.write(180);
    }
    Serial.println(deg);
    prior_count = new_count;
    delay(10);
  }
}
/////////////////////////XBEE Receiver and Servo Part on Gripper/////////////////////////
/*
#include<Servo.h>
Servo gripper;
 
int pos=0;

//Variables
bool started= false;//True: Message is strated
bool ended   = false;//True: Message is finished 
char incomingByte ; //Variable to store the incoming byte
char msg;    //Message - array from 0 to 2 (3 values - PWM - e.g. 240)
byte index;     //Index of array

void setup() {

  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module
  
  gripper.attach(9);
}

void loop() {
  
  while (Serial.available()>0){
    //Read the incoming byte

    incomingByte = Serial.read();
    //Start the message when the '<' symbol is received
    if(incomingByte == '<')
    {
     started = true;
     msg = '\0'; // Throw away any incomplete packet
   }
   //End the message when the '>' symbol is received
   else if(incomingByte == '>')
   {
     ended = true;
     break; // Done reading - exit from while loop!
   }
   //Read the message!
   else
   {
     if(started && (!ended)) // Make sure there is room
     {
       msg = incomingByte; // Add char to array

     }
   }
 }
 
 if(started && ended)
 
  {
   int pos = atoi(msg);
   
   if(msg==1)
   {
    gripper.write(120);
   }
   if(msg==0)
   {
    gripper.write(180);
   }
   //Serial.println(value); //Only for debugging
   msg ='\0';
   started = false;
   ended = false;
 }

}
 
/*
