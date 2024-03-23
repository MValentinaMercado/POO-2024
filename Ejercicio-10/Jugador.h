#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador {
private:
    int velocidad;
    int fuerza;
    string nombre;

public:
    Jugador();
    Jugador(int v, int f, string n);
    ~Jugador();

    int getVelocidad();
    int getFuerza();
    string getNombre();

    void setVelocidad(int v);
    void setFuerza(int f);
    void setNombre(string n);

    void mostrarDatos();
};

#endif

