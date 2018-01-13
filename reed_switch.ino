Now we can load the sketch on our board.

const int pinSwitch = 12; //Pin Reed

const int pinLed = 9; //Pin LED

int StatoSwitch = 0;

void setup()

{

pinMode(pinLed, OUTPUT); //Imposto i PIN

pinMode(pinSwitch, INPUT);

}

void loop()

{

StatoSwitch = digitalRead(pinSwitch); //Leggo il valore del Reed

if (StatoSwitch == HIGH)

{

digitalWrite(pinLed, HIGH);

}

else

{

digitalWrite(pinLed, LOW);

}

}
