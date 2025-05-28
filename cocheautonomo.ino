
#include <Servo.h>
#include <NewPing.h>

#define trigger A1   //emisor analogico para sensor
#define echo A2      //receptor analogico sensor
#define maximun_distance 200

Servo servo;
boolean goesForward = false;
int pinS = 9;
int distance = 100;
 
NewPing sonar(trigger, echo, maximun_distance);

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  servo.attach (pinS);
  servo.write(115);
  delay(2000);
  distance = readPing();
}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;

    if(distance<=20){  
    Detener();
    delay(300);
    Atras();
    delay(400);
    Detener();
    delay(300);
    distanceRight= lookRight();
    delay(300);
    distanceLeft=lookLeft();
    delay(300);
    
      if (distance >= distanceLeft) {
      Derecha();
      Detener();
       } else  {
      Izquierda();
      Detener();
    } 
    } else {
      Adelante();
    }

    distance = readPing();
}

int lookRight() {
  servo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  servo.write(115);
  return distance;
}

int lookLeft() {
  servo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo.write(115);
  return distance;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();

  if (cm==0){
    cm=250;
}
return cm;
}
void Atras(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}
   
void Adelante(){
  if (!goesForward){
    goesForward=true;
  }

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
  delay(500);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Derecha(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(500);
   digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Detener(){
  goesForward = false;

  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}