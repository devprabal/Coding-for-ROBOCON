#define trig 12
#define echo 11
long duration, distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration= pulseIn(echo,HIGH);
  distance=duration/58;
  Serial.print(distance);
  Serial.print("\n");
  delay(1000);
}
