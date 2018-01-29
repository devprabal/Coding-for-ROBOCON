volatile unsigned long count=0;
unsigned long prior_count=0;

void pulse(){
  count=count+1;
}
void setup() {
 pinMode(3, INPUT);
 attachInterrupt(digitalPinToInterrupt(3),pulse,RISING);
// NVIC_SET_PRIORIT(IRQ_PORTA,0);
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
