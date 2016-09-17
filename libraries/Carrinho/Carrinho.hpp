#ifndef CARRINHO_H
#define CARRINHO_H

#include "Arduino.h"
#include "Motor.h"

 /*******************************************************
 *    Interface para configuracao geral do carrinho.    *
 ********************************************************/

class Carrinho {
  public:
    Carrinho(Motor a, Motor b); //Metodo construtor
    void  esquerda();           //Gira o carrinho para a esquerda.
    void  direita();            //Gira o carrinho para a direita.
    void  andar();              //Anda pra frente.
    void  parar();              //Parar o carrinho.
  private:
    Motor motorA, motorB;
};

#endif
