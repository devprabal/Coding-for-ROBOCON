const int potPin = A0; //Pot at Arduino A0 pin 
//Variables:
int pos ; //Value from pot

void setup() {

  //Start the serial communication
  Serial.begin(9600); //Baud rate must be the same as is on xBee module

}

void loop() {
    
    //Read the analog value from pot and store it to "value" variable
    pos = analogRead(A0);
    //Map the analog value to pwm value
    pos = map (pos, 0, 1023, 0, 180);
  //Send the message:
  Serial.print('<');  //Starting symbol
  Serial.print(pos);//Value from 0 to 255
  Serial.println('>');//Ending symbol
}



