#include "instrumento.h"

Instrumento::Instrumento(QString  marca) : marca(marca) {}

Instrumento::~Instrumento() {}

void Instrumento::verlo() {
    qDebug() << "Marca:" << marca;
}
