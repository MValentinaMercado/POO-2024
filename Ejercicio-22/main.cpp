#include <QApplication>
#include <QDebug>
#include <QVector>
#include "instrumento.h"
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QVector<Instrumento*> instrumentos;

    //instanciamos los objetos

    instrumentos.push_back(new Guitarra("Fender", 10));
    instrumentos.push_back(new Bateria ("Pearl", 5));
    instrumentos.push_back(new Teclado("Korg", 76, 120));

    for (int i = 0; i < instrumentos.size(); ++i) {
        instrumentos[i]->verlo();
        instrumentos[i]->sonar();
    }

    // Limpiar memoria
    for (int i = 0; i < instrumentos.size(); ++i) {
        delete instrumentos[i];
    }

    return a.exec();
}
