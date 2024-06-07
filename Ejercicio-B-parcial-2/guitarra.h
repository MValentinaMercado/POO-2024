#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento { //clase derivada de instrumento
public:
    void afinar();
    int cantidad_de_cuerdas;
};

#endif // GUITARRA_H
