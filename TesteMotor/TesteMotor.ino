#include <Carrinho.h>
#include <Motor.h>
#include <Ultrasonic.h>

//Configuracoes do sensor frontal.
#define FrontalTriggerPin 8
#define FrontalEchoPin 9

//Configuracoes do sensor lateral.
#define LateralTriggerPin 11
#define LateralEchoPin 10

//Configuracoes motorA
#define IN1 2
#define IN2 3
#define PWMA 12    //Pino PWM do Motor A
#define VA 130     //Valor analogico PWM

//Configuracoes motorB
#define IN3 4
#define IN4 5
#define PWMB 13   //Pino PWM do Motor B
#define VB 130    //Valor analogico PWM

//Ultrasonic sensor(8, 9);

//Intanciando um objeto do tipos carrinho que recebe dois motores
//Os dois motores devem estar previamente configurados.

                                  //Criando um nova instancia para o motorA.
Carrinho *carrinho = new Carrinho(new Motor(IN1, IN2, PWMA, VA),
                                  //Criando um nova instancia para o motorB.
                                  new Motor(IN3, IN4, PWMB, VB),
                                  //Criando um nova instancia para o sensor frontal.
                                  new Ultrasonic(FrontalTriggerPin, FrontalEchoPin),
                                  //Criando um nova instancia para o sensor lateral.
                                  new Ultrasonic(LateralTriggerPin, LateralEchoPin));

void setup() {
  //Configuracoes gerais dos dipositivos ligados ao Arduino.
  Serial.begin(9600);
  carrinho->configCarrinho();
}

void loop() {
   if(!carrinho->livreAFrente() && !carrinho->livreAEsquerda()) {
     carrinho->direita();
   }
   else if(!carrinho->livreAFrente() && carrinho->livreAEsquerda()) {
     carrinho->esquerda();
   }
   else if(carrinho->livreAFrente() && !carrinho->livreAEsquerda()) {
     carrinho->andar();
   }
   else if(carrinho->livreAFrente() && carrinho->livreAEsquerda()) {
     carrinho->esquerda();
     carrinho->andar();
   }
}
