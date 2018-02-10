// if sensor on white is OFF then set OFF = 1
bool OFF = 1;
bool ON = 0;
// down sensors
#define O1 A0
#define O2 A1
#define O3 A2
#define O4 A3
#define O5 A4

//dir pins
#define dirPinFR 7
#define dirPinFL 8
#define dirPinRR 4
#define dirPinRL 2
// pwm Pins
#define pwmPinFR 6
#define pwmPinFL 9
#define pwmPinRL 3
#define pwmPinRR 5
//volatile int task_no;

void setup()
{
  pinMode(O1, INPUT);
  pinMode(O2, INPUT);
  pinMode(O3, INPUT);
  pinMode(O4, INPUT);
  pinMode(O5, INPUT);

  pinMode(pwmPinFR, OUTPUT);
  pinMode(pwmPinRR, OUTPUT);
  pinMode(pwmPinFL, OUTPUT);
  pinMode(pwmPinRL, OUTPUT);
  pinMode(dirPinFR, OUTPUT);
  pinMode(dirPinFL, OUTPUT);
  pinMode(dirPinRR, OUTPUT);
  pinMode(dirPinRL, OUTPUT);

}
void loop()
{
  int itFollows_speedValue = 102;
  int adjustment_speed = 60;
  if ((digitalRead(O1) == OFF && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == OFF) ||
      (digitalRead(O1) == OFF && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == OFF && digitalRead(O5) == OFF) ||
      (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == OFF))
  {

    analogWrite(pwmPinFR, itFollows_speedValue);
    analogWrite(pwmPinRR, itFollows_speedValue);
    analogWrite(pwmPinFL, itFollows_speedValue);
    analogWrite(pwmPinRL, itFollows_speedValue);
    digitalWrite(dirPinFR, LOW);
    digitalWrite(dirPinFL, LOW);
    digitalWrite(dirPinRR, LOW);
    digitalWrite(dirPinRL, LOW);
    while ((digitalRead(O1) == OFF && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == OFF) ||
           (digitalRead(O1) == OFF && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == OFF && digitalRead(O5) == OFF) ||
           (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == OFF))
    {
      analogWrite(pwmPinFR, itFollows_speedValue);
      analogWrite(pwmPinRR, itFollows_speedValue);
      analogWrite(pwmPinFL, itFollows_speedValue);
      analogWrite(pwmPinRL, itFollows_speedValue);
      digitalWrite(dirPinFR, LOW);
      digitalWrite(dirPinFL, LOW);
      digitalWrite(dirPinRR, LOW);
      digitalWrite(dirPinRL, LOW);
    }
  }

  if ((digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == OFF) ||
      (digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == OFF && digitalRead(O5) == OFF) ||
      (digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == OFF && digitalRead(O4) == OFF && digitalRead(O5) == OFF) ||
      (digitalRead(O1) == ON && digitalRead(O2) == OFF && digitalRead(O3) == OFF && digitalRead(O4) == OFF && digitalRead(O5) == OFF))
  {
    //left or (diagonal left //south-west) //if ON == 1 then go left else if ON == 0 then go right
    //task_no = 2;
    while ((digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == OFF) ||
           (digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == OFF && digitalRead(O5) == OFF) ||
           (digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == OFF && digitalRead(O4) == OFF && digitalRead(O5) == OFF) ||
           (digitalRead(O1) == ON && digitalRead(O2) == OFF && digitalRead(O3) == OFF && digitalRead(O4) == OFF && digitalRead(O5) == OFF))
    {
      if (ON == 1)
      {
        // right because ON == 0
        analogWrite(pwmPinFR, adjustment_speed);
        analogWrite(pwmPinRR, adjustment_speed);
        analogWrite(pwmPinFL, adjustment_speed);
        analogWrite(pwmPinRL, adjustment_speed);
//        digitalWrite(dirPinFR, LOW);
//        digitalWrite(dirPinFL, HIGH);
//        digitalWrite(dirPinRR, LOW);
//        digitalWrite(dirPinRL, HIGH);
        /*THIS SHOULD BE THE DIRECTIONS but I don't know why it doesn't work*/
                          digitalWrite(dirPinFR, LOW);
                          digitalWrite(dirPinFL, HIGH);
                          digitalWrite(dirPinRR, HIGH);
                          digitalWrite(dirPinRL, LOW);
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
      }
      if (ON == 0)
      {
        // for left when ON == 1
        analogWrite(pwmPinFR, adjustment_speed);
        analogWrite(pwmPinRR, adjustment_speed);
        analogWrite(pwmPinFL, adjustment_speed);
        analogWrite(pwmPinRL, adjustment_speed);
//        digitalWrite(dirPinFR, HIGH);
//        digitalWrite(dirPinFL, LOW);
//        digitalWrite(dirPinRR, HIGH);
//        digitalWrite(dirPinRL, LOW);
        /*THIS SHOULD BE THE DIRECTIONS but I don't know why it doesn't work*/
                          digitalWrite(dirPinFR, HIGH);
                          digitalWrite(dirPinFL, LOW);
                          digitalWrite(dirPinRR, LOW);
                          digitalWrite(dirPinRL, HIGH);
        //                  /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
      }

    }
    if ((digitalRead(O1) == OFF && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == ON) ||
        (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == ON) ||
        (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == OFF && digitalRead(O4) == ON && digitalRead(O5) == ON) ||
        (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == OFF && digitalRead(O4) == OFF && digitalRead(O5) == ON))
    {
      //right or (diagonal right // south-east)// if ON == 1 then go right else if ON == 0 then go left
      //task_no = 3;
      while ((digitalRead(O1) == OFF && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == ON) ||
             (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == ON) ||
             (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == OFF && digitalRead(O4) == ON && digitalRead(O5) == ON) ||
             (digitalRead(O1) == OFF && digitalRead(O2) == OFF && digitalRead(O3) == OFF && digitalRead(O4) == OFF && digitalRead(O5) == ON))


      {
        if (ON == 1)
        { //left because ON == 0
          analogWrite(pwmPinFR, adjustment_speed);
          analogWrite(pwmPinRR, adjustment_speed);
          analogWrite(pwmPinFL, adjustment_speed);
          analogWrite(pwmPinRL, adjustment_speed);
//          digitalWrite(dirPinFR, HIGH);
//          digitalWrite(dirPinFL, LOW);
//          digitalWrite(dirPinRR, HIGH);
//          digitalWrite(dirPinRL, LOW);
          /*THIS SHOULD BE THE DIRECTIONS but I don't know why it doesn't work*/
                            digitalWrite(dirPinFR, HIGH);
                            digitalWrite(dirPinFL, LOW);
                            digitalWrite(dirPinRR, LOW);
                            digitalWrite(dirPinRL, HIGH);
          /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        }
        if (ON == 0)
        {
          //for right when ON == 1

          analogWrite(pwmPinFR, adjustment_speed);
          analogWrite(pwmPinRR, adjustment_speed);
          analogWrite(pwmPinFL, adjustment_speed);
          analogWrite(pwmPinRL, adjustment_speed);
//          digitalWrite(dirPinFR, LOW);
//          digitalWrite(dirPinFL, HIGH);
//          digitalWrite(dirPinRR, LOW);
//          digitalWrite(dirPinRL, HIGH);
          /*THIS SHOULD BE THE DIRECTIONS but I don't know why it doesn't work*/
                            digitalWrite(dirPinFR, LOW);
                            digitalWrite(dirPinFL, HIGH);
                            digitalWrite(dirPinRR, HIGH);
                            digitalWrite(dirPinRL, LOW);
          /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        }
      }
    }
//    if ((digitalRead(O1) == ON && digitalRead(O2) == ON && digitalRead(O3) == ON && digitalRead(O4) == ON && digitalRead(O5) == ON))
//    {
//      //return true;
//      //do nothing
//    }
    else
    {
      //task_no=1;
      analogWrite(pwmPinFR, itFollows_speedValue);
      analogWrite(pwmPinRR, itFollows_speedValue);
      analogWrite(pwmPinFL, itFollows_speedValue);
      analogWrite(pwmPinRL, itFollows_speedValue);
      digitalWrite(dirPinFR, LOW);
      digitalWrite(dirPinFL, LOW);
      digitalWrite(dirPinRR, LOW);
      digitalWrite(dirPinRL, LOW);
    }
  }
}
