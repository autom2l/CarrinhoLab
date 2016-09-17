#ifndef MOTOR_H
#define MOTOR_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Motor {
  public:
    Motor(int mA, int mB, int mPWM, int vel);
    int getINA();
    int getINB();
    int getPWM();
    int getVelocidade();
    void config();
  private:
    int INA;
    int INB;
    int PWM;
    int velocidade;
};

#endif
