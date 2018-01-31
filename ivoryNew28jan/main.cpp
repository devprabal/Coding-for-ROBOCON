/* SYMBOL DETAILS

's' means Side Sensor Array
'd' means Down Sensor Array
int flag in setDirection() function is to be made 0 when we are starting from rest

*/
// Auto calibrating line sensors LSS05
// down sensors
#define O1 1
#define O2 2
#define O3 3
#define O4 4
#define O5 5
// side sensors
#define L1 6
#define L2 7
#define L3 8
#define L4 9
#define L5 10

// Motor drivers MD13S or MD10C
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////
// utility functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool allSensors(char orientation)
{
    if(orientation=='s')
    {
        if(digitalRead(L1) && digitalRead(L2) && digitalRead(L3) && digitalRead(L4) && digitalRead(L5)==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(orientation=='d')
    {
        if(digitalRead(O1) && digitalRead(O2) && digitalRead(O3) && digitalRead(O4) && digitalRead(O5) == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool middleSensors(char orientation)
{
    if(orientation=='s')
    {
        if(digitalRead(L2) && digitalRead(L3) && digitalRead(L4)==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(orientation=='d')
    {
        if(digitalRead(O2) && digitalRead(O3) && digitalRead(O4)==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void allStop()
{
    int i = 0;

    analogWrite(pwmPinFR, i);
    analogWrite(pwmPinFL, i);
    analogWrite(pwmPinRL, i);
    analogWrite(pwmPinRR, i);

}
void setDirection(bool FR, bool FL, bool RL, bool RR, int speedValue, int flag)
{
    if(flag==0)
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
    else
    {
        analogWrite(pwmPinFR, speedValue);
        analogWrite(pwmPinFL, speedValue);
        analogWrite(pwmPinRL, speedValue);
        analogWrite(pwmPinRR, speedValue);
    }
}
void Movement(int speedValue)
{
    analogWrite(pwmPinFR, speedValue);
    analogWrite(pwmPinFL, speedValue);
    analogWrite(pwmPinRR, speedValue);
    analogWrite(pwmPinRL, speedValue);
}
void forwardMovement(int speedValue, int flag=1)
{
    setDirection(1,1,1,1,speedValue,flag);//when button pressed (do once)
    Movement(speedValue);//keep on going till button is pressed (repeatedly)
}
void backwardMovement(int speedValue, int flag=1)
{
    setDirection(0,0,0,0,speedValue,flag);//when button pressed (do once)
    Movement(speedValue);//keep on going till button is pressed (repeatedly)
}
void leftMovement(int speedValue, int flag=1)
{
    setDirection(1,0,1,0,speedValue,flag);//when button pressed (do once)
    Movement(speedValue);//keep on going till button is pressed (repeatedly)
}
void rightMovement(int speedValue, int flag=1)
{
    setDirection(0,1,0,1,speedValue,flag);//when button pressed (do once)
    Movement(speedValue);//keep on going till button is pressed (repeatedly)
}
void diagonalMovement(int speedValue)
{

    digitalWrite(dirPinFR,LOW);
    digitalWrite(dirPinRL,LOW);
    analogWrite(pwmPinFL,0);
    analogWrite(pwmPinRR,0);
    for(int i=0; i<speedValue; i+=2)
    {
        analogWrite(pwmPinFR, i);
        analogWrite(pwmPinRL, i);
    }
}
bool itFollows(char orientation)
{
    if(orientation=='s')
    {
        if(digitalRead(L1)==1)
        {
            while(middleSensors('s')!=true)
            {
                forwardMovement(50);//enter a slow speedValue here
            }
        }
        if(digitalRead(L5)==1)
        {
            while(middleSensors('s')!=true)
            {
                backwardMovement(50);//enter a slow speedValue here
            }
        }
    }
    if(orientation=='d')
    {
        if(digitalRead(O1)==1)
        {
            while(middleSensors('d')!=true)
            {
                leftMovement(50);//enter a slow speedValue here
            }
        }
        if(digitalRead(O5)==1)
        {
            while(middleSensors('d')!=true)
            {
                rightMovement(50);//enter a slow speedValue here
            }
        }
    }
    return true;
}

void setup()
{

}

void loop()
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // starting into main line
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(allSensors('s')!=1)
    {
        diagonalMovement(150);
    }
    while(middleSensors('d')!=1)
    {
        diagonalMovement(150);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // main line following
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(allSensors('d')!=1 && itFollows('d'))
    {
        backwardMovement(150);
    }
    while(middleSensors('s')!=1)
    {
        backwardMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //align with manual bot
    //take shuttle

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TZ1
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    rightMovement(150,0); // here flag=0 because we are starting from rest now
    for(int itr_TZ1 = 1; itr_TZ1 <=2; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            rightMovement(150);
        }
    }
    while(middleSensors('d')!=1)
    {
        rightMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //throw
    //feedback
    //anything else (CV) ?
    leftMovement(150,0); // here flag=0 because we are starting from rest now
    for(int itr_TZ1 = 1; itr_TZ1 <=2; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            leftMovement(150);
        }
    }
    while(middleSensors('d')!=1)
    {
        leftMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //align with manual bot
    //take shuttle
    //see color
    //decide whether to go TZ1 or TZ2

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // going towards start of TZ2
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    backwardMovement(150,0); // here flag=0 because we are starting from rest now
    while(allSensors('d')!=1 && itFollows('d'))
    {
        backwardMovement(150);
    }
    while(middleSensors('s')!=1)
    {
        backwardMovement(100);//a little slow speedValue than previous instance
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TZ2
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(int itr_TZ2 = 1; itr_TZ2 <=2; itr_TZ2++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            rightMovement(150);
        }
    }
    while(middleSensors('d')!=1)
    {
        rightMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //throw
    //feedback
    //anything else (CV) ?
    leftMovement(150,0); // here flag=0 because we are starting from rest now
    for(int itr_TZ1 = 1; itr_TZ1 <=2; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            leftMovement(150);
        }
    }
    while(middleSensors('d')!=1)
    {
        leftMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //check manual bot availability
    //align with manual bot
    //take shuttle
    //see color
    //decide whether to go TZ2 or TZ3

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TZ3
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    rightMovement(150,0); // here flag=0 because we are starting from rest now
    for(int itr_TZ3 = 1; itr_TZ3 <=5; itr_TZ3++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            rightMovement(150);
        }
    }
    while(middleSensors('d')!=1)
    {
        rightMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //throw
    //feedback
    //anything else (CV) ?

    leftMovement(150,0); // here flag=0 because we are starting from rest now
    for(int itr_TZ1 = 1; itr_TZ1 <=5; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            leftMovement(150);
        }
    }
    while(middleSensors('d')!=1)
    {
        leftMovement(100);//a little slow speedValue than previous instance
    }
    allStop();
    //align with manual bot
    //take shuttle
    //go again TZ3
}
