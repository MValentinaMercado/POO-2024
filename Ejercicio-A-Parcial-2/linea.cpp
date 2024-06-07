#include "linea.h"

Linea::Linea(int x_ini, int y_ini, int x_fin, int y_fin)
    : x_inicial(x_ini), y_inicial(y_ini), x_final(x_fin), y_final(y_fin) {
}

int Linea::getXInicial() const {
    return x_inicial;
}

int Linea::getYInicial() const {
    return y_inicial;
}

int Linea::getXFinal() const {
    return x_final;
}

int Linea::getYFinal() const {
    return y_final;
}

void Linea::setXInicial(int x_ini) {
    x_inicial = x_ini;
}

void Linea::setYInicial(int y_ini) {
    y_inicial = y_ini;
}

void Linea::setXFinal(int x_fin) {
    x_final = x_fin;
}

void Linea::setYFinal(int y_fin) {
    y_final = y_fin;
}
