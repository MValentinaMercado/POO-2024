#include "Jugador.h"
#include <vector>

using namespace std;

int main() {
    vector<Jugador> jugadores;

    jugadores.push_back(Jugador(10, 5, "Juan"));
    jugadores.push_back(Jugador(2, 9, "Maria"));
    jugadores.push_back(Jugador(6, 9, "Luis"));
    jugadores.push_back(Jugador(7, 8, "Ana"));
    jugadores.push_back(Jugador(9, 6, "Pedro"));
    jugadores.push_back(Jugador(5, 10, "Laura"));
    jugadores.push_back(Jugador(4, 9, "Carlos"));
    jugadores.push_back(Jugador(5, 8, "Sofía"));
    jugadores.push_back(Jugador(6, 7, "Diego"));
    jugadores.push_back(Jugador(8, 10, "Elena"));

    for (auto& jugador : jugadores) {
        jugador.mostrarDatos();
    }


    return 0;
}
