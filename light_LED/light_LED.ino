void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(2)==0)
  {
    digitalWrite(3,HIGH);
    delay(50);
    digitalWrite(3,LOW);
    delay(100);
  }
  else {
    digitalWrite(4,HIGH);
    delay(50);
    digitalWrite(4,LOW);
    delay(100);
  }
}
