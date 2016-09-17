#include "Arduino.h"
#include "Motor.hpp"

  /************************************************
  *       Implementacao da interface Motor.hpp    *
  *************************************************/

  /********************************************
  * Metodo construtor do objeto Motor         *
  * Ja e inicializado com os devidos valores  *
  * de configuracao.                          *
  *********************************************/
Motor::Motor(int mA, int mB, int mPWM, int vel) 
: INA(mA), INB(mB), PWM(mPWM), velocidade(vel){
  
}

int   Motor::getINA(){return INA;}
int   Motor::getINB(){return INB;}
int   Motor::getPWM(){return PWM;}
int   Motor::getVelocidade(){return velocidade;}
void  Motor::config() {
  pinMode(getINA() ,OUTPUT);
  pinMode(getINB() ,OUTPUT);
  pinMode(getPWM() ,OUTPUT);
  analogWrite(getPWM(), getVelocidade());
}
