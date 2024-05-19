#include <iostream>
#include "Animal.h"

using namespace std;

int main() {
    Mascota perro("Carlos","Perro", "Terrestre", "Croquetas", true);
    Animal tigre("Tigre", "Selva", "Carne", false);
    Mascota loro("Pepa", "Loro", "Selva", "Semillas", true);

    perro.mostrarInfo();
    tigre.mostrarInfo();
    loro.mostrarInfo();

    Cuidador cuidador;
    cuidador.cambiarHabitat(tigre, "Reserva Natural");
    tigre.mostrarInfo();

    return 0;
}
