#ifndef VIENTO_H
#define VIENTO_H


#include "instrumento.h"

class Viento : public Instrumento{
public:
    void afinar(); //clase virtual pura
    QString metal_usado;

};

#endif // VIENTO_H
