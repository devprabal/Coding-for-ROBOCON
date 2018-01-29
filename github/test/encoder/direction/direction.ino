volatile unsigned long count=0;
unsigned long prior_count=0;
#define encoderA 3
#define encoderB 2
void pulse(){
   if (digitalRead(encoderB) == LOW) count=count+1;         // CW
    else count=count-1;                                    // CCW
}
void setup() {
 pinMode(encoderA, INPUT);
 pinMode(encoderB, INPUT);
 attachInterrupt(digitalPinToInterrupt(encoderA),pulse,RISING);
  Serial.begin(9600);
}
void loop() {
  unsigned long new_count=(count);
  if (new_count != prior_count){
    Serial.println((new_count%3000)*0.12);
    prior_count=new_count;
    delay(10);
  }
}
