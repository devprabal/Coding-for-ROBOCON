
// direction Pins
#define dirFL 6 //FR=RR in manualBot config // change RR to FR in autoBot
#define dirFR 11 //FL=FR in manualBot config
#define dirRR 5//RR=RL in manualBot config
#define dirRL 8 //RL=FL in manualBot config
// pwm Pins
#define pwmFL 7
#define pwmFR 10
#define pwmRR 4
#define pwmRL 9

#define GREEN 1
#define WHITE 0
#define dw(a,b) digitalWrite(a,b)
#define aw(a,b) analogWrite(a,b)

int speedValue = 150;
int slowspeed = 90;


void diagonal()
{
  aw(pwmFR,speedValue);
  aw(pwmFL,0);
  aw(pwmRL,  0);
  aw(pwmRR,  speedValue);
  Serial.println("diagonal");
  dw(dirFR, 1);
  dw(dirRR, 0);


}
void forward() {
  aw(pwmFR, speedValue);
  aw(pwmFL, speedValue);
  aw(pwmRR, speedValue);
  aw(pwmRL, speedValue);
  Serial.println("forward");

  dw(dirFR, 1);
  dw(dirFL, 0);
  dw(dirRL, 0);
  dw(dirRR, 1);
}
void backward() {
  aw(pwmFR, speedValue);
  aw(pwmFL, speedValue);
  aw(pwmRR, speedValue);
  aw(pwmRL, speedValue);
  Serial.println("backward");
  dw(dirFR, 0);
  dw(dirFL, 0);
  dw(dirRL, 1);
  dw(dirRR, 1);
 }
void left() {
  aw(pwmFR, speedValue);
  aw(pwmFL, speedValue);
  aw(pwmRR, speedValue);
  aw(pwmRL, speedValue);
  Serial.println("left");
  dw(dirFR, 0);
  dw(dirFL, 0);
  dw(dirRL, 0);
  dw(dirRR, 0);
}
void right() {
  aw(pwmFR, speedValue);
  aw(pwmFL, speedValue);
  aw(pwmRR, speedValue);
  aw(pwmRL, speedValue);
  Serial.println("right");
  dw(dirFR, 1);
  dw(dirFL, 1);
  dw(dirRL, 1);
  dw(dirRR, 1);
}
void stopall(){
  aw(pwmFR,0);
  aw(pwmFL,0);
  aw(pwmRR,0);
  aw(pwmRL,0);
  Serial.println("stop");
}
void setup() {
  // put your setup code here, to run once:
pinMode(pwmFR, OUTPUT);
  pinMode(pwmFR, OUTPUT);
  pinMode(pwmFL, OUTPUT);
  pinMode(pwmRL, OUTPUT);
  pinMode(dirFR, OUTPUT);
  pinMode(dirFL, OUTPUT);
  pinMode(dirRR, OUTPUT);
  pinMode(dirRL, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
      // dirRL- 9 dir  
//      aw(pwmFL, speedValue);               
//  di
backward();
}
