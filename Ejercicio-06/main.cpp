#include <iostream>
#include "Animal.h"
#include "proyecto.h"

using namespace std;

int main() {
    Animal perro("Perro", "Terrestre", "Croquetas", true);
    Animal tigre("Tigre", "Selva", "Carne", false);
    Animal loro("Loro", "Selva", "Semillas", true);

    perro.mostrarInfo();
    tigre.mostrarInfo();
    loro.mostrarInfo();

      /*cout<<"-.-.-.-.-.-.-.-.-"<<endl;
      string version = proyecto::getVersion();
      cout << version << endl;*/

    return 0;
}
