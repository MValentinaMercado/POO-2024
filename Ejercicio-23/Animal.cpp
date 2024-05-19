#include "Animal.h"

Animal::Animal() {}

Animal::Animal(string especie, string habitat, string alimentacion, bool Domestico) {
    this->especie = especie;
    this->habitat = habitat;
    this->alimentacion = alimentacion;
    this->Domestico = Domestico;
}
void Animal::mostrarInfo() {
    cout << "Especie: " << especie << endl;
    cout << "Habitat: " << habitat << endl;
    cout << "Alimentacion: " << alimentacion << endl;
    cout << (Domestico ? "Es domestico" : "Es salvaje") << endl;
    cout << endl;
}

Mascota::Mascota(string nombre, string especie, string habitat, string alimentacion, bool esDomestico)
    : Animal(especie, habitat, alimentacion, esDomestico), nombre(nombre) {}

void Mascota::mostrarInfo() {
    if(esDomestic()){
        cout << "Nombre: " << nombre << endl;
            Animal::mostrarInfo();
    }else{
        Animal::mostrarInfo();
    }
}

void Cuidador::cambiarHabitat(
        Animal &animal, string nuevoHabitat) {
    animal.habitat = nuevoHabitat;
}
