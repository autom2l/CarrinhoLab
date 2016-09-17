#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor {
  public:
    Motor(int mA, int mB, int mPWM, int vel);
    int getINA();
    int getINB();
    int getPWM();
    int getVelocidade();
    void config();
  private:
    int INA;        //Guarda o numero do pino de configuracao do motor no arduino.
    int INB;        //Guarda o numero do pino de configuracao do motor no arduino.
    int PWM;        //Guarda o numero do pino de configuracao pwm do motor no arduino.
    int velocidade; //Configuracao dodo valor pwm (0 - 255).
};

#endif
