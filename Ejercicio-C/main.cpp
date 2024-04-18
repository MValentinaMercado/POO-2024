#include <QApplication>
#include "Barra.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Barra barra;

    barra.show();

    return a.exec();
}
