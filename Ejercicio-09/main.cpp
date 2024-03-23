
#include <iostream>
#include "proyecto.h"
using namespace std;

template <class T>
void imprimir(T *v, int cantidad, bool mayor_a_menor) {
    //p/inserccion
    for (int i = 1; i < cantidad; ++i) {
        T temp = v[i];
        int j = i - 1;
        if (mayor_a_menor) {
            while (j >= 0 && v[j] < temp) {
                v[j + 1] = v[j];
                --j;
            }
        } else {
            while (j >= 0 && v[j] > temp) {
                v[j + 1] = v[j];
                --j;
            }
        }
        v[j + 1] = temp;
    }

    //array ordenado
    if (mayor_a_menor) {
        cout << "Ordenado de mayor a menor: ";
        for (int i = 0; i < cantidad; ++i) {
            cout << v[i] << " ";
        }
    } else {
        cout << "Ordenado de menor a mayor: ";
        for (int i = 0; i < cantidad; ++i) {
            cout << v[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int array_enteros[] = {5, 2, 9, 1, 6};
    float array_flotantes[] = {3.5, 1.2, 7.8, 2.4, 5.6};

    int cantidad_enteros = sizeof(array_enteros) / sizeof(array_enteros[0]);
    int cantidad_flotantes = sizeof(array_flotantes) / sizeof(array_flotantes[0]);

    //De mayor a menor
    imprimir(array_enteros, cantidad_enteros, true);

    //De menor a mayor
    imprimir(array_flotantes, cantidad_flotantes, false);
	
	/*cout<<"-.-.-.-.-.-.-.-.-"<<endl;
      string version = proyecto::getVersion();
      cout << version << endl;*/

    return 0;
}
