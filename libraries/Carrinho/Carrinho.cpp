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
  this->setMotor('a', 255);
  this->setMotor('b', 200);
  //digitalWrite(motorA->getINA(), LOW);
  //digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(700);
  this->parar();
}

//Vira o carrinho para a direita.
void Carrinho::direita() {
  this->setMotor('a', 200);
  this->setMotor('b', 255);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  //digitalWrite(motorB->getINA(), LOW);
  //digitalWrite(motorB->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), HIGH);
  delay(590);
  this->parar();
}

//Faz o carrinho andar pra frente.
void Carrinho::andar(){
  this->setMotor('a', 255);
  this->setMotor('b', 200);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(500);
}

//Faz o carrinho parar.
void Carrinho::parar() {
  this->setMotor('a', 255);
  this->setMotor('b', 255);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), HIGH);
  delay(500);
}

/******************************************
 *      Funcao de configuracao do motor   *
 ******************************************/

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

bool Carrinho::livreAFrente() {
  return (sensorFrontal->Ranging(CM) > 15);
}

bool Carrinho::livreAEsquerda() {
  return (sensorLateral->Ranging(CM) > 15);
}

int Carrinho::verificar(){
  this->parar();
  if(this->livreAEsquerda())
    return 1;
  if(!this->livreAEsquerda() && !this->livreAFrente())
    return 2;
  if(this->livreAFrente() && !this->livreAEsquerda())
    return 3;
  return 0;
}

void Carrinho::olharFrente() {
  servo->write(80);
  delay(500);
}
