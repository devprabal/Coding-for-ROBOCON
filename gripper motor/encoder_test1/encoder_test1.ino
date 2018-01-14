/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputAgreen 6
 #define outputB 7
 int counter = 0; 
 int aState;
 int aLastState;  
 void setup() { 
   pinMode (outputAgreen,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputAgreen);   
 } 
 void loop() { 
   aState = digitalRead(outputAgreen); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
     Serial.print("   Angle: ");
     Serial.print(0.18*counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }

