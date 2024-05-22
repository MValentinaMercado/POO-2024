#include "ventana.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    //https://es.wikipedia.org/wiki/Revoluci%C3%B3n_de_Mayo (solo imagenenes)
    //https://www.anipedia.net/gatos/ (todos los tipos de archivos)
    QApplication a(argc, argv);
    ventana w;
    w.show();
    return a.exec();
}
