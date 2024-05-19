// Animal.cpp
#include "Animal.h"

Animal::Animal() {}

Animal::Animal(string especie, string habitat, string alimentacion, bool Domestico) {
    this->especie = especie;
    this->habitat = habitat;
    this->alimentacion = alimentacion;
    this->Domestico = Domestico;
}

string Animal::getEspecie() {
    return especie;
}

string Animal::getHabitat() {
    return habitat;
}

string Animal::getAlimentacion() {
    return alimentacion;
}

bool Animal::esDomestic() {
    return Domestico;
}

void Animal::mostrarInfo() {
    cout << "Especie: " << especie << endl;
    cout << "Habitat: " << habitat << endl;
    cout << "Alimentacion: " << alimentacion << endl;
    cout << (Domestico ? "Es domestico" : "Es salvaje") << endl;
    cout << endl;
}

bool Animal::compararPorEspecie(Animal* a, Animal* b) {
    return a->getEspecie() < b->getEspecie();
}
