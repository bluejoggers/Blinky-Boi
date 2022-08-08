int rpin = 3;
int bpin = 5;
int gpin = 6;

void setup()
{
  pinMode(rpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  pinMode(gpin,OUTPUT);
}

void loop()
{
digitalWrite(bpin,HIGH);
delay(1000);

}
