  char tz1color = 'b';
  char tz2color = 'w';
  char tz3color = 'g';
  char cross='0';
  char flag = '0';
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
    char al='a';
    while(1)
    {
      Serial.println("Press 1 for allign, else 0 ");
      while(Serial.available()<=0);
      al=Serial.read();
        if(al=='1'){
        Serial.println("bot aligned");
        break;
        }
        else{
          Serial.println("Bot not aligned");
        }
    }
    return (int)al;
  }
  void mBotAvailable()
  {
    char mStatus;
    while(1)
    {
      Serial.println("Press 1 if manualBot is Available before TZ1 else 0");
      while(Serial.available()<=0);
      mStatus = Serial.read();
      if (mStatus == '1')
      {
        Serial.println("Manual bot detected.");
        break;
      }
    }
    
  }
  char takeShuttle()
  {
    char st ='0';
    while(1)
    {
      Serial.println("Press 1 for Shuttle available");
      while(Serial.available()<=0);
      st = Serial.read();
      if(st == '1'){
      Serial.println("shuttle availble");
      break;
      }
      else{
        Serial.println("stuttle not found");
      }
    }
    
    return st;
  }
  char detectColor()
  {
      char c;
     // while(1)
      {
        Serial.println("Detect color....\nENter color...\n'b'-black'\nw'-white\n'g'-gold");
        while(Serial.available()<=0);
        c = Serial.read();
        if (c=='w'){
        Serial.println("White detected");
        return 'w';
        }
        else if (c=='b'){
        Serial.println("black detected");
        return 'b';
      }
      else //if (c=='g')
      {
        Serial.println("gold detected");
        return 'g';
      }
     }  
  }
  void stopp()
  {
    Serial.println("Stop");
  }
  char throww()
  {
    char th = '0';
    while(1)
    {
      Serial.println("press 1 for throw success or else 0");
      while(Serial.available()<=0);
      th = Serial.read();
      if(th == '1')
      {
       break;
      }
    }
    return th;
  }
 void tz1() // throws at cross_no 2
  {
    char cross_no = '0'; // to count no. of crosses
    char cross = '0'; // to detect a cross
    
  char prev = '0';
      char curr = '0';
     
    while(1)
    {
      
      bool newc= curr == '1' && prev =='0';
       bool newcomc= curr == '0' && prev =='1';
      Serial.println("Press 0 for no cross, 1 for a cross");
      while(Serial.available()<=0);
      cross = Serial.read();
      prev = curr;
      curr = cross;
      if (newc)
      {
        int(cross_no++);
        Serial.println(cross_no);
        right();
      }
      if (curr == prev || newcomc )
      {
        
        right();
      }
      if (cross_no == '3')
      {
      stopp();
      char feedback = throww();
      break;
      }
    }
  //for going back 
    while(1)
    {
    
      left();
      prev = curr;
      Serial.println("Press 0 for no cross, 1 for a cross");
      while(Serial.available()<=0);
      cross = Serial.read();
      curr = cross;
       if (curr == '1' && prev =='0')
      {
        int(cross_no--);
      }
      if (cross_no == '0')
      {
      stopp();
      break;
      }
    }
    
  }
  
  void tz2()
  {
//  int  cross_no=0;
//  
//    bool prev=false; bool curr=false;
//  
//    while(1){
//    right();
//    prev = curr;
//    curr = cross;
//    if (curr==true && prev == false){
//      cross_no++;
//    }
//    if (cross_no == 2){
//      stopp();
//      int feedback = throww();
//     
//      break;
//    }
//    }
//  //for going back 
//    while(1){
//      curr = false;
//      prev = false;
//     if (curr==true && prev == false){
//      cross_no--;
//    }
//    if (cross_no == 0){
//      stopp();
//      break;
//    }
//    }
    tz1(); 
    flag = '1'; 
  }
  
  void tz3() // throws at cross_no 5
  {
    
    char cross_no = '0'; // to count no. of crosses
    char cross = '0'; // to detect a cross
    
  
    while(1)
    {
      char prev = '0';
      char curr = '0';
      right();
      prev = curr;
      Serial.println("Press 0 for no cross, 1 for a cross");
      while(Serial.available()<=0);
      cross = Serial.read();
      curr = cross;
      if (curr == prev)
      {
        right();
      }
      if (curr != prev)
      {
        int(cross_no++);
        right();
      }
      if (cross_no == '5')
      {
      stopp();
      char feedback = throww();
      break;
      }
    }
  //for going back 
    while(1)
    {
      char prev = '0';
      char curr = '0';
      left();
      prev = curr;
      Serial.println("Press 0 for no cross, 1 for a cross");
      while(Serial.available()<=0);
      cross = Serial.read();
      curr = cross;
      if (curr != prev)
      {
        int(cross_no--);
      }
      if (cross_no == '0')
      {
      stopp();
      break;
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
    char cross = 0;
    
    //back();
    Serial.flush();
    while(1)
    {
      Serial.println("\nPress 0 for not cross, 1 for cross  ");
      while(Serial.available()<=0);
      cross = Serial.read();
      
      if(cross == '0')
       {
        if(flag == '0') 
        back();
        else
        {
          break;
        }
       }
       else
       {
          break;
       }
    }
  stopp();
  //delay(1000);
  
  if(isAligned()=='1')
  {
    char shuttle_status = takeShuttle();
    char shuttle_color = detectColor();
    if (shuttle_status == '1'){
      if(shuttle_color == tz1color)
      {
        tz1();
      }
      else if(shuttle_color == tz2color)
      {
        while(1)
        {
          Serial.println("Move back till a cross is detected. Press 1 for cross else 0");
          while(Serial.available()<=0);
          cross = Serial.read();
          if(cross == 0)
          {
            back();
          }
          else
          {
            break;
          }
        }
      }
      if(shuttle_color == tz2color)
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
