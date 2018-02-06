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
void setDirection(bool FR, bool FL, bool RL, bool RR, int speedValue)
{
  digitalWrite(dirPinFR, FR);
  digitalWrite(dirPinFL, FL);
  digitalWrite(dirPinRL, RL);
  digitalWrite(dirPinRR, RR);
  for(int i = 0; i < speedValue; i+=2)
  {
    analogWrite(pwmPinFR, i);
    analogWrite(pwmPinFL, i);
    analogWrite(pwmPinRL, i);
    analogWrite(pwmPinRR, i);
  }
  
}
void Movement(int speedValue)
{
    analogWrite(pwmPinFR, speedValue);
    analogWrite(pwmPinFL, speedValue);
    analogWrite(pwmPinRR, speedValue);
    analogWrite(pwmPinRL, speedValue);
}
void ease_out(int speedValue)
{
  for(int i = speedValue; i >= 0; i-=2)
  {
    analogWrite(pwmPinFR, i);
    analogWrite(pwmPinFL, i);
    analogWrite(pwmPinRL, i);
    analogWrite(pwmPinRR, i);
  }
  delay(5000);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(dirPinFR, OUTPUT);
  pinMode(dirPinFL, OUTPUT);
  pinMode(dirPinRR, OUTPUT);
  pinMode(dirPinRL, OUTPUT);
  pinMode(pwmPinFR, OUTPUT);
  pinMode(pwmPinFL, OUTPUT);
  pinMode(pwmPinRR, OUTPUT);
  pinMode(pwmPinRL, OUTPUT);
  
}

void loop() {
  // Forward direction
  setDirection(1,1,1,1,150);//when button pressed (do once)
  while(millis()<5000)
  {
    Movement(150);//keep on going till button is pressed (repeatedly)
  }
  
  ease_out(150);//when button is released (do once)
  // Backward direction
  setDirection(0,0,0,0,150);
  while(millis()<15000)
  {
    Movement(150);//keep on going till button is pressed (repeatedly)
  }
  ease_out(150);
  // Left direction
  setDirection(1,0,1,0,150);
  while(millis()<25000)
  {
    Movement(150);//keep on going till button is pressed (repeatedly)
  }
  ease_out(150);
  // Right direction
  setDirection(0,1,0,1,150);
  while(millis()<35000)
  {
    Movement(150);//keep on going till button is pressed (repeatedly)
  }
  ease_out(150);
  // clockwise turning
  setDirection(0,1,1,0,150);
  while(millis()<45000)
  {
    Movement(150);//keep on going till button is pressed (repeatedly)
  }
  ease_out(150);
  // anticlockwise turning
  setDirection(0,1,1,0,150);
  while(millis()<55000)
  {
    Movement(150);//keep on going till button is pressed (repeatedly)
  }
  ease_out(150);
  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////////DIAGONAL/////////////////////////////////////////////////
  analogWrite(pwmPinFL,0);
  analogWrite(pwmPinRR,0);
  digitalWrite(dirPinFR,LOW);
  digitalWrite(dirPinRL,LOW);
  for(int i=0; i<150; i+=2)
  {
    analogWrite(pwmPinFR, i);
    analogWrite(pwmPinRL, i);
  }
  for(int i=150; i>150; i-=2)
  {
    analogWrite(pwmPinFR, i);
    analogWrite(pwmPinRL, i);
  }
  delay(2000);
}
