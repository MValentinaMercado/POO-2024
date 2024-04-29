#include "pintura.h"
#include <QApplication>


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Pintura pintura;
    pintura.show();
    return app.exec();
}

