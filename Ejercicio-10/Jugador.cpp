#include "Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){
    velocidad = 0;
    fuerza = 0;
    nombre = "sin nombre";
}

Jugador::Jugador(int v, int f, string n){
    velocidad = v;
    fuerza = f;
    nombre = n;
}

Jugador::~Jugador() {}

int Jugador::getVelocidad() {
    return velocidad;
}

int Jugador::getFuerza() {
    return fuerza;
}

string Jugador::getNombre() {
    return nombre;
}

void Jugador::setVelocidad(int v) {
    velocidad = v;
}

void Jugador::setFuerza(int f) {
    fuerza = f;
}

void Jugador::setNombre(string n) {
    nombre = n;
}

void Jugador::mostrarDatos() {
    cout << "Nombre: " << nombre << ", Velocidad: " << velocidad
         << ", Fuerza: " << fuerza << endl;
}
