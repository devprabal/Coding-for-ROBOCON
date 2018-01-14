#define output A0
//#define led 13
int check;
void setup() {
  //pinMode(led, OUTPUT);
  pinMode(output, INPUT);
  Serial.begin(9600);  
}
void loop() {
  check = analogRead(output);
  Serial.println(check);
  Serial.println("\n");//Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
//  if (check == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
//  {
//    Serial.println("BLACK \n");
//    //digitalWrite(led, HIGH);//Illuminates the 13th Port LED
//  }
//  else
//  {
//    Serial.println("WHITE \n");
//    //digitalWrite(led, LOW);
// }
  delay(200);
}
