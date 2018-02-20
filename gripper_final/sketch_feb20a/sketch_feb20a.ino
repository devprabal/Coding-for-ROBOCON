
  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
int irPin = 7;
int prev=0,a;
int count  = 0;
int motorPin1 =3 ,motorPin2 = 4;
 
void setup() 
{ 
  pinMode(irPin,INPUT);
   pinMode(motorPin1,OUTPUT);
    pinMode(motorPin2,OUTPUT);
   Serial.begin(9600);
} 
 
void loop() 
{
  prev = a;
  a = digitalRead(irPin);
  
 // Serial.println(a);
  if (prev!=a && a==HIGH){
    Serial.println("counted");
    count++;
  }
  
  Serial.println(count);
  if (a == HIGH && count>=6)
  {
    Serial.println("motor started");
    digitalWrite(motorPin1,1);
    digitalWrite(motorPin2,0);
    delay(1000);
    count = 0;
  }
  else{
    digitalWrite(motorPin1,0);
    digitalWrite(motorPin2,1);
  }
} 

