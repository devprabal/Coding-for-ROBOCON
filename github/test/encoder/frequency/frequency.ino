unsigned long start_time;
unsigned long stop_time;
unsigned long pulseTime;
bool start =true;
void pulse(){
  if(start){
    start_time=micros();
    start=false;
  }  
  else{
    stop_time=micros();
    start=true;
  }
  pulseTime=stop_time-start_time;
}
void setup() {
 pinMode(3, INPUT);
 attachInterrupt(digitalPinToInterrupt(3),pulse,CHANGE);
  Serial.begin(9600);
}
void loop() {
  Serial.println(pulseTime);
  delay(1000);
}
