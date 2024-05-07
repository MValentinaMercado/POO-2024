#include <QApplication>
#include "login.h"
#include "adminDB.h"


int main(int argc, char** argv) {
    QApplication a(argc, argv);
    login login;
    login.show();

    return a.exec();
}
