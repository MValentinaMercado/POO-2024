#include "electrico.h"

Electrico::Electrico(int voltaje) : voltaje(voltaje) {}

Electrico::~Electrico() {
    qDebug() << "Desenchufado";
}

int Electrico::getVoltaje() {
    return voltaje;
}

void Electrico::setVoltaje(int voltaje) {
    this->voltaje = voltaje;
}
