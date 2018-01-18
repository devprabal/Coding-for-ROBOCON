  char tz2color = 'w';
  char tz1color = 'b';
  char tz3color = 'g';
  bool cross=false;
  void back()
  {
    Serial.println("Back");
  }
  void left()
  {
    Serial.println("left");
  }
  void right()
  {
    Serial.println("right");
  }
  int isAligned()
  {
    int al=0;
    Serial.flush();
    while(Serial.available()>0)
    {
      Serial.println("press 1 for aligned and 0 for not aligned");
      al=Serial.read();
      if(al==1){
      Serial.println("bot aligned");
      break;
      }
      else{
        Serial.println("Bot not aligned");
      }
      delay(1000);
    }
    return al;
  }
  bool takeShuttle()
  {
    Serial.println("Press 1 for Shuttle available");
    bool st = Serial.read();
    if(st){
      Serial.println("shuttle availble");
      }
      else{
        Serial.println("stuttle not find");
      }
    return st;
  }
  char detectColor()
  {
      Serial.println("Detect color....\nENter color...\n'w'-white\n'b'-black\n'g'-gold");
      char c = Serial.read();
      if (c=='w'){
        Serial.println("White detected");
        return 'w';
      }
      if (c=='b'){
        Serial.println("black detected");
        return 'b';
      }
      if (c=='g'){
        Serial.println("gold detected");
        return 'g';
      }
      
  }
  void stopp()
  {
    Serial.println("Stop");
  }
  int throww()
  {
    Serial.println("press 1 for positive feedback or else 0");
    return Serial.read();
  }
  void tz1()
  {
   int cross_no=0;
  
    bool prev=false;bool curr=false;
  
    while(1){
    right();
    prev = curr;
    Serial.println("Press 0 for no cross, 1 for cross");
    cross = Serial.read();
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
      break;
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
    char cross = '0';
    Serial.flush();
    while(!Serial.available())
    {
    back();
    Serial.println("\nPress 0 for not cross, 1 for cross  ");
    strcpy(cross,Serial.read());
    //Serial.println(cross);
    delay(1000);
    }
    
  stopp();
  delay(1000);
  if(isAligned()=='1')
  {
    bool shuttle_status = takeShuttle();
    char shuttle_color = detectColor();
    if (shuttle_status){
    if(shuttle_color == tz1color)
    {
    tz1();
    }
    if(shuttle_color == tz2color)
    {
      while(!cross)
      {
        back();
        cross = Serial.read();
      }
    }
    if(shuttle_color == tz1color)
    {
      tz2();
    }
    if(shuttle_color == tz3color)
    {
      tz3();
    }
  }
  }
  }
