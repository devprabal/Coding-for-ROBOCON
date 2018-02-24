//Down Sensors
#define D1 44
#define D2 46 //52
#define D3 48 //50
#define D4 50 //48
#define D5 52 //46

#define D6 32
#define D7 34 //52
#define D8 36 //50
#define D9 38 //48
#define D10 40 //46
//DS1 facing problem

//DS2 ==D5
//DS3 == D4
//DS4==D3
//DS5==D2

//Side Sensors
#define S1 22
#define S2 24
#define S3 26
#define S4 28
#define S5 30
#define S6 23
#define S7 25
#define S8 27
#define S9 29
#define S10 31
//ds1== error
//ds2 = s2
//ds3 = s3
//ds4 = s4
//ds5 = s5
// direction Pins
#define dirFR 6 //FR=RR in manualBot config // change RR to FR in autoBot
#define dirFL 4 //FL=FR in manualBot config
#define dirRR 8 //RR=RL in manualBot config
#define dirRL 2 //RL=FL in manualBot config
// pwm Pins
#define pwmFR 10
#define pwmFL 5
#define pwmRR 9
#define pwmRL 3

#define GREEN 1
#define WHITE 0
#define dw(a,b) digitalWrite(a,b)
#define aw(a,b) analogWrite(a,b)

int speedValue = 90;
int slowspeed = 60;
void slowdown(int value) {

}
void diagonal()
{
  aw(pwmFL, 0);
  aw(pwmRR,0);
  aw(pwmFR,  speedValue);
  aw(pwmRL,  speedValue);
  Serial.println("diagonal");
  dw(dirFR, 0);
  dw(dirRL, 0);


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
  dw(dirFL, 1);
  dw(dirRL, 0);
  dw(dirRR, 1);
 }
