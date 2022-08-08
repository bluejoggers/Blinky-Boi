int rpin = 11;
int bpin = 9;
int gpin = 10;

void setup()
{
  pinMode(4,OUTPUT);
  pinMode(rpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  pinMode(gpin,OUTPUT);
    digitalWrite(gpin,LOW);
  digitalWrite(rpin,LOW);
  digitalWrite(bpin,LOW);
}

void loop()
{

  
digitalWrite(bpin,1);
delay(1000);

}
