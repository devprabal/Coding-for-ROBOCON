 const int pin1 = 3;
const int pin2 = 4;
const int pin3 = 5;
const int pin4 = 6;

void setup() {
  // put your setup code here, to run once:
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);


}

void loop() {
// 
 digitalWrite(pin1,0);
 digitalWrite(pin2,1);
delay(1000); 

 digitalWrite(pin3,0);
 digitalWrite(pin4,1);
delay(1000);

 // put your main code here, to run repeatedly:

}
