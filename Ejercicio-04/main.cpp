#include <vector>
#include <iostream>
#include <ctime>
#include "proyecto.h"
using namespace std;

int main() {
    srand(time(0));

    vector<int> valores(30);
    for (int i = 0; i < 30; i++) {
        valores[i] = 1 + rand() % 15;
    }
    cout << "Valores generados:" << endl;
    for (int i = 0; i < 30; ++i) {
        cout << valores[i] << " ";
    }
    cout << endl;

    vector<int> contador(15, 0);
    for (int i = 0; i < 30; i++) {
        contador[valores[i] - 1]++;
    }

    int moda = 1;
    int maxO = contador[0];
    for (int i = 1; i < 15; ++i) {
        if (contador[i] > maxO) {
            maxO = contador[i];
            moda = i + 1;
        }
    }

    cout << "La moda es: " << moda << ", que aparece " << maxO << " veces." << endl;

    /*cout<<"-.-.-.-.-.-.-.-.-"<<endl;
    string version = proyecto::getVersion();
    cout << version << endl;*/

    return 0;
}
