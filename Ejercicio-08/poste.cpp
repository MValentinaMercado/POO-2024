
#include <Poste.h>


Poste::Poste( int altura, int seccion ) : altura( altura ), seccion( seccion )  {

}

void Poste::getDatos( int & altura, int & seccion )  {
    altura = this->altura;
    seccion = this->seccion;
}

void Poste::setDatos( int altura, int seccion )  {
    this->altura = altura;
    this->seccion = seccion;
}
