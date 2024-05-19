#include "teclado.h"

Teclado::Teclado(QString marca, int teclas, int voltaje)
    : Instrumento(marca), Electrico(voltaje), teclas(teclas) {}

void Teclado::sonar() {
    qDebug() << "Teclado suena...";
}

int Teclado::getTeclas() {
    return teclas;
}

void Teclado::setTeclas(int teclas) {
    this->teclas = teclas;
}
