#define COLOR0 4
#define COLOR1 5
#define COLOR2 6
#define COLOR3 7
#define sensorOut 8
int frequency = 0;
void setup() {
  pinMode(COLOR0, OUTPUT);
  pinMode(COLOR1, OUTPUT);
  pinMode(COLOR2, OUTPUT);
  pinMode(COLOR3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(COLOR0,HIGH);
  digitalWrite(COLOR1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(COLOR2,LOW);
  digitalWrite(COLOR3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(COLOR2,HIGH);
  digitalWrite(COLOR3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(COLOR2,LOW);
  digitalWrite(COLOR3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
   Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(100);
}
