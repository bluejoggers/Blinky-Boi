int rpin=11;
int gpin=10;
int bpin=9;

char input[8];

void setup() 
{
  Serial.begin(9600);
  Serial.println("Online!");
  
  pinMode(rpin,OUTPUT);
  pinMode(gpin,OUTPUT);
  pinMode(bpin,OUTPUT);

  LED_off();
}


/*
 $Input format: RintGintBintMint
 1.Static mode with customizable color options
 the customization can be done using PWM
 2.Colour Cycle mode (no customization)
 3.Strobing effect with customiation
 4.Breathing with just 3 options (R,G and B)under work 
 
 Mode: Off
 Key:0
 Mode: Static 
 Key:1
 Mode: Colour Cycle
 Key:2
 Mode: Strobing
 Key:3
 Mode: Breathing
 Key:4
 */

 void LED_off()
{
  digitalWrite(rpin,LOW);
  digitalWrite(gpin,LOW);
  digitalWrite(bpin,LOW);
}

void LED_static(int r, int g, int b)
{
    analogWrite(rpin, map(r,0,9,0,255));
    analogWrite(gpin, map(g,0,9,0,255));
    analogWrite(bpin, map(b,0,9,0,255));
}


void LED( int r, int g, int b, char mode)
{
  switch(mode)
  {
   case '0':
      LED_off();
      break;

   case '1':
      LED_static(r,g,b);
      break;
    
   case '2':   //starts off with red
      while(Serial.available()!=8)
      {
        int rgb[3]={255,0,0}; //array of integers, holds the values of the duty cycle of the PWM wave
                              
        for(int dcolour=0;dcolour<3;dcolour++)
        {
          int icolour;
          if(dcolour==2)
          {
            icolour=0;
          }
          else
          {
            icolour=dcolour+1;
          }//keeps cycling between the colours to increase and decrease

          for(int i=0;i<255;i++)
          {
              rgb[dcolour]--;
              rgb[icolour]++;

              analogWrite(rpin, rgb[0]);
              analogWrite(gpin, rgb[1]);
              analogWrite(bpin, rgb[2]);
              delay(20);
          }
        } 
      }
      break;

    case '3':
      while(Serial.available()!=8)
      {
        LED_static(r,g,b);
        delay(400);
              
        LED_off();
        delay(250);
      }
      break;
/*
    case '4':
      while(Serial.avaialable()!=8)
      {
        
      }
*/
    defualt:
      LED_off();
      Serial.println("Invalid Command!"); 
      break;
  }
}

void loop() 
{
  while(Serial.available()==8)
  {
    Serial.readBytes(input,8);
    Serial.println("Received!");
  
    LED(input[1]-'0', input[3]-'0', input[5]-'0', input[7]); //int int int char
  }
}
