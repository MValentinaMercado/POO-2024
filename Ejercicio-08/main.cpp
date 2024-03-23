#include <iostream>
#include <string>
#include "Persona.h"
#include "Poste.h"
#include "proyecto.h"

using namespace std;

// Función genérica para imprimir la descripción de cualquier objeto
void imprimirDescripcion(const string& descripcion) {
    cout << descripcion << endl;
}

int main() {
    // Crear objetos de la clase Persona
    Persona persona1("Lucrecia", 25);
    Persona persona2("Juan", 30);

    // Crear objetos de la clase Poste
    Poste poste1(8, 15);
    Poste poste2(10, 20);

    // Obtener datos de las personas
    string nombrePersona1;
    int edadPersona1;
    persona1.getDatos(nombrePersona1, edadPersona1);

    string nombrePersona2;
    int edadPersona2;
    persona2.getDatos(nombrePersona2, edadPersona2);

    // Obtener datos de los postes
    int alturaPoste1, seccionPoste1;
    poste1.getDatos(alturaPoste1, seccionPoste1);

    int alturaPoste2, seccionPoste2;
    poste2.getDatos(alturaPoste2, seccionPoste2);

    // Imprimir descripción de los objetos
    imprimirDescripcion("Persona con nombre " + nombrePersona1 + " y edad " + to_string(edadPersona1));
    imprimirDescripcion("Persona con nombre " + nombrePersona2 + " y edad " + to_string(edadPersona2));

    imprimirDescripcion("Poste con altura de " + to_string(alturaPoste1) + " metros y " + to_string(seccionPoste1) + " cm de diametro");
    imprimirDescripcion("Poste con altura de " + to_string(alturaPoste2) + " metros y " + to_string(seccionPoste2) + " cm de diametro");

    /*cout<<"-.-.-.-.-.-.-.-.-"<<endl;
        string version = proyecto::getVersion();
        cout << version << endl;*/

    return 0;
}
