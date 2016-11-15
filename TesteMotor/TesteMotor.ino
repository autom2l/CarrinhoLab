#include <Carrinho.h>
#include <Motor.h>
#include <Ultrasonic.h>
#include <Servo.h>

//Configuracoes do sensor frontal.
#define FrontalTriggerPin  9
#define FrontalEchoPin     7

#define LateralTriggerPin  13
#define LateralEchoPin 12

//Configuracoes motorA
#define IN1                2
#define IN2                3
#define PWMA               6      //Pino PWM do Motor A
#define VA                 128     //Valor analogico PWM

//Configuracoes motorB
#define IN3                4
#define IN4                5
#define PWMB               11     //Pino PWM do Motor B
#define VB                 100    //Valor analogico PWM

//Intanciando um objeto do tipos carrinho que recebe dois motores
//Os dois motores devem estar previamente configurados.

                                  //Criando um nova instancia para o motorA.
Carrinho *carrinho = new Carrinho(new Motor(IN1, IN2, PWMA, VA),
                                  //Criando um nova instancia para o motorB.
                                  new Motor(IN3, IN4, PWMB, VB),
                                  //Criando um nova instancia para o sensor frontal.
                                  new Ultrasonic(FrontalTriggerPin, FrontalEchoPin),
                                  //Criando uma nova intancia prar o sensor lateral.
                                  new Ultrasonic(LateralTriggerPin, LateralEchoPin),
                                  //Criando um nova instancia para o servo motor.
                                  new Servo());

void setup() {
  //Configuracoes gerais dos dipositivos ligados ao Arduino.
  Serial.begin(9600);
  carrinho->configCarrinho();
}

void loop() {
  switch(carrinho->verificar()){
    case 1:
      carrinho->esquerda();
      break;
    case 2:
      carrinho->esquerda();
      carrinho->esquerda();
      break;
    case 3:
      carrinho->andar();
      break;
    default:
      break;
  }
}
