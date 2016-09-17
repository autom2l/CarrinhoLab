#ifndef CARRINHO_H
#define CARRINHO_H

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Motor.h"

class Carrinho {
  public:
    Carrinho(Motor a, Motor b);
    void  esquerda();
    void  direita();
    void  andar();
    void  parar();
  private:
    Motor motorA, motorB;
};

#endif
