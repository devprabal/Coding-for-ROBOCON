#define solA 3
#define solB 4
void setup() {
  // put your setup code here, to run once:
  pinMode(solA, OUTPUT);
  pinMode(solB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(solA, HIGH);
digitalWrite(solB, LOW);
delay(2500);
digitalWrite(solA, LOW);
digitalWrite(solB, HIGH);

}
