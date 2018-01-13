const int pwm = 2 ;  //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
const int in_3 = 1 ;
const int in_4 = 3 ;
const int in_5 = 4 ;
const int in_6 = 5 ;
const int in_7 = 6 ;
const int in_8 = 7 ;



//For providing logic to L298 IC to choose the direction of the DC motor 

void setup()
{
pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2,OUTPUT) ;
}

void loop()
{
  
  
  
  
  }
void forward(){
  //MOTOR1
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs





//MOTOR2
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs    


//MOTOR3
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_5,HIGH) ;
digitalWrite(in_6,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
   



//MOTOR4
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_7,HIGH) ;
digitalWrite(in_8,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
    

}


void backward(){
//motor1
//For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;

//motor2
//For Anti Clock-wise motion - IN_3 = LOW , IN_4 = HIGH
digitalWrite(in_3,LOW) ;
digitalWrite(in_4,HIGH) ;

//motor3
//For Anti Clock-wise motion - IN_5 = LOW , IN_6 = HIGH
digitalWrite(in_5,LOW) ;
digitalWrite(in_6,HIGH) ;

//motor4
//For Anti Clock-wise motion - IN_7 = LOW , IN_8 = HIGH
digitalWrite(in_7,LOW) ;
digitalWrite(in_8,HIGH) ;

}
void right(){
//For Anti Clock-wise motion - IN_7 = LOW , IN_8 = HIGH
digitalWrite(in_3,LOW) ;
digitalWrite(in_4,HIGH) ;

//For Anti Clock-wise motion - IN_3 = LOW , IN_4 = HIGH
digitalWrite(in_7,LOW) ;
digitalWrite(in_8,HIGH) ;

//For Clock wise motion , in_1 = High , in_2 = Low
digitalWrite(in_1,HIGH) ;
digitalWrite(in_2,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
     

//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_5,HIGH) ;
digitalWrite(in_6,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
     
}

 
void left(){
//For Anti Clock-wise motion - IN_1 = LOW , IN_8 = HIGH
digitalWrite(in_1,LOW) ;
digitalWrite(in_2,HIGH) ;
//For Anti Clock-wise motion - IN_3 = LOW , IN_4 = HIGH
digitalWrite(in_7,LOW) ;
digitalWrite(in_8,HIGH) ;

//For Clock wise motion , in_1 = High , in_2 = Low
digitalWrite(in_3,HIGH) ;
digitalWrite(in_4,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
 
//For Clock wise motion , in_1 = High , in_2 = Low
digitalWrite(in_5,HIGH) ;
digitalWrite(in_6,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
  





 }




void break(){
  //MOTOR1
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_1,LOW) ;
digitalWrite(in_2,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs





//MOTOR2
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_3,LOW) ;
digitalWrite(in_4,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs    


//MOTOR3
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_5,LOW) ;
digitalWrite(in_6,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
   



//MOTOR4
//For Clock wise motion , in_1 = High , in_2 = Low

digitalWrite(in_7,LOW) ;
digitalWrite(in_8,LOW)  ;
analogWrite(pwm,255)    ;
//Clockwise for 3 secs
    

  
}







{



  
 }
 

 
