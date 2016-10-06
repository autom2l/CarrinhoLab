#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
/*
  * Confira um unico motor.
  *
  *****************************************
  * E responsabilidade do programador     *
  * nao repetir a mesma configurcao para  *
  * dois motores ao mesmo tempo.          *
  *****************************************
  *
*/

class Motor {
  public:
    Motor(int, int, int, int);
    int getINA();         //Retorna o pino INA.
    int getINB();         //Retorna o pino INB.
    int getPWM();         //Retorna o pinoPWM.
    int getVelocidade();  //Retorna o valor do pwm(0 - 255).
    void config();        //Faz as devidaas configuracoes no arquivo principal do arduino.
  private:
    int INA;        //Guarda o numero do pino de configuracao do motor no arduino.
    int INB;        //Guarda o numero do pino de configuracao do motor no arduino.
    int PWM;        //Guarda o numero do pino de configuracao pwm do motor no arduino.
    int velocidade; //Configuracao dodo valor pwm (0 - 255).
};

#endif
