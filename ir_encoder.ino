int flag = 1;
int ir = 2;
int count = 0;
int servo = 3;
int stflag = 0;
int sp = 130;

#include <Servo.h>
Servo myservo;
int pos =0;

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
myservo.attach(3);
myservo.write(60);
delay(200);
Serial.begin(9600);
}

void loop() {
  if (count >=36){
      digitalWrite(8,LOW);
      Serial.println("stopping");
      delay(1500);
      myservo.write(160);
    }
  else{
  analogWrite(8,130);
  digitalWrite(12,HIGH);
  }
  // put your main code here, to run repeatedly:
  if (digitalRead(ir) and flag){
    Serial.println(count);
    flag = 0;
    count++;
  }

  if (!digitalRead(ir)){
    flag = 1;
  }

  if (count == 10){
    Serial.println("10 done!");
//    count = 0;
    
  if (count >=37){
      digitalWrite(8,LOW);
      Serial.println("stopping");
      
    }
 }
 
//  if (count >= 43){
//  myservo.write(160); 
//  digitalWrite(12,0);
// analogWrite(12,150);
//  delay(100);}
   
  
    
 
}
