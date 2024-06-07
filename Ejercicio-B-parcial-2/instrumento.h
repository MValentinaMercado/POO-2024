#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>

class Instrumento {
public:
    virtual ~Instrumento();
    virtual void afinar() = 0; //funcion virtual pura

    QString marca;
    double precio;

};

#endif // INSTRUMENTO_H
