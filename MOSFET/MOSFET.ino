int dpin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(dpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dpin, HIGH);
  delay(2000);
  digitalWrite(dpin, LOW);
  delay(1000);
  
}
