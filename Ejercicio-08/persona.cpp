#include "Persona.h"

Persona::Persona(string n, int e) {
    nombre = n;
    edad = e;
}

void Persona::getDatos(string &nombre, int &edad) {
    nombre = this->nombre;
    edad = this->edad;
}

void Persona::setDatos(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}
