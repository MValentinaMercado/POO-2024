#include <iostream>
#include <ctime>
#include <cstdlib>//para los numeros aleatorios
using namespace std;

int main() {
    cout<<"Numeros aleatorios:"<<endl;
    srand(time(nullptr));

    int num = 10;
    int minimo = 2;
    int maximo = 20;

    for (int i = 0; i < num; ++i) {
        int aleatorio = minimo + rand() % (maximo - minimo + 1);
        cout << aleatorio << " ";
    }
    cout<<endl;
    return 0;
}
