/* SYMBOL DETAILS

's' means Side Sensor Array
'digitalRead(O4)' means Down Sensor Array
int flag in setDirection() function is to be made 0 when we are starting from rest

*/
// Auto calibrating line sensors LSS05
// down sensors
#define O1 A0
#define O2 A1
#define O3 A2
#define O4 A3
#define O5 A4
// side sensors // we can also use digital pins, no problem in that
#define L1 A8
#define L2 A9
#define L3 A10
#define L4 A11
#define L5 A12

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
        int itFollows_speedValue = 102;
        if ((digitalRead(L1) == 0 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 0) || (digitalRead(L1) == 0 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 0 && digitalRead(L5) == 0) || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 0))
        {

            analogWrite(pwmPinFR, itFollows_speedValue);
            analogWrite(pwmPinRR, itFollows_speedValue);
            analogWrite(pwmPinFL, itFollows_speedValue);
            analogWrite(pwmPinRL, itFollows_speedValue);
            digitalWrite(dirPinFR, LOW);
            digitalWrite(dirPinFL, HIGH);
            digitalWrite(dirPinRR, HIGH);
            digitalWrite(dirPinRL, LOW);
            while ((digitalRead(L1) == 0 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 0) || (digitalRead(L1) == 0 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 0 && digitalRead(L5) == 0)
                    || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 0))
            {
                analogWrite(pwmPinFR, itFollows_speedValue);
                analogWrite(pwmPinRR, itFollows_speedValue);
                analogWrite(pwmPinFL, itFollows_speedValue);
                analogWrite(pwmPinRL, itFollows_speedValue);
                digitalWrite(dirPinFR, LOW);
                digitalWrite(dirPinFL, HIGH);
                digitalWrite(dirPinRR, HIGH);
                digitalWrite(dirPinRL, LOW);
            }
        }

        if ((digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 0) || (digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 0 && digitalRead(L5) == 0) || (digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 0 && digitalRead(L4) == 0 && digitalRead(L5) == 0)
             || (digitalRead(L1) == 1 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 0 && digitalRead(L5) == 0))
        {
            //forward or (diagonal forward //north-east)
            //task_no = 2;
            while ((digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 1
                    && digitalRead(L4) == 1 && digitalRead(L5) == 0) || (digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 0 && digitalRead(L5) == 0) ||
                    (digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 0 && digitalRead(L4) == 0 && digitalRead(L5) == 0) || (digitalRead(L1) == 1 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 0 && digitalRead(L5) == 0))
            {
                //      analogWrite(pwmPinFR, 70);
                //      analogWrite(pwmPinRR, 70);
                //      analogWrite(pwmPinFL, 51);
                //      analogWrite(pwmPinRL, 51);
                //      digitalWrite(dirPinFR, HIGH);
                //      digitalWrite(dirPinFL, HIGH);
                //      digitalWrite(dirPinRR, HIGH);
                //      digitalWrite(dirPinRL, HIGH);
                analogWrite(pwmPinFR, 0);
                analogWrite(pwmPinRR, itFollows_speedValue);
                analogWrite(pwmPinFL, itFollows_speedValue);
                analogWrite(pwmPinRL, 0);
                digitalWrite(dirPinFR, HIGH);
                digitalWrite(dirPinFL, LOW);
                digitalWrite(dirPinRR, LOW);
                digitalWrite(dirPinRL, HIGH);
            }
        }
        if ((digitalRead(L1) == 0 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 1) || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 1) || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 1 && digitalRead(L5) == 1)
            || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 1 && digitalRead(L5) == 1)
             || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 0 && digitalRead(L5) == 1))
        {
            //back or (diagonal back // south-east)
            //task_no = 3;
            while ((digitalRead(L1) == 0 && digitalRead(L2) == 1 && digitalRead(L3) == 1
                    && digitalRead(L4) == 1 && digitalRead(L5) == 1) || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 1) ||
                    (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 1 && digitalRead(L5) == 1) || (digitalRead(L1) == 0 && digitalRead(L2) == 0 && digitalRead(L3) == 0 && digitalRead(L4) == 0 && digitalRead(L5) == 1))
            {
                //      analogWrite(pwmPinFR, 51);
                //      analogWrite(pwmPinRR, 51);
                //      analogWrite(pwmPinFL, 70);
                //      analogWrite(pwmPinRL, 70);
                //      digitalWrite(dirPinFR, HIGH);
                //      digitalWrite(dirPinFL, HIGH);
                //      digitalWrite(dirPinRR, HIGH);
                //      digitalWrite(dirPinRL, HIGH);
                analogWrite(pwmPinFR, itFollows_speedValue);
                analogWrite(pwmPinRR, 0);
                analogWrite(pwmPinFL, 0);
                analogWrite(pwmPinRL, itFollows_speedValue);
                digitalWrite(dirPinFR, LOW);
                digitalWrite(dirPinFL, LOW);
                digitalWrite(dirPinRR, LOW);
                digitalWrite(dirPinRL, LOW);
            }
        }
        if ((digitalRead(L1) == 1 && digitalRead(L2) == 1 && digitalRead(L3) == 1 && digitalRead(L4) == 1 && digitalRead(L5) == 1))
        {
            return true;
        }
        else
        {
            //task_no=1;
            analogWrite(pwmPinFR, itFollows_speedValue);
            analogWrite(pwmPinRR, itFollows_speedValue);
            analogWrite(pwmPinFL, itFollows_speedValue);
            analogWrite(pwmPinRL, itFollows_speedValue);
            digitalWrite(dirPinFR, LOW);
            digitalWrite(dirPinFL, HIGH);
            digitalWrite(dirPinRR, HIGH);
            digitalWrite(dirPinRL, LOW);
        }
    }
    }
    if(orientation=='d')
    {
        int itFollows_speedValue = 102;
        if ((digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 0) || (digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 0 && digitalRead(O5) == 0) || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 0))
        {

            analogWrite(pwmPinFR, itFollows_speedValue);
            analogWrite(pwmPinRR, itFollows_speedValue);
            analogWrite(pwmPinFL, itFollows_speedValue);
            analogWrite(pwmPinRL, itFollows_speedValue);
            digitalWrite(dirPinFR, LOW);
            digitalWrite(dirPinFL, LOW);
            digitalWrite(dirPinRR, LOW);
            digitalWrite(dirPinRL, LOW);
            while ((digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 0) || (digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 0 && digitalRead(O5) == 0)
                    || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 0))
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

        if ((digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 0) || (digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 0 && digitalRead(O5) == 0) || (digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 0)
             || (digitalRead(O1) == 1 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 0))
        {
            //left or (diagonal left)
            //task_no = 2;
            while ((digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 1
                    && digitalRead(O4) == 1 && digitalRead(O5) == 0) || (digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 0 && digitalRead(O5) == 0) ||
                    (digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 0) || (digitalRead(O1) == 1 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 0))
            {
                //      analogWrite(pwmPinFR, 70);
                //      analogWrite(pwmPinRR, 70);
                //      analogWrite(pwmPinFL, 51);
                //      analogWrite(pwmPinRL, 51);
                //      digitalWrite(dirPinFR, HIGH);
                //      digitalWrite(dirPinFL, HIGH);
                //      digitalWrite(dirPinRR, HIGH);
                //      digitalWrite(dirPinRL, HIGH);
                analogWrite(pwmPinFR, itFollows_speedValue);
                analogWrite(pwmPinRR, 0);
                analogWrite(pwmPinFL, 0);
                analogWrite(pwmPinRL, itFollows_speedValue);
                digitalWrite(dirPinFR, HIGH);
                digitalWrite(dirPinFL, HIGH);
                digitalWrite(dirPinRR, HIGH);
                digitalWrite(dirPinRL, HIGH);
            }
        }
        if ((digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 1) || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 1) || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 1 && digitalRead(O5) == 1)
            || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 1 && digitalRead(O5) == 1)
             || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 1))
        {
            //right or (diagonal right)
            //task_no = 3;
            while ((digitalRead(O1) == 0 && digitalRead(O2) == 1 && digitalRead(O3) == 1
                    && digitalRead(O4) == 1 && digitalRead(O5) == 1) || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 1) ||
                    (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 1 && digitalRead(O5) == 1) || (digitalRead(O1) == 0 && digitalRead(O2) == 0 && digitalRead(O3) == 0 && digitalRead(O4) == 0 && digitalRead(O5) == 1))
            {
                //      analogWrite(pwmPinFR, 51);
                //      analogWrite(pwmPinRR, 51);
                //      analogWrite(pwmPinFL, 70);
                //      analogWrite(pwmPinRL, 70);
                //      digitalWrite(dirPinFR, HIGH);
                //      digitalWrite(dirPinFL, HIGH);
                //      digitalWrite(dirPinRR, HIGH);
                //      digitalWrite(dirPinRL, HIGH);
                analogWrite(pwmPinFR, 0);
                analogWrite(pwmPinRR, itFollows_speedValue);
                analogWrite(pwmPinFL, itFollows_speedValue);
                analogWrite(pwmPinRL, 0);
                digitalWrite(dirPinFR, HIGH);
                digitalWrite(dirPinFL, HIGH);
                digitalWrite(dirPinRR, HIGH);
                digitalWrite(dirPinRL, HIGH);
            }
        }
        if ((digitalRead(O1) == 1 && digitalRead(O2) == 1 && digitalRead(O3) == 1 && digitalRead(O4) == 1 && digitalRead(O5) == 1))
        {
            return true;
        }
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
    return true;
}

void setup()
{
    pinMode(O1, INPUT);
    pinMode(O2, INPUT);
    pinMode(O3, INPUT);
    pinMode(O4, INPUT);
    pinMode(O5, INPUT);
    pinMode(L1, INPUT);
    pinMode(L2, INPUT);
    pinMode(L3, INPUT);
    pinMode(L4, INPUT);
    pinMode(L5, INPUT);
    pinMode(pwmPinFR,OUTPUT);
    pinMode(pwmPinRR,OUTPUT);
    pinMode(pwmPinFL,OUTPUT);
    pinMode(pwmPinRL,OUTPUT);
    pinMode(dirPinFR,OUTPUT);
    pinMode(dirPinFL,OUTPUT);
    pinMode(dirPinRR,OUTPUT);
    pinMode(dirPinRL,OUTPUT);
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
