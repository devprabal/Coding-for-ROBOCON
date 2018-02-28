//Down Sensors
#define D1 33
#define D2 35 //52
#define D3 37 //50
#define D4 39 //48
#define D5 41 //46

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
#define S1 30  //30
#define S2 28 //28
#define S3 26  //26
#define S4 24  //24
#define S5 22  //22
#define S6 31  //31
#define S7 29
#define S8 27
#define S9 25
#define S10 23
//ds1== error
//ds2 = s2
//ds3 = s3
//ds4 = s4
//ds5 = s5

// direction Pins
#define dirFR 6 //FR=RR in manualBot config // change RR to FR in autoBot
#define dirFL 4 //FL=FR in manualBot config
#define dirRR 8 //RR=RL in manualBot config
#define dirRL A1 //RL=FL in manualBot config
// pwm Pins
#define pwmFR 10
#define pwmFL 5
#define pwmRR 9
#define pwmRL A0

#define GREEN 1
#define WHITE 0
#define dw(a,b) digitalWrite(a,b)
#define aw(a,b) analogWrite(a,b)

void setup() {
  // put your setup code here, to run once:
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
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
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
  
  Serial.print(digitalRead(S1));
  Serial.print(digitalRead(S2));
  Serial.print(digitalRead(S3));
  Serial.print(digitalRead(S4));/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Serial.print(digitalRead(S5));
  Serial.print(digitalRead(S6));
  Serial.print(digitalRead(S7));
  Serial.print(digitalRead(S8));
  Serial.print(digitalRead(S9));
  Serial.println(digitalRead(S10));

}
