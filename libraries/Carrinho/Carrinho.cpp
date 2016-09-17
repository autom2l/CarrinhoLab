#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Carrinho.h"

Carrinho::Carrinho(Motor a, Motor b):motorA(a), motorB(b) {
  analogWrite(motorA.getPWM(), motorA.getVelocidade());
  analogWrite(motorB.getPWM(), motorB.getVelocidade());
}
void Carrinho::esquerda() {
  digitalWrite(motorA.getINA(), LOW);
  digitalWrite(motorA.getINB(), HIGH);
  digitalWrite(motorB.getINA(), HIGH);
  digitalWrite(motorB.getINB(), LOW);
  delay(500);
}
void Carrinho::direita() {
  digitalWrite(motorA.getINA(), HIGH);
  digitalWrite(motorA.getINB(), LOW);
  digitalWrite(motorB.getINA(), LOW);
  digitalWrite(motorB.getINB(), HIGH);
  delay(500);
}
void Carrinho::andar(){
  digitalWrite(motorA.getINA(), HIGH);
  digitalWrite(motorA.getINB(), LOW);
  digitalWrite(motorB.getINA(), HIGH);
  digitalWrite(motorB.getINB(), LOW);
  delay(200);
}
void Carrinho::parar() {
  digitalWrite(motorA.getINA(), HIGH);
  digitalWrite(motorA.getINB(), HIGH);
  digitalWrite(motorB.getINA(), HIGH);
  digitalWrite(motorB.getINB(), HIGH);
  delay(800);
}
