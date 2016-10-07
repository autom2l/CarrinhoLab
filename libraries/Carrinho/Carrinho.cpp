#include <Arduino.h>
#include <Carrinho.h>

  /**************************************************************************************************
  * Metodo Construtor do carrinho.                                                                  *
  * Recebe 2 Motores configurados (E reponsabilidade do programador fazer as devidas configuracoes) *
  ***************************************************************************************************/
Carrinho::Carrinho(Motor *a, Motor *b, Ultrasonic *frontal, Ultrasonic *lateral)
  :motorA(a), motorB(b), sensorFrontal(frontal), sensorLateral(lateral) {
  //analogWrite(motorA.getPWM(), motorA.getVelocidade());
  //analogWrite(motorB.getPWM(), motorB.getVelocidade());
}

//Configura os pinos dos motores A e B para o funcionamento do motor.
void Carrinho::configCarrinho() {
  this->motorA->config();
  this->motorB->config();
  this->sensorFrontal->config();
  this->sensorLateral->config();
}

//Vira o carrinho para a esquerda.
void Carrinho::esquerda() {
  digitalWrite(this->motorA->getINA(), LOW);
  digitalWrite(this->motorA->getINB(), HIGH);
  digitalWrite(this->motorB->getINA(), HIGH);
  digitalWrite(this->motorB->getINB(), LOW);
  delay(500);
}

//Vira o carrinho para a direita.
void Carrinho::direita() {
  digitalWrite(this->motorA->getINA(), HIGH);
  digitalWrite(this->motorA->getINB(), LOW);
  digitalWrite(this->motorB->getINA(), LOW);
  digitalWrite(this->motorB->getINB(), HIGH);
  delay(500);
}

//Faz o carrinho andar pra frente.
void Carrinho::andar(){
  digitalWrite(this->motorA->getINA(), HIGH);
  digitalWrite(this->motorA->getINB(), LOW);
  digitalWrite(this->motorB->getINA(), HIGH);
  digitalWrite(this->motorB->getINB(), LOW);
  delay(200);
}

//Faz o carrinho parar.
void Carrinho::parar() {
  digitalWrite(this->motorA->getINA(), HIGH);
  digitalWrite(this->motorA->getINB(), HIGH);
  digitalWrite(this->motorB->getINA(), HIGH);
  digitalWrite(this->motorB->getINB(), HIGH);
  delay(800);
}

//Funcoes de uso dos sensores.
bool Carrinho::livreAEsquerda() {return (this->sensorLateral->Ranging(CM) > 5);}
bool Carrinho::livreAFrente() {return (this->sensorFrontal->Ranging(CM) > 5);}
