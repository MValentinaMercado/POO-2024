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
    Animal();
    Animal(string especie, string habitat, string alimentacion, bool esDomestico);

    string getEspecie();
    string getHabitat();
    string getAlimentacion();
    bool esDomestic();

    void mostrarInfo();

    static bool compararPorEspecie(Animal* a, Animal* b);//independiente a los objetos, se utiliza como argmento para sort
};

#endif
