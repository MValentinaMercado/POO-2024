#include <iostream>
#include <vector>
#include <algorithm>
#include "Animal.h"


using namespace std;

int main() {
    vector<Animal*> animales;

    Animal* perro = new Animal("Perro", "Terrestre", "Croquetas", true);
    Animal* zorro = new Animal("Zorro", "Bosque", "Frutas", false);
    Animal* loro = new Animal("Loro", "Selva", "Semillas", true);

    animales.push_back(perro);
    animales.push_back(zorro);
    animales.push_back(loro);

    sort(animales.begin(), animales.end(), Animal::compararPorEspecie);//ordena segun la especie del objeto

    for (const auto& animal : animales) {
        animal->mostrarInfo();
    }


    return 0;
}
