String tz2color = "white";
String tz1color = "black";
String tz3color = "gold";
bool cross=false;
void back()
{
  
}
void left()
{
  
}
void right()
{
}
bool isAligned()
{
}
bool takeShuttle()
{
  
}
String detectColor()
{
}
void stopp()
{
  
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

}

void loop() 
{
  // put your main code here, to run repeatedly:
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
 
