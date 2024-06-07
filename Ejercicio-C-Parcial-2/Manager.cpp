#include "Manager.h"

Manager::Manager(QObject *parent) : QObject(parent),
                                    ventana(new Ventana),
                                    login(Login::getInstancia()),
                                    admindb(AdminDB::getInstancia())
{
    admindb->conectar();
    connect(login, SIGNAL(signal_usuarioValido(bool)), this, SLOT(slot_ingreso(bool)));
}

void Manager::iniciar()
{
    login->show();
}

void Manager::slot_ingreso(bool valido)
{
    if (valido) {
        login->hide();
        ventana->show();
    } else {
        login->close();
    }
}
