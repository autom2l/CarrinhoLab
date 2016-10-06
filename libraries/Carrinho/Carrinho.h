#ifndef CARRINHO_H
#define CARRINHO_H

#include "Arduino.h"
#include "Motor.h"
#include <Ultrasonic.h>

 /*******************************************************
 *    Interface para configuracao geral do carrinho.    *
 ********************************************************/

class Carrinho {
  public:
    //Metodo construtor.
    Carrinho(Motor*, Motor*, Ultrasonic*, Ultrasonic*);
    //Funcao de configuracao do carrinho.
    void  configCarrinho();

    //Funcoes de acao do carrinho.
    void  esquerda();             //Gira o carrinho para a esquerda.
    void  direita();              //Gira o carrinho para a direita.
    void  andar();                //Anda pra frente.
    void  parar();                //Parar o carrinho.
    
    //Funcoes de uso dos sensores.
    bool livreAEsquerda();
    bool livreAFrente();
  private:
    Motor *motorA, *motorB;
    Ultrasonic *sensorFrontal, *sensorLateral;
};

#endif
