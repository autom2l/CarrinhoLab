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
#define PWMA 12 //Pino PWM do Motor A
#define VA 130  //Valor analogico PWM

//configuracoes motorB
#define IN3 3
#define IN4 4
#define PWMB 13 //Pino PWM do Motor B
#define VB 130  //Valor analogico PWM

//Intanciando um objeto para o sensor ultrasonico frontal e lateral.
//Configurando o sensor com seus respectivos pinos de trigger e echo
Ultrasonic  *ultrasonicFrontal = new Ultrasonic(FrontalTriggerPin, FrontalEchoPin);
Ultrasonic  *ultrasonicLateral = new Ultrasonic(LateralTriggerPin, LateralTriggerPin);

//Instanciando um objeto do tipo Motor para o motor A e B.
//Configura o mortor A e B para usar seus respectivos pinos.
Motor *motorA = new Motor(IN1, IN2, PWMA, VA);
Motor *motorB = new Motor(IN3, IN4, PWMB, VB);

//Intanciando um objeto do tipos carrinho que recebe dois motores
//Os dois motores devem estar previamente configurados.
Carrinho *carrinho = new Carrinho(motorA, motorB, ultrasonicFrontal, ultrasonicLateral);

void setup() {
  //Configuracoes gerais dos dipositivos ligados ao Arduino.
  //Configura ambos os motores.
  carrinho->configCarrinho();
}

void loop() {

}
