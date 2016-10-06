/************************************************
*       Implementacao da interface Motor.h    *
*************************************************/

#include "Arduino.h"
#include "Motor.h"

  /********************************************
  * Metodo construtor do objeto Motor         *
  * Ja e inicializado com os devidos valores  *
  * de configuracao.                          *
  *********************************************/
Motor::Motor(int mA, int mB, int mPWM, int vel)
: INA(mA), INB(mB), PWM(mPWM) {
  //Garante que o valor para o PWM esteja entre 0 e 255.
  if(vel <= 255 || vel >= 0) velocidade = vel;
  else if(vel > 255) velocidade = 255;
  else if(vel < 0)   velocidade = 0;
}

//Retorna o numero do pino que esta ligado na entrada IN[1-4] da ponte H.
int   Motor::getINA(){return INA;}
int   Motor::getINB(){return INB;}

//Retorna o numero do pino que esta ligado na entrada INA ou INB da ponte H.
int   Motor::getPWM(){return PWM;}

//Retorna o valor analogico configurado para o PWM.
//
int   Motor::getVelocidade(){return velocidade;}

void  Motor::config() {
  pinMode(getINA() ,OUTPUT);
  pinMode(getINB() ,OUTPUT);
  pinMode(getPWM() ,OUTPUT);
  analogWrite(getPWM(), getVelocidade());
}
