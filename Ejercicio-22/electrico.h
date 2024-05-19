#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <QDebug>

class Electrico { //clase base de teclado
public:
    Electrico(int voltaje = 220);
    virtual ~Electrico();

    int getVoltaje();
    void setVoltaje(int voltaje);

private:
    int voltaje;
};

#endif // ELECTRICO_H
