#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento { // clase derivada de instrumento
public:
    Bateria(QString marca = "Yamaha", int tambores = 5);

    void sonar(); //funcion virtual pura
    int getTambores();
    void setTambores(int tambores);

private:
    int tambores;
};

#endif // BATERIA_H
