/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define outputA 2
 #define outputB 3

 int counter = 500; 
 int aState;
 int aLastState;  
 int rotation = 1;

 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){  
    rotation++;   
//      If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     if(rotation==200){
     Serial.print("Rotation: ");
     Serial.println(rotation);  
     Serial.print("Position: ");
     Serial.println(counter);
     Serial.print("   Angle: ");
     Serial.println(0.18*counter);
     Serial.print("\n");
}
   }} 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }
