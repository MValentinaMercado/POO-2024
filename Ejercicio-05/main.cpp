#include <iostream>
#include <vector>
#include <algorithm> // Para sort
#include <string>
#include "proyecto.h"

using namespace std;

int main() {
    vector<string> expresiones = {
        "Poner el grito en el cielo",
        "Meter la pata",
        "Dar gato por liebre",
        "Estar hasta las manos",
        "Venir a cuento"
    };
    // Ordenar alfabéticamente
    sort(expresiones.begin(), expresiones.end());

    cout << "Expresiones:" << endl;
    for (const auto& expresion : expresiones) {
        cout << "- " << expresion <<endl;
    }

       /*cout<<"-.-.-.-.-.-.-.-.-"<<endl;
       string version = proyecto::getVersion();
       cout << version << endl;*/

    return 0;
}
