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
    Carrinho(Motor*, Motor*, Ultrasonic*, Servo*);
    Carrinho(Motor*, Motor*, Ultrasonic*, Ultrasonic*, Servo*);

    //Funcao de configuracao do carrinho.
    void  configCarrinho();

    //Funcoes de acao do carrinho.
    void  esquerda();             //Gira o carrinho para a esquerda.
    void  direita();              //Gira o carrinho para a direita.
    void  andar();                //Anda pra frente.
    void  parar();                //Parar o carrinho.

    void setMotor(char, int);

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
