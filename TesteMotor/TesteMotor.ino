#include <Motor.h>
#include <Carrinho.h>
#include <Ultrasonic.h>

//Configuracoes do sensor frontal.
#define FrontalTriggerPin 8
#define FrontalEchoPin 9

//Configuracoes do sensor lateral.
#define LateralTriggerPin 6
#define LateralEchoPin 7

//Configuracoes motorA
#define IN1 1
#define IN2 2
#define PWMA 12
#define VA 130

//configuracoes motorB
#define IN3 3
#define IN4 4
#define PWMB 13
#define VB 130

Ultrasonic ultrasonic(FrontalTriggerPin, FrontalEchoPin);
Motor motorA(IN1, IN2, PWMA, VA);
Motor motorB(IN3, IN4, PWMB, VB);
Carrinho carrinho(motorA, motorB);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(FrontalTriggerPin, OUTPUT);
  pinMode(FrontalEchoPin, INPUT);
  motorA.config();
  motorB.config();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(olhar()) carrinho.andar();

  else {
    carrinho.parar();
    carrinho.esquerda();
  }
  
}

bool olhar() {
  if(ultrasonic.Ranging(CM) >= 45)
    return true;
  return false;
}