void left() {
  aw(pwmFR, slowspeed);
  aw(pwmFL, slowspeed);
  aw(pwmRR, slowspeed);
  aw(pwmRL, slowspeed);
  Serial.println("left");
  dw(dirFR, 0);
  dw(dirFL, 0);
  dw(dirRL, 0);
  dw(dirRR, 0);
}
void right() {
  aw(pwmFR, slowspeed);
  aw(pwmFL, slowspeed);
  aw(pwmRR, slowspeed);
  aw(pwmRL, slowspeed);
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
void tz1() {
  //we have reached cross above tz1
  while (!(digitalRead(D1) == GREEN || digitalRead(D2) == GREEN || digitalRead(D3) == GREEN || digitalRead(D4) == GREEN || digitalRead(D5) == GREEN))
    if ((digitalRead(S1) == WHITE && digitalRead(S2) == GREEN && digitalRead(S3) == GREEN && digitalRead(S4) == GREEN && digitalRead(S5) == WHITE) ||
      (digitalRead(S1) == WHITE && digitalRead(S2) == GREEN && digitalRead(S3) == GREEN && digitalRead(S4) == WHITE && digitalRead(S5) == WHITE) ||
      (digitalRead(S1) == WHITE && digitalRead(S2) == WHITE && digitalRead(S3) == GREEN && digitalRead(S4) == GREEN && digitalRead(S5) == WHITE))
    {
      right();
    }
    else if ((digitalRead(S1) == GREEN || digitalRead(S2) == GREEN) && digitalRead(S5) == WHITE)
    {
      forward();
    }

    else if (digitalRead(S1) == WHITE && (digitalRead(S4) == WHITE || digitalRead(S5) == GREEN))
    {
      backward();
    }
  
  
  //REACHED TZ1 THROWING POSITIGREEN
  while (!(digitalRead(S1) == WHITE && digitalRead(S2) == WHITE && digitalRead(S3) == WHITE && digitalRead(S4) == WHITE && digitalRead(S5) == WHITE))
  {
    left();
  }
  
  while (!(digitalRead(D1) == GREEN || digitalRead(D2) == GREEN || digitalRead(D3) == GREEN || digitalRead(D4) == GREEN || digitalRead(D5) == GREEN)) {


    {
      if ((digitalRead(S1) == WHITE && digitalRead(S2) == GREEN && digitalRead(S3) == GREEN && digitalRead(S4) == GREEN && digitalRead(S5) == WHITE) ||
        (digitalRead(S1) == WHITE && digitalRead(S2) == GREEN && digitalRead(S3) == GREEN && digitalRead(S4) == WHITE && digitalRead(S5) == WHITE) ||
        (digitalRead(S1) == WHITE && digitalRead(S2) == WHITE && digitalRead(S3) == GREEN && digitalRead(S4) == GREEN && digitalRead(S5) == WHITE))
      {
        left();
      }
      else if ((digitalRead(S1) == GREEN || digitalRead(S2) == GREEN) && digitalRead(S5) == WHITE)
      {
        forward();
      }

      else if (digitalRead(S1) == WHITE && (digitalRead(S4) == WHITE || digitalRead(S5) == GREEN))
      {
        backward();
      }
    }
  }
}
void tz2()
{
  tz1();
}
void setup() {
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  pinMode(D6, INPUT);
  pinMode(D7, INPUT);
  pinMode(D8, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
  

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  
  pinMode(S6, INPUT);
  pinMode(S7, INPUT);
  pinMode(S8, INPUT);
  pinMode(S9, INPUT);
  pinMode(S10, INPUT);

  pinMode(pwmFR, OUTPUT);
  pinMode(pwmRR, OUTPUT);
  pinMode(pwmFL, OUTPUT);
  pinMode(pwmRL, OUTPUT);
  pinMode(dirFR, OUTPUT);
  pinMode(dirFL, OUTPUT);
  pinMode(dirRR, OUTPUT);
  pinMode(dirRL, OUTPUT);
  Serial.begin(9600);

  while(digitalRead(S1) == WHITE && digitalRead(S2) == WHITE && digitalRead(S3) == WHITE && digitalRead(S4) == WHITE && digitalRead(S5) == WHITE){}
  
  //go diagonal begin
    while (1) //everything off then move diagnally full speed
  {
    diagonal();
    Serial.print(digitalRead(S1));
    Serial.print(digitalRead(S2));
    Serial.print(digitalRead(S3));
    Serial.print(digitalRead(S4));
    Serial.println(digitalRead(S5));
    if((digitalRead(S2) == WHITE ))//&& digitalRead(S3) == WHITE)/*digitalRead(S3) == GREEN  || digitalRead(S5) == GREEN )*/
    {
      Serial.println("should go strainght now");
      break;
    }
  }
  while(1){
    
  Serial.print("------slow down-------------");
  if(digitalRead(D2) == WHITE || digitalRead(D3) == WHITE || digitalRead(D4) == WHITE || digitalRead(D1) == WHITE){
    break;
  }
  
} //Line FOllower to tz1

    while (1)
    //      TODO: check for all 5 down sensors GREEN condition in while loop
    //     */

  { 
    if (digitalRead(D4) == WHITE || digitalRead(D5) == WHITE || digitalRead(D6) == WHITE||  digitalRead(D7) == WHITE)
      
    {
      backward();
      Serial.println("backward");
      Serial.print("      DOwn  ");
  Serial.print(digitalRead(D1));
  Serial.print(digitalRead(D2));
  Serial.print(digitalRead(D3));
  Serial.print(digitalRead(D4));
  Serial.print(digitalRead(D5));
  Serial.print(digitalRead(D6));
  Serial.print(digitalRead(D7));
  Serial.print(digitalRead(D8));
  Serial.print(digitalRead(D9));
  Serial.println(digitalRead(D10));
  if(digitalRead(S2) == WHITE || digitalRead(S3) == WHITE || digitalRead(S4) == WHITE || digitalRead(S5) == WHITE)
      break;
    }
    else if ((digitalRead(D1) == GREEN) && (digitalRead(D8) == WHITE ||digitalRead(D9) == WHITE || digitalRead(D10) == WHITE))
    {
      right();
      Serial.print("      DOwn  ");
  Serial.print(digitalRead(D1));
  Serial.print(digitalRead(D2));
  Serial.print(digitalRead(D3));
  Serial.print(digitalRead(D4));
  Serial.print(digitalRead(D5));
  Serial.print(digitalRead(D6));
  Serial.print(digitalRead(D7));
  Serial.print(digitalRead(D8));
  Serial.print(digitalRead(D9));
  Serial.println(digitalRead(D10));
    
    }

    else if ((digitalRead(D1) == WHITE || digitalRead(D2) == WHITE || digitalRead(D3) == WHITE) && digitalRead(D10) == GREEN)
    {
      left();
      Serial.print("      DOwn  ");
  Serial.print(digitalRead(D1));
  Serial.print(digitalRead(D2));
  Serial.print(digitalRead(D3));
  Serial.print(digitalRead(D4));
  Serial.print(digitalRead(D5));
  Serial.print(digitalRead(D6));
  Serial.print(digitalRead(D7));
  Serial.print(digitalRead(D8));
  Serial.print(digitalRead(D9));
  Serial.println(digitalRead(D10));
      
    }
    else if ((digitalRead(S1) == WHITE && digitalRead(S2) == WHITE && digitalRead(S3) == WHITE && digitalRead(S4) == WHITE && digitalRead(S5) == WHITE)||
             (digitalRead(D1) == GREEN && digitalRead(D2) == GREEN && digitalRead(D3) == GREEN && digitalRead(D4) == GREEN && digitalRead(D5) == GREEN) && 
             (digitalRead(D6) == GREEN && digitalRead(D7) == GREEN && digitalRead(D8) == GREEN && digitalRead(D9) == GREEN && digitalRead(D10) == GREEN))
             {
                //stopall();
              }
    else{
      backward();
      Serial.println("--------------------");
      
    }
  }
  stopall();
  
  
  
}

void loop() {
  Serial.print(digitalRead(S1));
  Serial.print(digitalRead(S2));
  Serial.print(digitalRead(S3));
  Serial.print(digitalRead(S4));
  Serial.println(digitalRead(S5));
  Serial.print("      DOwn  ");
  Serial.print(digitalRead(D1));
  Serial.print(digitalRead(D2));
  Serial.print(digitalRead(D3));
  Serial.print(digitalRead(D4));
  Serial.println(digitalRead(D5));
 

  // now follow backward line until any one of side sensors is GREEN

   //tz1();
  //  \ 
  //  //going towards tz2
  //  //now follow backward line until any one of side sensors is GREEN
  //  while (digitalRead(S1) == WHITE && digitalRead(S2) == WHITE && digitalRead(S3) == WHITE && digitalRead(S4) == WHITE && digitalRead(S5) == WHITE)
  //    /*
  //       TODO: check for all 5 down sensors GREEN condition in while loop
  //     */
  //  {
  //    if ((digitalRead(D1) == WHITE && digitalRead(D2) == GREEN && digitalRead(D3) == GREEN && digitalRead(D4) == GREEN && digitalRead(D5) == WHITE) ||
  //      (digitalRead(D1) == WHITE && digitalRead(D2) == GREEN && digitalRead(D3) == GREEN && digitalRead(D4) == WHITE && digitalRead(D5) == WHITE) ||
  //      (digitalRead(D1) == WHITE && digitalRead(D2) == WHITE && digitalRead(D3) == GREEN && digitalRead(D4) == GREEN && digitalRead(D5) == WHITE))
  //    {
  //      backward();
  //    }
  //    else if ((digitalRead(D1) == GREEN || digitalRead(D2) == GREEN) && digitalRead(D5) == WHITE)
  //    {
  //      left();
  //    }
  //
  //    else if (digitalRead(D1) == WHITE && (digitalRead(D4) == GREEN || digitalRead(D5) == GREEN))
  //    {
  //      right();
  //    }
  //  }

  //tz2();
}





