//Down Sensors
#define D1 44
#define D2 46
#define D3 48
#define D4 50
#define D5 52
//Side Sensors
#define S1 22
#define S2 24
#define S3 26
#define S4 28
#define S5 30
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

#define ON 1
#define OFF 0
#define dw(a,b) digitalWrite(a,b)
#define aw(a,b) analogWrite(a,b)

int speedValue = 90;
void slowdown(int value) {

}
void diagonal()
{
  aw(pwmFR, 0);
  aw(pwmRL,0);
  aw(pwmFL,  speedValue);
  aw(pwmRR,  speedValue);
  Serial.println("diagonal");
  dw(dirFL, 1);
  dw(dirRR, 1);


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
  dw(dirRL, 1);
  dw(dirRR, 0);
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
  Serial.begin(9600);
  //go diagonal
  while (1) //everything off then move diagnally full speed
  {
    diagonal();
    Serial.print(digitalRead(S1));
    Serial.print(digitalRead(S2));
    Serial.print(digitalRead(S3));
    Serial.print(digitalRead(S4));
    Serial.println(digitalRead(S5));
    if((digitalRead(S1) == ON || digitalRead(S2) == ON ))//&& digitalRead(S3) == OFF)/*digitalRead(S3) == ON  || digitalRead(S5) == ON )*/
    {
      Serial.println("should go strainght now");
      break;
    }

  }
}

void loop() {
  Serial.print(digitalRead(S1));
  Serial.print(digitalRead(S2));
  Serial.print(digitalRead(S3));
  Serial.print(digitalRead(S4));
  Serial.println(digitalRead(S5));
  Serial.print("DOwn  ");
  Serial.print(digitalRead(D1));
  Serial.print(digitalRead(D2));
  Serial.print(digitalRead(D3));
  Serial.print(digitalRead(D4));
  Serial.println(digitalRead(D5));


  // while (digitalRead(D3) == OFF && digitalRead(D4) == OFF && digitalRead(D5) == OFF)
  //  {
  //    slowdown(120);  //slow speed to a particular value
  //    Serial.println("slowdon");
  //    Serial.print(digitalRead(S1));
  //    Serial.print(digitalRead(S2));
  //    Serial.print(digitalRead(S3));
  //    Serial.print(digitalRead(S4));
  //    Serial.println(digitalRead(S5));
  //  }

  // now follow backward line until any one of side sensors is ON
  while (digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == OFF && digitalRead(S4) == OFF && digitalRead(S5) == OFF)    
    //      TODO: check for all 5 down sensors ON condition in while loop
    //     */
  {
    if ((digitalRead(D1) == OFF && digitalRead(D2) == ON && digitalRead(D3) == ON && digitalRead(D4) == ON && digitalRead(D5) == OFF) ||
      (digitalRead(D1) == OFF && digitalRead(D2) == ON && digitalRead(D3) == ON && digitalRead(D4) == OFF && digitalRead(D5) == OFF) ||
      (digitalRead(D1) == OFF && digitalRead(D2) == OFF && digitalRead(D3) == ON && digitalRead(D4) == ON && digitalRead(D5) == OFF))
    {
      backward();
      Serial.println("backward");
    }
    else if ((digitalRead(D1) == ON || digitalRead(D2) == ON) && digitalRead(D5) == OFF)
    {
      right();
      Serial.print(digitalRead(S1));
      Serial.print(digitalRead(S2));
      Serial.print(digitalRead(S3));
      Serial.print(digitalRead(S4));
      Serial.println(digitalRead(S5));
      Serial.print("DOwn");
      Serial.print(digitalRead(D1));
      Serial.print(digitalRead(D2));
      Serial.print(digitalRead(D3));
      Serial.print(digitalRead(D4));
      Serial.println(digitalRead(D5));
      Serial.println("right");
    }

    else if (digitalRead(D1) == OFF && (digitalRead(D4) == ON || digitalRead(D5) == ON))
    {
      left();
      Serial.print(digitalRead(S1));
      Serial.print(digitalRead(S2));
      Serial.print(digitalRead(S3));
      Serial.print(digitalRead(S4));
      Serial.println(digitalRead(S5));
      Serial.print("DOwn");
      Serial.print(digitalRead(D1));
      Serial.print(digitalRead(D2));
      Serial.print(digitalRead(D3));
      Serial.print(digitalRead(D4));
      Serial.println(digitalRead(D5));
      Serial.println("left");
    }
  }
  //  tz1();
  //  \ 
  //  //going towards tz2
  //  //now follow backward line until any one of side sensors is ON
  //  while (digitalRead(S1) == OFF && digitalRead(S2) == OFF && digitalRead(S3) == OFF && digitalRead(S4) == OFF && digitalRead(S5) == OFF)
  //    /*
  //       TODO: check for all 5 down sensors ON condition in while loop
  //     */
  //  {
  //    if ((digitalRead(D1) == OFF && digitalRead(D2) == ON && digitalRead(D3) == ON && digitalRead(D4) == ON && digitalRead(D5) == OFF) ||
  //      (digitalRead(D1) == OFF && digitalRead(D2) == ON && digitalRead(D3) == ON && digitalRead(D4) == OFF && digitalRead(D5) == OFF) ||
  //      (digitalRead(D1) == OFF && digitalRead(D2) == OFF && digitalRead(D3) == ON && digitalRead(D4) == ON && digitalRead(D5) == OFF))
  //    {
  //      backward();
  //    }
  //    else if ((digitalRead(D1) == ON || digitalRead(D2) == ON) && digitalRead(D5) == OFF)
  //    {
  //      left();
  //    }
  //
  //    else if (digitalRead(D1) == OFF && (digitalRead(D4) == ON || digitalRead(D5) == ON))
  //    {
  //      right();
  //    }
  //  }

  //tz2();
}





