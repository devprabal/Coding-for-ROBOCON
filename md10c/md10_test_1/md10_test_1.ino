//#define dir 2
#define pwmPin 3

void setup() {
  // put your setup code here, to run once:
//  pinMode(dir,OUTPUT);
  pinMode(pwmPin, OUTPUT);
//  digitalWrite(dir, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
//  for(pwm_value=0;pwm_value<256;pwm_value++)
//  {
//    analogWrite(pwmPin,pwm_value); //increase PWM in every 0.1 sec
//  }
  
    digitalWrite(pwmPin,HIGH); 
    delay(1); 
    digitalWrite(pwmPin,LOW); 
    delay(1);
 
}
