//Down Sensors
#define D1 A0
#define D2 A1
#define D3 A2
#define D4 A3
#define D5 A4
//Side Sensors
#define S1 A5
#define S2 A6
#define S3 A7
#define S4 A8
#define S5 A9
// direction Pins
#define dirPinFR 7
#define dirPinFL 8
#define dirPinRR 4
#define dirPinRL 2
// pwm Pins
#define pwmPinFR 6
#define pwmPinFL 9
#define pwmPinRL 3
#define pwmPinRR 5
void slowdown(int value){
  for (;i>value;i--){
    aw(pi,);
  }
}
void setup() {
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(pwmPinFR, OUTPUT);
  pinMode(pwmPinRR, OUTPUT);
  pinMode(pwmPinFL, OUTPUT);
  pinMode(pwmPinRL, OUTPUT);
  pinMode(dirPinFR, OUTPUT);
  pinMode(dirPinFL, OUTPUT);
  pinMode(dirPinRR, OUTPUT);
  pinMode(dirPinRL, OUTPUT);

  //go diagonal
  while(digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == OFF && digitalRead(S4) == OFF && digitalRead(S5) == OFF) //everything off then move diagnally full speed
        { 
          diagonal();
        }
  //slow down
    slowdown();  //slow speed to a particular value  
  if(digitalRead(D3) == ON || digitalRead(D4) == ON || digitalRead(D5) == ON)
  {
    
  }
        
        
        
        
        
        }
  

void loop() {}
