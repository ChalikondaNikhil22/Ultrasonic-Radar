#include<Arduino.h>
#include <Servo.h>

Servo myservo;

#define echo 6
#define trigger 7

int distance;
int degree;

void setup() {
Serial.begin(9600);

myservo.attach(2);

pinMode(echo, INPUT);
pinMode(trigger, OUTPUT);

delay(100);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 for(degree=1; degree<180; degree+=1){
 myservo.write(degree);
 delay(80);
 data();
 }

 for(degree=180; degree>1; degree-=1){
 myservo.write(degree);
 delay(80);
 data();
 }
 Serial.print(degree);
}

void data(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  long time = pulseIn(echo, HIGH);
  distance = time / 28.5 / 2;
 }
 Serial.print(distance);
}
