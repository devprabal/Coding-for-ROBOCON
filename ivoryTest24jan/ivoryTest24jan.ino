char tz1color = 'b';
char tz2color = 'w';
char tz3color = 'g';
char cross = '0';
char flag = '0';
#define O1 A4
#define O2 A3
#define O3 A2
#define O4 A1
#define O5 A0

#define L1 A4
#define L2 A3
#define L3 A2
#define L4 A1
#define L5 A0


#define pwmFR 3
#define dirFR 4

#define pwmFL 6
#define dirFL 8

#define pwmRR 5
#define dirRR 7

#define pwmRL 9
#define dirRL 10

// Command struct for motor controllers
typedef struct {
  int pulse;
  bool direction;
  bool brake;
} MotorValues;

// Defines structs for each motor
MotorValues motorFR;
MotorValues motorFL;
MotorValues motorRR;
MotorValues motorRL;


// ****************************************************
// Sets output analog values based on command struct
// RETURNS: none
// ****************************************************
void commandMotors() {
  analogWrite(pwmFR, motorFR.pulse);
  analogWrite(pwmRR, motorRR.pulse);
  analogWrite(pwmFL, motorFL.pulse);
  analogWrite(pwmRL, motorRL.pulse);
}

// ****************************************************
// Stops the robot by setting all outputs to 0
// RETURNS: none
// ****************************************************
void allStop() {
  analogWrite(pwmFR, 0);
  analogWrite(pwmRR, 0);
  analogWrite(pwmFL, 0);
  analogWrite(pwmRL, 0);
}

// ****************************************************
// Forward Movement Demonstration
// RETURNS: none
// ****************************************************
void forwardMovement() {

  // Set direction bits
  digitalWrite(dirFR, HIGH); digitalWrite(dirFL, HIGH); digitalWrite(dirRR, HIGH); digitalWrite(dirRL, HIGH);

  // Ramp up and command motor controllers
  for (int i = 0; i < 255; i++)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }
  for (int i = 255; i >= 0 ; i--)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }

  allStop();
}

// ****************************************************
// Backward Movement Demonstration
// RETURNS: none
// ****************************************************
void backwardMovement() {

  // Set direction bits
  digitalWrite(dirFR, LOW); digitalWrite(dirFL, LOW); digitalWrite(dirRR, LOW); digitalWrite(dirRL, LOW);

  // Ramp up and command motor controllers
  for (int i = 0; i < 255; i++)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }
  for (int i = 255; i >= 0 ; i--)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }

  allStop();
}


// ****************************************************
// Sidestep Left Movement Demonstration
// RETURNS: none
// ****************************************************
void leftMovement() {

  // Set direction bits
  digitalWrite(dirFR, HIGH); digitalWrite(dirFL, LOW); digitalWrite(dirRR, LOW); digitalWrite(dirRL, HIGH);

  // Ramp up and command motor controllers
  for (int i = 0; i < 255; i++)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }
  for (int i = 255; i >= 0 ; i--)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }

  allStop();
}


// ****************************************************
// Sidestep Right Movement Demonstration
// RETURNS: none
// ****************************************************
void rightMovement() {

  // Set direction bits
  digitalWrite(dirFR, LOW); digitalWrite(dirFL, HIGH); digitalWrite(dirRR, HIGH); digitalWrite(dirRL, LOW);

  // Ramp up and command motor controllers
  for (int i = 0; i < 255; i++)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }
  for (int i = 255; i >= 0 ; i--)
  {
    motorFR.pulse = i;
    motorFL.pulse = i;
    motorRR.pulse = i;
    motorRL.pulse = i;
    commandMotors();
    delay(25);
  }

  allStop();
}

