#define ColorTrig 12
#define ColorEcho 11
long duration, distance;
void setup() {
  // put your setup code here, to run once:
  pinMode(ColorTrig, OUTPUT);
  pinMode(ColorEcho, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ColorTrig,LOW);
  delayMicroseconds(2);
  digitalWrite(ColorTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(ColorTrig,LOW);
  duration= pulseIn(ColorEcho,HIGH);
  distance=duration/58;
  Serial.print(distance);
  Serial.print("\n");
  delay(1000);
}
