#include "bateria.h"

Bateria::Bateria(QString marca, int tambores) : Instrumento(marca), tambores(tambores) {}

void Bateria::sonar() {
    qDebug() << "Batería suena...";
}

int Bateria::getTambores() {
    return tambores;
}

void Bateria::setTambores(int tambores) {
    this->tambores = tambores;
}
