String tz2color = "white";
String tz1color = "black";
String tz3color = "gold";
bool cross=false;
void back()
{
  Serial.print("Back");
}
void left()
{
  Serial.print("left");
}
void right()
{
  Serial.print("right");
}
bool isAligned()
{
  Serial.println("press 1 for aligned and 0 for not aligned");
  bool al = Serial.read();
  if(a1){
    Serial.println("bot aligned");
  }
  else{
    Serial.println("Bot not aligned");
  }
  return a1;
}
bool takeShuttle()
{
  Serial.println("Shuttle 1 for Shuttle available")
  bool st = Serial.read();
  if(st){
    Serial.println("shuttle availble");
    }
    else{
      Serial.println("stuttle not find");
    }
  return st;
}
String detectColor()
{
    Serial.println("Detect color....\nENter color...\n'w'-white\n'b'-black\n'g'-gold");
    char c = Serial.read();
    if (c=='w'){
      Serial.println("White detected");
      return "white";
    }
    
}
void stopp()
{
  Serial.println("Stop");
}
int throww()
{
  
}
void tz1()
{
 int cross_no=0;

  bool prev=false;bool curr=false;

  while(1){
  right();
  prev = curr;
  curr = cross;
  if (curr==true && prev == false){
    cross_no++;
  }
  if (cross_no == 2){
    stopp();
    int feedback = throww();
    break;
  }
  }
//for going back 
  while(1){
    curr = false;
    prev = false;
   if (curr==true && prev == false){
    cross_no--;
  }
  if (cross_no == 0){
    stopp();
    return;
  }
  } 
}

void tz2()
{
int  cross_no=0;

  bool prev=false; bool curr=false;

  while(1){
  right();
  prev = curr;
  curr = cross;
  if (curr==true && prev == false){
    cross_no++;
  }
  if (cross_no == 2){
    stopp();
    int feedback = throww();
    break;
  }
  }
//for going back 
  while(1){
    curr = false;
    prev = false;
   if (curr==true && prev == false){
    cross_no--;
  }
  if (cross_no == 0){
    stopp();
    return;
  }
  } 
}

void tz3()
{
 int cross_no=0;
  bool prev=false; bool curr=false;

  while(1){
  right();
  prev = curr;
  curr = cross;
  if (curr==true && prev == false){
    cross_no++;
  }
  if (cross_no == 5){
    stopp();
    int feedback = throww();
    break;
  }
  }
//for going back 
  while(1){
    curr = false;
    prev = false;
   if (curr==true && prev == false){
    cross_no--;
  }
  if (cross_no == 0){
    stopp();
    return;
  }
  } 
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  bool cross = 0;
  //if(Serial.available()>0)
  {
    cross = Serial.read();
  }
while(!cross)
{
  back();
}

if(isAligned())
{
  bool shuttle_status = takeShuttle();
  String shuttle_color = detectColor();
  if (shuttle_status){
  while(shuttle_color == tz1color)
  {
  tz1();
  }
  if(shuttle_color == tz2color)
  {
    while(!cross)
    {
      back();
    }
  }
  while(shuttle_color == tz1color)
  {
    tz2();
  }
  while(shuttle_color == tz3color)
  {
    tz3();
  }
}
}
}
 
