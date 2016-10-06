#include "Arduino.h"
#include "Carrinho.h"

  /**************************************************************************************************
  * Metodo Construtor do carrinho.                                                                  *
  * Recebe 2 Motores configurados (E reponsabilidade do programador fazer as devidas configuracoes) *
  ***************************************************************************************************/
Carrinho::Carrinho(Motor a, Motor b):motorA(a), motorB(b) {
  //analogWrite(motorA.getPWM(), motorA.getVelocidade());
  //analogWrite(motorB.getPWM(), motorB.getVelocidade());
}

//Configura os pinos dos motores A e B para o funcionamento do motor.
void Carrinho::configMotores() {
  motorA.config();
  motorB.config();
}

//Vira o carrinho para a esquerda.
void Carrinho::esquerda() {
  digitalWrite(motorA.getINA(), LOW);
  digitalWrite(motorA.getINB(), HIGH);
  digitalWrite(motorB.getINA(), HIGH);
  digitalWrite(motorB.getINB(), LOW);
  delay(500);
}

//Vira o carrinho para a direita.
void Carrinho::direita() {
  digitalWrite(motorA.getINA(), HIGH);
  digitalWrite(motorA.getINB(), LOW);
  digitalWrite(motorB.getINA(), LOW);
  digitalWrite(motorB.getINB(), HIGH);
  delay(500);
}

//Faz o carrinho andar pra frente.
void Carrinho::andar(){
  digitalWrite(motorA.getINA(), HIGH);
  digitalWrite(motorA.getINB(), LOW);
  digitalWrite(motorB.getINA(), HIGH);
  digitalWrite(motorB.getINB(), LOW);
  delay(200);
}

//Faz o carrinho parar.
void Carrinho::parar() {
  digitalWrite(motorA.getINA(), HIGH);
  digitalWrite(motorA.getINB(), HIGH);
  digitalWrite(motorB.getINA(), HIGH);
  digitalWrite(motorB.getINB(), HIGH);
  delay(800);
}
