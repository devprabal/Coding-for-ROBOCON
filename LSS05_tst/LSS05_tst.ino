#define O1 A4
#define O2 A3
#define O3 A2
#define O4 A1
#define O5 A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2 ,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(O1));
  Serial.print("  ");
  Serial.print(analogRead(O2));
  Serial.print("  ");
  Serial.print(analogRead(O3));
  Serial.print("  ");
  Serial.print(analogRead(O4));
  Serial.print("  ");
  Serial.println(analogRead(O5));
}
