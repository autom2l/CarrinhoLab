#include <Arduino.h>
#include <Carrinho.h>

  /**************************************************************************************************
  * Metodo Construtor do carrinho.                                                                  *
  * Recebe 2 Motores configurados (E reponsabilidade do programador fazer as devidas configuracoes) *
  ***************************************************************************************************/
Carrinho::Carrinho(Motor *a, Motor *b, Ultrasonic *frontal, Ultrasonic *lateral)
  :motorA(a), motorB(b), sensorFrontal(frontal), sensorLateral(lateral) {}

/**********************************************************************
*                                                                     *
* Configura os pinos dos motores A e B para o funcionamento do motor. *
*                                                                     *
***********************************************************************/
void Carrinho::configCarrinho() {
  motorA->config();
  motorB->config();
  sensorFrontal->Config();
  sensorLateral->Config();
}

//Vira o carrinho para a esquerda.
void Carrinho::esquerda() {
  digitalWrite(motorA->getINA(), LOW);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(188);
}

//Vira o carrinho para a direita.
void Carrinho::direita() {
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  digitalWrite(motorB->getINA(), LOW);
  digitalWrite(motorB->getINB(), HIGH);
  delay(188);
}

//Faz o carrinho andar pra frente.
void Carrinho::andar(){
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(190);
}

//Faz o carrinho parar.
void Carrinho::parar() {
  /************************************
  *         Para o motor A            *
  *************************************/
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), HIGH);

  /************************************
  *         Para o motor B            *
  *************************************/
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), HIGH);
  delay(2500);
}

//Funcoes de uso dos sensores.
bool Carrinho::livreAEsquerda() {return (sensorLateral->Ranging(CM) > 7);}
bool Carrinho::livreAFrente() {return (sensorFrontal->Ranging(CM) > 7);}

int Carrinho::olhar() {
  this->parar();
  if     (!livreAFrente() && !livreAEsquerda()) return 1;
  else if(!livreAFrente() &&  livreAEsquerda()) return 2;
  else if( livreAFrente() && !livreAEsquerda()) return 3;
  else if( livreAFrente() &&  livreAEsquerda()) return 4;
}
