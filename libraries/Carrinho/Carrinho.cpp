#include <Carrinho.h>

  /**************************************************************************************************
  * Metodo Construtor do carrinho.                                                                  *
  * Recebe 2 Motores configurados (E reponsabilidade do programador fazer as devidas configuracoes) *
  ***************************************************************************************************/
Carrinho::Carrinho(Motor *a, Motor *b, Ultrasonic *frontal, Ultrasonic *lateral, Servo *servoMotor)
  :motorA(a), motorB(b), sensorFrontal(frontal), sensorLateral(lateral), servo(servoMotor) {}

Carrinho::Carrinho(Motor *a, Motor *b, Ultrasonic *frontal, Ultrasonic *lateral)
  :motorA(a), motorB(b), sensorFrontal(frontal), sensorLateral(lateral), servo(NULL) {}

/**********************************************************************
*                                                                     *
* Configura os pinos dos motores A e B para o funcionamento do motor. *
*                                                                     *
***********************************************************************/
void Carrinho::configCarrinho() {
  motorA->config();
  motorB->config();
  sensorFrontal->Config();
  if(this->servo != NULL) servo->attach(8);
  this->olharFrente();
}

//Vira o carrinho para a esquerda.
void Carrinho::esquerda() {
  this->setMotorA(135);
  this->setMotorB(255);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(1000);
  this->parar();
}

//Vira o carrinho 180 graus.
void Carrinho::meiaVolta() {
  this->setMotorA(142);
  this->setMotorB(110);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);

  digitalWrite(motorB->getINA(), LOW);
  digitalWrite(motorB->getINB(), HIGH);
  delay(1000);
  this->parar();
}

//Faz o carrinho andar pra frente.
void Carrinho::andar(){
  this->setMotorA(125);
  this->setMotorB(110);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), LOW);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), LOW);
  delay(980);
}

//Faz o carrinho parar.
void Carrinho::parar() {
  this->setMotorA(255);
  this->setMotorB(255);
  digitalWrite(motorA->getINA(), HIGH);
  digitalWrite(motorA->getINB(), HIGH);
  digitalWrite(motorB->getINA(), HIGH);
  digitalWrite(motorB->getINB(), HIGH);
  delay(200);
}

/******************************************
 *      Funcao de configuracao do motor   *
 ******************************************/

void Carrinho::setMotorA(int newVel) {
  this->motorA->setVelocidade(newVel);
  analogWrite(this->motorA->getPWM(), this->motorA->getVelocidade());
  return;
}

void Carrinho::setMotorB(int newVel) {
  this->motorB->setVelocidade(newVel);
  analogWrite(this->motorB->getPWM(), this->motorB->getVelocidade());
  return;
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
  if(servo != NULL) {
    servo->write(80);
    delay(500);
    return;
  }
}
