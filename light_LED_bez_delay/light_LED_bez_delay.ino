struct{
  int okres_wlaczenia;
  int okres_wylaczenia;
  int czas_ostatniej_zmiany;
  int stan;
} dioda;

int incomingByte = 0; // for incoming serial data

void setup() {
  
  // put your setup code here, to run once:
  dioda.okres_wlaczenia = 500;
  dioda.okres_wylaczenia = 500;
  dioda.stan = LOW;
  dioda.czas_ostatniej_zmiany = millis(); //millis zwraca liczbę milisekund od włączenia arduino
  Serial.begin(9600); //open serial port set up for 9600 baud
  
  pinMode(2,OUTPUT); //dioda
  pinMode(3,OUTPUT); //lcd
  pinMode(4,INPUT); //temp sensor

}

void obsluga_diody(){
  int uplynelo = millis() - dioda.czas_ostatniej_zmiany;
  if ((uplynelo >= dioda.okres_wylaczenia) && dioda.stan == LOW){
    dioda.stan=HIGH;
    dioda.czas_ostatniej_zmiany=millis();
    digitalWrite(2,dioda.stan);
  }
  else if ((uplynelo >= dioda.okres_wlaczenia) && dioda.stan == HIGH){
    dioda.stan=LOW;
    dioda.czas_ostatniej_zmiany=millis();
    digitalWrite(2,dioda.stan);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  obsluga_diody();
  String history;
  String to_tok;
  int flashrate;
  
  if (Serial.available()){
    String intxt = Serial.readString();
//    to_tok = intxt;
//    if (strtok(to_tok," ")=="dioda"){ // NEED TO USE METHOD SUBSTRING
//      flashrate=toInt(strtok(NULL," "));
//      Serial.print("flashrate = \n");
//    }
    
    if (intxt == "info\n"){
      Serial.print("(C) 2020 Elektromobilnosc.\n");
      history+=intxt;
    }
    else if (intxt == "lcd\n"){
      Serial.print("dioda zaraz zablysnie.\n");
      history+=intxt;
    }
    else if (intxt == "menu\n"){
      Serial.print(history);
      //history+=intxt;
    }
//    else if(intxt == "
//    else if (intxt == "temp C\n"){
//      int temp = digitalRead(4);
//      Serial.print("temp = %d\n",temp);
//    }
    else
      Serial.print("O czym to do mnie rozmawiasz?\n");
  }
}
