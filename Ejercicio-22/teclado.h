#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico { // clase derivada de intrumento y electrivo (herencia multiple)
public:
    Teclado(QString marca = "Yamaha", int teclas = 61, int voltaje = 220);

    void sonar(); //clase virtual pura
    int getTeclas();
    void setTeclas(int teclas);

private:
    int teclas;
};

#endif // TECLADO_H
