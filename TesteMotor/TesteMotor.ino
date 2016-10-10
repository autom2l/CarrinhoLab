#include <Motor.h>
#include <Carrinho.h>
#include <Ultrasonic.h>

//Configuracoes do sensor frontal.
#define FrontalTriggerPin 8
#define FrontalEchoPin 9

//Configuracoes do sensor lateral.
#define LateralTriggerPin 11
#define LateralEchoPin 10

//Configuracoes motorA
#define IN1 0
#define IN2 1
#define PWMA 12 //Pino PWM do Motor A
#define VA 130  //Valor analogico PWM

//Configuracoes motorB
#define IN3 2
#define IN4 3
#define PWMB 13 //Pino PWM do Motor B
#define VB 130  //Valor analogico PWM

//Intanciando um objeto do tipos carrinho que recebe dois motores
//Os dois motores devem estar previamente configurados.
                                  //Criando um nova instancia para o motorA.
Carrinho *carrinho = new Carrinho(new Motor(IN1, IN2, PWMA, VA),
                                  //Criando um nova instancia para o motorB.
                                  new Motor(IN3, IN4, PWMB, VB),
                                  //Criando um nova instancia para o sensor frontal.
                                  new Ultrasonic(FrontalTriggerPin, FrontalEchoPin),
                                  //Criando um nova instancia para o sensor lateral.
                                  new Ultrasonic(LateralTriggerPin, LateralTriggerPin));

void setup() {
  //Configuracoes gerais dos dipositivos ligados ao Arduino.
  carrinho->configCarrinho();
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  // if(!carrinho->livreAFrente() && !carrinho->livreAEsquerda()) {
  //   carrinho->parar();
  //   carrinho->direita();
  //   carrinho->parar();
  // }
  // else if(!carrinho->livreAFrente() && carrinho->livreAEsquerda()) {
  //   carrinho->parar();
  //   carrinho->esquerda();
  //   carrinho->parar();
  // }
  // else if(carrinho->livreAFrente() && !carrinho->livreAEsquerda()) {
  //   carrinho->andar();
  // }
  // else if(carrinho->livreAFrente() && carrinho->livreAEsquerda()) {
  //   carrinho->parar();
  //   carrinho->esquerda();
  //   carrinho->andar();
  // }
}
