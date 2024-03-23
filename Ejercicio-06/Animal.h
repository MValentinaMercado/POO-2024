// Animal.h
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal {
private:
    string especie;
    string habitat;
    string alimentacion;
    bool Domestico;

public:
    // Constructores
    Animal();
    Animal(string especie, string habitat, string alimentacion, bool esDomestico);

    // Métodos para obtener información
    string getEspecie();
    string getHabitat();
    string getAlimentacion();
    bool esDomestic();

    // Método para mostrar información
    void mostrarInfo();
};

#endif // ANIMAL_H
