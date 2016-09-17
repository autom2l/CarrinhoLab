#include <Ultrasonic.h>
#include <Motor.h>
#include <Carrinho.h>

//Configuracoes do sensor.
#define triggerPin 8
#define echoPin    9

//Configuracoes motorA
#define IN1 4
#define IN2 5
#define PWMA 12
#define VA 130

//configuracoes motorB
#define IN3 6
#define IN4 7
#define PWMB 13
#define VB 130 

Ultrasonic ultrasonic(triggerPin, echoPin);
Motor motorA(IN1, IN2, PWMA, VA);
Motor motorB(IN3, IN4, PWMB, VB);
Carrinho carrinho(motorA, motorB);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT);
  pinMode(echoPin, INPUT);
  motorA.config();
  motorB.config();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(olhar()) {
    carrinho.andar();
  }    
  else {
    carrinho.parar();
    carrinho.esquerda();
  }
}

bool olhar() {
  ultrasonic.Timing();
  if(ultrasonic.Ranging(CM) >= 45)
    return true;
  return false;
}
