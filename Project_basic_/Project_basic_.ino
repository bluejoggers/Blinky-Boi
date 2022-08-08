int rpin = 11;
int gpin = 10;
int bpin = 9;

void setup()
{
  pinMode(rpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  pinMode(gpin,OUTPUT);
}

void loop()
{
int i = 0;
  
  for(i=0;i<=255;i+=5)
  {
    analogWrite(rpin,i);
    delay(50);
  }
  digitalWrite(rpin,LOW);
  
  for(i=0;i<=255;i+=5)
  {
    analogWrite(bpin,i);
    delay(50);
  }
 digitalWrite(bpin,LOW);
  
  for(i=0;i<=255;i+=5)
  {
    analogWrite(gpin,i);
    delay(50);
  }
digitalWrite(gpin,LOW);
delay(2000);
}
