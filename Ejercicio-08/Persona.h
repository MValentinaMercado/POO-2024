#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad);

    void getDatos(string &nombre, int &edad);
    void setDatos(string nombre, int edad);
};

#endif // PERSONA_H
