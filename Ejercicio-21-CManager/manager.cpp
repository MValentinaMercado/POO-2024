#include "manager.h"
#include <QDebug>

Manager::Manager(QObject *parent) : QObject(parent)
{
    login = new Login;
    ventana = new Ventana;
    adminDB = new AdminDB(this);

    connect(login, SIGNAL(validarUsuario()), this, SLOT(slot_validarUsuario()));
    connect(ventana, SIGNAL(volverLogin()), this, SLOT(slot_mostrarLogin()));
}

void Manager::iniciar()
{
    if (adminDB->conectar("C:/Sqlite/DB/db.sqlite")) {
        qDebug() << "La base se abrió bien";
    } else {
        qDebug() << "Error al abrir la base de datos";
    }

    login->show();
}

void Manager::slot_validarUsuario()
{
    // cponce, 1234
    if (adminDB->validarUsuario("usuarios", login->getUsuario(), login->getClave())) {
        login->close();
        ventana->show();
        qDebug() << "Usuario válido";
    } else {
        qDebug() << "Usuario no válido";
    }
}

void Manager::slot_mostrarLogin()
{
    ventana->close();
    login->show();
}
