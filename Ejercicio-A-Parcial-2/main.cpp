#include "Principal.h"
#include "admindb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AdminDB::getInstancia()->conectar("C:/Sqlite/DB/lineas.db");

    Principal p;
    p.show();

    return a.exec();
}
