#define encoder0PinA  2
#define encoder0PinB  3

volatile long encoder0Pos=0;
long newposition;
long oldposition = 0;
unsigned long newtime;
unsigned long oldtime = 0;
long vel;

void setup()
{
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder, RISING);  // encoDER ON PIN 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
}

void loop()
{
newposition = encoder0Pos;
newtime = millis();
vel = (newposition-oldposition) * 1000 /(newtime-oldtime);
Serial.print ("speed = ");
Serial.println (vel);
oldposition = newposition;
oldtime = newtime;
delay(250);
}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}
