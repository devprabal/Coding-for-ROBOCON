/* SYMBOL DETAILS

's' means Side Sensor Array
'd' means Down Sensor Array


*/

#define O1 1
#define O2 2
#define O3 3
#define O4 4
#define O5 5

#define L1 6
#define L2 7
#define L3 8
#define L4 9
#define L5 10
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
void forwardMovement()
{
    setDirection(1,1,1,1,150);//when button pressed (do once)
    Movement(150);//keep on going till button is pressed (repeatedly)
}
void backwardMovement()
{
    setDirection(0,0,0,0,150);//when button pressed (do once)
    Movement(150);//keep on going till button is pressed (repeatedly)
}
void leftMovement()
{
    setDirection(1,0,1,0,150);//when button pressed (do once)
    Movement(150);//keep on going till button is pressed (repeatedly)
}
void rightMovement()
{
    setDirection(0,1,0,1,150);//when button pressed (do once)
    Movement(150);//keep on going till button is pressed (repeatedly)
}
void diagonalMovement()
{

    digitalWrite(dirPinFR,LOW);
    digitalWrite(dirPinRL,LOW);
    analogWrite(pwmPinFL,0);
    analogWrite(pwmPinRR,0);
    for(int i=0; i<150; i+=2)
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
                //move forward
            }
        }
        if(digitalRead(L5)==1)
        {
            while(middleSensors('s')!=true)
            {
                //move back
            }
        }
    }
    if(orientation=='d')
    {
        if(digitalRead(O1)==1)
        {
            while(middleSensors('d')!=true)
            {
                //move left
            }
        }
        if(digitalRead(O5)==1)
        {
            while(middleSensors('d')!=true)
            {
                //move right
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
        diagonalMovement();
    }
    while(middleSensors('d')!=1)
    {
        diagonalMovement();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // main line following
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(allSensors('d')!=1 && itFollows('d'))
    {
        backwardMovement();
    }
    while(middleSensors('s')!=1)
    {
        backwardMovement();
    }
    allStop();
    //align with manual bot
    //take shuttle

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TZ1
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(int itr_TZ1 = 1; itr_TZ1 <=2; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            rightMovement();
        }
    }
    while(middleSensors('d')!=1)
    {
        rightMovement();
    }
    allStop();
    //throw
    //feedback
    //anything else (CV) ?
    for(int itr_TZ1 = 1; itr_TZ1 <=2; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            leftMovement();
        }
    }
    while(middleSensors('d')!=1)
    {
        leftMovement();
    }
    allStop();
    //align with manual bot
    //take shuttle
    //see color
    //decide whether to go TZ1 or TZ2

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // going towards start of TZ2
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(allSensors('d')!=1 && itFollows('d'))
    {
        backwardMovement();
    }
    while(middleSensors('s')!=1)
    {
        backwardMovement();
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TZ2
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    for(int itr_TZ2 = 1; itr_TZ2 <=2; itr_TZ2++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            rightMovement();
        }
    }
    while(middleSensors('d')!=1)
    {
        rightMovement();
    }
    allStop();
    //throw
    //feedback
    //anything else (CV) ?
    for(int itr_TZ1 = 1; itr_TZ1 <=2; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            leftMovement();
        }
    }
    while(middleSensors('d')!=1)
    {
       leftMovement();
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

    for(int itr_TZ3 = 1; itr_TZ3 <=5; itr_TZ3++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
            rightMovement();
        }
    }
    while(middleSensors('d')!=1)
    {
        rightMovement();
    }
    allStop();
    //throw
    //feedback
    //anything else (CV) ?
    for(int itr_TZ1 = 1; itr_TZ1 <=5; itr_TZ1++)
    {
        while(allSensors('s')!=1 && itFollows('s'))
        {
           leftMovement();
        }
    }
    while(middleSensors('d')!=1)
    {
        leftMovement();
    }
    allStop();
    //align with manual bot
    //take shuttle
    //go again TZ3
}
