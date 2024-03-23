#ifndef POSTE_H
#define POSTE_H
class Poste  {
private:
    int altura;
    int seccion;

public:
    Poste( int altura, int seccion );

    void getDatos( int & altura, int & seccion );
    void setDatos( int altura, int seccion );
};

#endif // POSTE_H
