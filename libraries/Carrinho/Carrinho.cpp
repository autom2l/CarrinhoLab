#include <Arduino.h>
#include <Carrinho.h>


  /**************************************************************************************************
  * Metodo Construtor do carrinho.                                                                  *
  * Recebe 2 Motores configurados (E reponsabilidade do programador fazer as devidas configuracoes) *
  ***************************************************************************************************/
Carrinho::Carrinho(Motor *a, Motor *b, Ultrasonic *frontal, Servo *servoMotor)
  :motorA(a), motorB(b), sensorFrontal(frontal), sensorLateral(NULL), servo(servoMotor) {}

Carrinho::Carrinho(Motor *a, Motor *b, Ultrasonic *frontal, Ultrasonic *lateral, Servo *servoMotor)
  :motorA(a), motorB(b), sensorFrontal(frontal), sensorLateral(lateral), servo(servoMotor) {}

/**********************************************************************
*                                                                     *
* Configura os pinos dos motores A e B para o funcionamento do motor. *
*                                                                     *
***********************************************************************/
void Carrinho::configCarrinho() {
  motorA->config();
  motorB->config();
  sensorFrontal->Config();
  servo->attach(8);
  this->olharFrente();
}

//Vira o carrinho para a esquerda.
void Carrinho::esquerda() {
  digitalWrite(motorA->getINA(), LOW);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  olharFrente();
  delay(200);
}

//Vira o carrinho para a direita.
void Carrinho::direita() {
  this->setMotor('a', 140);
  this->setMotor('b', 160);
  delay(500);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  digitalWrite(motorB->getINA(), LOW);
  digitalWrite(motorB->getINB(), HIGH);
  olharFrente();
}

//Faz o carrinho andar pra frente.
void Carrinho::andar(){
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(600);
}

//Faz o carrinho parar.
void Carrinho::parar() {
  this->setMotor('a', 255);
  this->setMotor('b', 255);
  delay(1000);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), HIGH);
}

void Carrinho::setMotor(char motor, int newVel) {
  if(motor == 'A' || motor == 'a') {
    motorA->setVelocidade(newVel);
    analogWrite(motorA->getPWM(), motorA->getVelocidade());
    return;
  }

  if(motor == 'B' || motor == 'b') {
    motorB->setVelocidade(newVel);
    analogWrite(motorB->getPWM(), motorB->getVelocidade());
    return;
  }
}

bool Carrinho::direcaoLivre() {
  delay(200);
  return (sensorFrontal->Ranging(CM) > 8);
}

bool Carrinho::livreAEsquerda() {
  delay(200);
  return (sensorLateral->Ranging(CM) > 8);
}

bool Carrinho::olharDireita(){
  servo->write(170);
  return this->direcaoLivre();
}

bool Carrinho::olharEsquerda(){
  servo->write(3);
  return this->direcaoLivre();
}

void Carrinho::olharFrente() {
  servo->write(80);
  delay(500);
}
