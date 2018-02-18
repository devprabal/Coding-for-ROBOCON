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
#define dirFR 7
#define dirFL 8
#define dirRR 4
#define dirRL 2
// pwm Pins
#define pwmFR 6
#define pwmFL 9
#define pwmRL 3
#define pwmRR 5


#define ON 1
#define OFF 0
#define dw(a,b) digitalWrite(a,b)
#define aw(a,b) analogWrite(a,b)
void slowdown(int value) {
}
void diagonal()
{
  aw(pwmFR, 1);
  aw(pwmRL, 1);
  aw(pwmFL, 0);
  aw(pwmRR, 0);

  dw(dirFR, 1);
  dw(dirRL, 1);


}
void forward() {
  aw(pwmFR, 1);
  aw(pwmFL, 1);
  aw(pwmRR, 1);
  aw(pwmRL, 1);

  dw(dirFR, 1);
  dw(dirFL, 0);
  dw(dirRL, 0);
  dw(dirRR, 1);
}
void backward() {
  aw(pwmFR, 1);
  aw(pwmFL, 1);
  aw(pwmRR, 1);
  aw(pwmRL, 1);

  dw(dirFR, 0);
  dw(dirFL, 1);
  dw(dirRL, 1);
  dw(dirRR, 0);
}
void left() {
  aw(pwmFR, 1);
  aw(pwmFL, 1);
  aw(pwmRR, 1);
  aw(pwmRL, 1);

  dw(dirFR, 0);
  dw(dirFL, 0);
  dw(dirRL, 0);
  dw(dirRR, 0);
}
void right() {
  aw(pwmFR, 1);
  aw(pwmFL, 1);
  aw(pwmRR, 1);
  aw(pwmRL, 1);

  dw(dirFR, 1);
  dw(dirFL, 1);
  dw(dirRL, 1);
  dw(dirRR, 1);
}
void tz1() {
  //we have reached cross above tz1
  while (!(digitalRead(D1) == ON || digitalRead(D2) == ON || digitalRead(D3) == ON || digitalRead(D4) == ON || digitalRead(D5) == ON))
  {
    if ((digitalRead(S1) == OFF && digitalRead(S2) == ON && digitalRead(S3) == ON && digitalRead(S4) == ON && digitalRead(S5) == OFF) ||
        (digitalRead(S1) == OFF && digitalRead(S2) == ON && digitalRead(S3) == ON && digitalRead(S4) == OFF && digitalRead(S5) == OFF) ||
        (digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == ON && digitalRead(S4) == ON && digitalRead(S5) == OFF))
    {
      right();
    }
    else if ((digitalRead(S1) == ON || digitalRead(S2) == ON) && digitalRead(S5) == OFF)
    {
      forward();
    }

    else if (digitalRead(S1) == OFF && (digitalRead(S4) == OFF || digitalRead(S5) == ON))
    {
      backward();
    }
  }
  //REACHED TZ1 THROWING POSITION
  while (!(digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == OFF && digitalRead(S4) == OFF && digitalRead(S5) == OFF))
  {
    left();
  }
  while (!(digitalRead(D1) == ON || digitalRead(D2) == ON || digitalRead(D3) == ON || digitalRead(D4) == ON || digitalRead(D5) == ON)) {


    {
      if ((digitalRead(S1) == OFF && digitalRead(S2) == ON && digitalRead(S3) == ON && digitalRead(S4) == ON && digitalRead(S5) == OFF) ||
          (digitalRead(S1) == OFF && digitalRead(S2) == ON && digitalRead(S3) == ON && digitalRead(S4) == OFF && digitalRead(S5) == OFF) ||
          (digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == ON && digitalRead(S4) == ON && digitalRead(S5) == OFF))
      {
        left();
      }
      else if ((digitalRead(S1) == ON || digitalRead(S2) == ON) && digitalRead(S5) == OFF)
      {
        forward();
      }

      else if (digitalRead(S1) == OFF && (digitalRead(S4) == OFF || digitalRead(S5) == ON))
      {
        backward();
      }
    }
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

    pinMode(pwmFR, OUTPUT);
    pinMode(pwmRR, OUTPUT);
    pinMode(pwmFL, OUTPUT);
    pinMode(pwmRL, OUTPUT);
    pinMode(dirFR, OUTPUT);
    pinMode(dirFL, OUTPUT);
    pinMode(dirRR, OUTPUT);
    pinMode(dirRL, OUTPUT);

    //go diagonal
    while (digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == OFF && digitalRead(S4) == OFF && digitalRead(S5) == OFF) //everything off then move diagnally full speed
    {
      diagonal();
    }
    while (digitalRead(D3) == OFF && digitalRead(D4) == OFF && digitalRead(D5) == OFF)
    {
      slowdown(120);  //slow speed to a particular value
    }

    //now follow backward line until any one of side sensors is ON
    while (digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == OFF && digitalRead(S4) == OFF && digitalRead(S5) == OFF)
      /*
         TODO: check for all 5 down sensors ON condition in while loop
      */
    {
      if ((digitalRead(D1) == OFF && digitalRead(D2) == ON && digitalRead(D3) == ON && digitalRead(D4) == ON && digitalRead(D5) == OFF) ||
          (digitalRead(D1) == OFF && digitalRead(D2) == ON && digitalRead(D3) == ON && digitalRead(D4) == OFF && digitalRead(D5) == OFF) ||
          (digitalRead(D1) == OFF && digitalRead(D2) == OFF && digitalRead(D3) == ON && digitalRead(D4) == ON && digitalRead(D5) == OFF))
      {
        backward();
      }
      else if ((digitalRead(D1) == ON || digitalRead(D2) == ON) && digitalRead(D5) == OFF)
      {
        left();
      }

      else if (digitalRead(D1) == OFF && (digitalRead(D4) == OFF || digitalRead(D5) == ON))
      {
        right();
      }
    }
   tz1(); 
//Reached outside tz1
  // if failed throw, then
  //align with manualBot
  //See if color == black and take shuttle from manualBot
  //go to TZ1 again
//  if (colour == black)
//  {
//    //above code
//  }



}


void loop() {}
