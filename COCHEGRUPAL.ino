#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);

char leer = 0;

void setup() {
 BT.begin(9600);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
}

void loop() {
  if(BT.available()>0){
    leer=BT.read();
    switch(leer){ 

     case 'F':
     Adelante();
     break;

     case 'B':
     Atras();
     break;

     case 'R':
     Derecha();
     break;

     case 'L':
     Izquierda();
     break;

     case 'S':
     Detener();
     break;
   }
 }
}

void Adelante(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}
   
void Atras(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void Derecha(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Izquierda(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void Detener(){
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}