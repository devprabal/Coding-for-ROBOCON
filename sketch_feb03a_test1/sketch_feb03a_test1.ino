#define O1 1
#define O2 2
#define O3 3
#define O4 4
#define O5 5

#define dirPinFR 7
#define dirPinFL 8
#define dirPinRR 4
#define dirPinRL 2

#define pwmPinFR 6
#define pwmPinFL 9
#define pwmPinRL 3
#define pwmPinRR 5
void setup()
{
  pinMode(O1, INPUT);
  pinMode(O2, INPUT);
  pinMode(O3, INPUT);
  pinMode(O4, INPUT);
  pinMode(O5, INPUT);
  pinMode(dirPinFR, OUTPUT);
  pinMode(dirPinFL, OUTPUT);
  pinMode(dirPinRR, OUTPUT);
  pinMode(dirPinRL, OUTPUT);
  pinMode(pwmPinFR, OUTPUT);
  pinMode(pwmPinFL, OUTPUT);
  pinMode(pwmPinRR, OUTPUT);
  pinMode(pwmPinRL, OUTPUT);

}

int speedValue = 200;
int divide = 2;
void loop()
{
int a = digitalRead(O1);
  int b = digitalRead(O2);
  int c = digitalRead(O3);
  int d = digitalRead(O4);
  int e = digitalRead(O5);

//  digitalWrite(dirPinFR, HIGH);
//  digitalWrite(dirPinFL, HIGH);
//  digitalWrite(dirPinRR, HIGH);
//  digitalWrite(dirPinRL, HIGH);
//
//  analogWrite(pwmPinFR, 0);
//  analogWrite(pwmPinFL, 0);
//  analogWrite(pwmPinRL, 0);
//  analogWrite(pwmPinRR, 0);
//  delay(2000);
  if (digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 1)
  {

    digitalWrite(dirPinFR, HIGH);
    digitalWrite(dirPinFL, HIGH);
    digitalWrite(dirPinRR, HIGH);
    digitalWrite(dirPinRL, HIGH);

    analogWrite(pwmPinFR, speedValue);
    analogWrite(pwmPinFL, speedValue);
    analogWrite(pwmPinRL, speedValue);
    analogWrite(pwmPinRR, speedValue);
    
  }
  else if (digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 0)
  {

    digitalWrite(dirPinFR, HIGH);
    digitalWrite(dirPinFL, HIGH);
    digitalWrite(dirPinRR, HIGH);
    digitalWrite(dirPinRL, HIGH);

    analogWrite(pwmPinFR, speedValue);
    analogWrite(pwmPinFL, speedValue);
    analogWrite(pwmPinRL, speedValue);
    analogWrite(pwmPinRR, speedValue);
  }
  else if (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 0)
  {

    digitalWrite(dirPinFR, LOW);
    digitalWrite(dirPinFL, LOW);
    digitalWrite(dirPinRR, LOW);
    digitalWrite(dirPinRL, LOW);
    
    analogWrite(pwmPinFR, speedValue);
    analogWrite(pwmPinFL, speedValue);
    analogWrite(pwmPinRL, speedValue);
    analogWrite(pwmPinRR, speedValue);
  }
//  else if (digitalRead(O1) == 1 && digitalRead(O5) == 0)
//  {
//    while ((digitalRead(O5) != 0))
//
//
//    {
//      //left
//      digitalWrite(dirPinFR, HIGH);
//      digitalWrite(dirPinFL, LOW);
//      digitalWrite(dirPinRR, HIGH);
//      digitalWrite(dirPinRL, LOW);
//
//      analogWrite(pwmPinFR, speedValue / divide);
//      analogWrite(pwmPinFL, speedValue / divide);
//      analogWrite(pwmPinRL, speedValue / divide);
//      analogWrite(pwmPinRR, speedValue / divide);
//            if(!( (digitalRead(O1) == 0) && ( digitalRead(O2) == 0) && (digitalRead(O3) == 0) && ( digitalRead(O4) == 0) && (digitalRead(O4) == 0)))
//        break;
//    }
//  }
//
//  else if (digitalRead(O1) == 0 && digitalRead(O5) == 1)
//  {
//    while ((digitalRead(O5) != 0))
//    {
//      //right
//      digitalWrite(dirPinFR, LOW);
//      digitalWrite(dirPinFL, HIGH);
//      digitalWrite(dirPinRR, HIGH);
//      digitalWrite(dirPinRL, LOW);
//
//      analogWrite(pwmPinFR, speedValue / divide);
//      analogWrite(pwmPinFL, speedValue / divide);
//      analogWrite(pwmPinRL, speedValue / divide);
//      analogWrite(pwmPinRR, speedValue / divide);
//      if(!( (digitalRead(O1) == 0) && ( digitalRead(O2) == 0) && (digitalRead(O3) == 0) && ( digitalRead(O4) == 0) && (digitalRead(O4) == 0)))
//        break;
//    }
//  }
  else
  {
    digitalWrite(dirPinFR, HIGH);
    digitalWrite(dirPinFL, LOW);
    digitalWrite(dirPinRR, LOW);
    digitalWrite(dirPinRL, HIGH);

    analogWrite(pwmPinFR, 0);
    analogWrite(pwmPinFL, 0);
    analogWrite(pwmPinRL, 0);
    analogWrite(pwmPinRR, 0);
  }
}
