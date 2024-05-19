#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento { //clase derivada de instrumento
public:
    Guitarra(QString marca = "Yamaha", int cuerdas = 6);

    void sonar(); // funcion virtual pura
    int getCuerdas();
    void setCuerdas(int cuerdas);

private:
    int cuerdas;
};

#endif // GUITARRA_H