char readSideCross()
{
  if (digitalRead(L1) == 1 and digitalRead(L5) == 1)
  {
    return '1';
  }
  else
  {
    return '0';
  }
}
char readCross()
{
  if (digitalRead(O1) == 1 and digitalRead(O5) == 1)
  {
    return '1';
  }
  else
  {
    return '0';
  }
}
void back()
{
  backwardMovement();
}
void left()
{
  leftMovement();
}
void right()
{
  rightMovement();
}
int isAligned()
{
  char al = '1';
  //  while (1)
  //  {
  //    Serial.println("Press 1 for allign, else 0 ");
  //    while (Serial.available() <= 0);
  //    al = Serial.read();
  //    if (al == '1') {
  //      Serial.println("bot aligned");
  //      break;
  //    }
  //    else {
  //      Serial.println("Bot not aligned");
  //    }
  //  }
  return (int)al;
}
void mBotAvailable()
{
  char mStatus;
  while (1)
  {
    Serial.println("Press 1 if manualBot is Available before TZ1 else 0");
    while (Serial.available() <= 0);
    mStatus = Serial.read();
    if (mStatus == '1')
    {
      Serial.println("Manual bot detected.");
      break;
    }
  }

}
char takeShuttle()
{
  char st = '1';
  //  while (1)
  //  {
  //    Serial.println("Press 1 for Shuttle available");
  //    while (Serial.available() <= 0);
  //    st = Serial.read();
  //    if (st == '1') {
  //      Serial.println("shuttle availble");
  //      break;
  //    }
  //    else {
  //      Serial.println("stuttle not found");
  //    }
  //  }

  return st;
}
char detectColor()
{
  char c;
  // while(1)
  {
    Serial.println("Detect color....\nENter color...\n'b'-black'\nw'-white\n'g'-gold");
    while (Serial.available() <= 0);
    c = Serial.read();
    if (c == 'w') {
      Serial.println("White detected");
      return 'w';
    }
    else if (c == 'b') {
      Serial.println("black detected");
      return 'b';
    }
    else //if (c=='g')
    {
      Serial.println("gold detected");
      return 'g';
    }
  }
}
void stopp()
{
  Serial.println("Stop");
}
char throww()
{
  char th = '1';
  //  while (1)
  //  {
  //    Serial.println("press 1 for throw success or else 0");
  //    while (Serial.available() <= 0);
  //    th = Serial.read();
  //    if (th == '1')
  //    {
  //      break;
  //    }
  //  }
  return th;
}
void tz1() // throws at cross_no 3
{
  char cross_no = '0'; // to count no. of crosses
  char cross = '0'; // to detect a cross

  char prev = '0';
  char curr = '0';

  while (1)
  {

    bool newc = curr == '1' && prev == '0';
    bool newcomc = curr == '0' && prev == '1';

    cross = readSideCross();
    prev = curr;
    curr = cross;
    if (newc)
    {
      int(cross_no++);

      right();
    }
    if (curr == prev || newcomc )
    {

      right();
    }
    if (cross_no == '3')
    {
      stopp();
      char feedback = throww();
      break;
    }
  }
  //for going back
  while (1)
  {

    left();
    prev = curr;

    cross = readSideCross();
    curr = cross;
    if (curr == '1' && prev == '0')
    {
      int(cross_no--);
    }
    if (cross_no == '0')
    {
      stopp();
      break;
    }
  }

}

void tz2()
{
  //  int  cross_no=0;
  //
  //    bool prev=false; bool curr=false;
  //
  //    while(1){
  //    right();
  //    prev = curr;
  //    curr = cross;
  //    if (curr==true && prev == false){
  //      cross_no++;
  //    }
  //    if (cross_no == 2){
  //      stopp();
  //      int feedback = throww();
  //
  //      break;
  //    }
  //    }
  //  //for going back
  //    while(1){
  //      curr = false;
  //      prev = false;
  //     if (curr==true && prev == false){
  //      cross_no--;
  //    }
  //    if (cross_no == 0){
  //      stopp();
  //      break;
  //    }
  //    }
  tz1();
  flag = '1';
}

void tz3() // throws at cross_no 5
{

  char cross_no = '0'; // to count no. of crosses
  char cross = '0'; // to detect a cross


  while (1)
  {
    char prev = '0';
    char curr = '0';
    right();
    prev = curr;

    cross = readSideCross();
    curr = cross;
    if (curr == prev)
    {
      right();
    }
    if (curr != prev)
    {
      int(cross_no++);
      right();
    }
    if (cross_no == '5')
    {
      stopp();
      char feedback = throww();
      break;
    }
  }
  //for going back
  while (1)
  {
    char prev = '0';
    char curr = '0';
    left();
    prev = curr;

    cross = readSideCross();
    curr = cross;
    if (curr != prev)
    {
      int(cross_no--);
    }
    if (cross_no == '0')
    {
      stopp();
      break;
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(O1, INPUT);
  pinMode(O2, INPUT);
  pinMode(O3, INPUT);
  pinMode(O4, INPUT);
  pinMode(O5, INPUT);
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(L3, INPUT);
  pinMode(L4, INPUT);
  pinMode(L5 , INPUT);
  //wheels output
  pinMode(pwmFR, OUTPUT);
  pinMode(dirFR, OUTPUT);

  pinMode(pwmFL, OUTPUT);
  pinMode(dirFL, OUTPUT);

  pinMode(pwmRR, OUTPUT);
  pinMode(dirRR, OUTPUT);

  pinMode(pwmRL, OUTPUT);
  pinMode(dirRL, OUTPUT);

}
void linefollow()
{
  if (digitalRead(O2) == 1 && digitalRead(O4) == 1)
  {
    //go straight
  }
  if (digitalRead(O2) == 0)
  {
    //turn right
  }
  if (digitalRead(O4) == 0)
  {
    //turn left
  }
  if (digitalRead(O1) == 1 && digitalRead(O5) == 1)
  {
    //stop
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  char cross = 0;

  //back();
  //  Serial.flush();
  while (1)
  {
    //    Serial.println("\nPress 0 for not cross, 1 for cross  ");
    //    while (Serial.available() <= 0);
    cross = readCross();

    if (cross == '0')
    {
      if (flag == '0')
        back();
      else
      {
        break;
      }
    }
    else
    {
      break;
    }
  }
  stopp();
  //delay(1000);

  if (isAligned() == '1')
  {
    char shuttle_status = takeShuttle();
    //char shuttle_color = detectColor();
    if (shuttle_status == '1') {
      tz1();

      while (1)
      {

        cross = readCross();
        if (cross == 0)
        {
          back();
        }
        else
        {
          break;
        }
      }


      tz2();


      tz3();

    }
  }
}
