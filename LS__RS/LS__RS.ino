int LS;
int RS;
int BS;
int FS;
int LineSensor;


void setup() {
 
 Serial.begin(9600);

}

void loop() {
  LS = Serial.read();
  RS = Serial.read();
  LS = Serial.read();
  RS = Serial.read();
  LineSensor = Serial.read();

  if( LS ==0 && RS==0 && BS == 1 && FS ==1 && LineSensor ==1){
    Serial.println("FORWARD");
  }

  if( LS == 1 && RS==1 && BS==1 && FS == 1 && LineSensor ==1){
    Serial.println("STOP");
    Serial.println("TakeShuttle");
    Serial.println("DetectColour");
  }
  if( LS== 1 && RS ==1 && BS == 0 && FS == 0 && LineSensor ==1){
    Serial.println("SLOW");
  }
  
}
