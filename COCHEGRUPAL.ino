#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);
#include <Servo.h>
Servo servo;
int pinS = 9;

char leer = 0;

void setup() {
 BT.begin(9600);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 servo.attach (pinS);
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

     case '1':
     Atacar();
     break; 

     case '2':
     Atacar2();
     break; 

     case '3':
     Atacar3();
     break; 

     
   }
 }
}

void Atras(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}
   
void Adelante(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void Izquierda(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Derecha(){
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
void Atacar(){
  servo.write(0);
}
  void Atacar2(){
  servo.write(90);
  }
void Atacar3(){
  servo.write(180);  
}
