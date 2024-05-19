#include "guitarra.h"

Guitarra::Guitarra(QString marca, int cuerdas) : Instrumento(marca), cuerdas(cuerdas) {}

void Guitarra::sonar() {
    qDebug() << "Guitarra suena...";
}

int Guitarra::getCuerdas() {
    return cuerdas;
}

void Guitarra::setCuerdas(int cuerdas) {
    this->cuerdas = cuerdas;
}
