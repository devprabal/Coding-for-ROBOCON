void setup() {
  // put your setup code here, to run once:
pinMode(8,INPUT);
//pinMode(A1,INPUT);
//pinMode(A2,INPUT);
//pinMode(A3,INPUT);
//pinMode(A4,INPUT);
pinMode(9,INPUT);

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(8));
  Serial.println(digitalRead(9));
analogWrite(3,120);
if(digitalRead(8)==LOW){
  digitalWrite(2,HIGH);
  Serial.println("high");
  delay(1000);
}
if(digitalRead(9)==HIGH){
  digitalWrite(2,LOW);
  Serial.println("low");
  delay(1000);
}
//if(digitalRead(2)==HIGH){
  //Serial.println("high");

//else{
//  Serial.println("low");
//}
}
