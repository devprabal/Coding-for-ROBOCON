int motorPin1=7 ,motorPin2=8  ;
int irPin=3;
int irPin0=2;
int prev=0,a,b;
int flag = 0;
int count =0; 
int counta = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(motorPin1,OUTPUT); 
  pinMode(motorPin2,OUTPUT);
    pinMode(irPin,INPUT);
  pinMode(irPin0,INPUT);
  Serial.begin(9600);
   digitalWrite(motorPin1,1);
  digitalWrite(motorPin2,0);
  delay(500);
 
  while(1){
    //xbee_received = Serial.read();
     prev=b;
    flag =a;
 //if(xbee_recieved == "TZ1"){
  a = digitalRead(irPin);
  b = digitalRead(irPin0);
 //}
// else{
 // b = digitalRead(irPin0);
  //a = LOW;
 //}
 
   if (prev!=b && b==HIGH)
 {
    Serial.println("counted");
    counta++;
    Serial.println(count);
 }
if (b==HIGH && counta==1)
 {
  Serial.println("motorstarted");
  

  
  
    Serial.println(b);
  digitalWrite(motorPin1,0);
  digitalWrite(motorPin2,1);
  delay(500);
  digitalWrite(motorPin1,1);
  digitalWrite(motorPin2,1);
  //delay(1000);
  counta=0;
  
 }
  else{
 digitalWrite(motorPin1,1);
 
  digitalWrite(motorPin2,1);
  
 }
if (flag!=a && a==HIGH)
 {
    Serial.println("counted");
    count++;
    Serial.println(count);
 }
if (a==HIGH && count==1)
 {
  Serial.println("motorstarted");
  

  
  
    Serial.println(a);
  digitalWrite(motorPin1,1);
  digitalWrite(motorPin2,0);
  delay(500);
  break;
  
 }
 else{
 digitalWrite(motorPin1,1);
  digitalWrite(motorPin2,1);  
    
    }
 
  }
}


void loop() {
}
   
