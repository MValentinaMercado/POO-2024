#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"

class Teclado : public Instrumento{
public:
    void afinar(); //clase virtual pura
    int cantidad_de_teclas;

};

#endif // TECLADO_H
