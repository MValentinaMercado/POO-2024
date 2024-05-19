#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Cuidador;

class Animal {
private:
    string especie;
    string habitat;
    string alimentacion;
    bool Domestico;

public:
    Animal();
    Animal(string especie, string habitat, string alimentacion, bool esDomestico);

    inline string getEspecie();
    inline string getHabitat();
    inline string getAlimentacion();
    inline bool esDomestic();

    void mostrarInfo();

    friend class Cuidador;
};


inline string Animal::getEspecie() {
    return especie;
}

inline string Animal::getHabitat() {
    return habitat;
}

inline string Animal::getAlimentacion() {
    return alimentacion;
}

inline bool Animal::esDomestic() {
    return Domestico;
}


class Mascota : public Animal {
private:
    string nombre;

public:
    Mascota(string nombre, string especie, string habitat, string alimentacion, bool esDomestico);
    void mostrarInfo();
};


class Cuidador {
public:
    void cambiarHabitat(Animal &animal, string nuevoHabitat);
};

#endif // ANIMAL_H
