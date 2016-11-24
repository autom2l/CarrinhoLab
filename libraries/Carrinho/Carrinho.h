#ifndef CARRINHO_H
#define CARRINHO_H

#include <Arduino.h>
#include <Motor.h>
#include <Ultrasonic.h>
#include <Servo.h>

 /*******************************************************
 *    Interface de configuracao geral do carrinho.    *
 ********************************************************/

class Carrinho {
  public:
    //Metodo construtor.
    Carrinho(Motor*, Motor*, Ultrasonic*, Ultrasonic*, Servo*);
    Carrinho(Motor*, Motor*, Ultrasonic*, Ultrasonic*);

    //Funcao de configuracao do carrinho.
    void  configCarrinho();

    //Funcoes de acao do carrinho.
    void  esquerda();             //Gira o carrinho para a esquerda.
    void  meiaVolta();            //Vira o carrinho 180 graus.
    void  andar();                //Anda pra frente.
    void  parar();                //Parar o carrinho.

    void setMotorA(int);
    void setMotorB(int);

    bool livreAFrente();
    bool livreAEsquerda();
    int verificar();
    void olharFrente();

  private:
    Motor *motorA, *motorB;
    Ultrasonic *sensorFrontal, *sensorLateral;
    Servo *servo;
};

#endif
