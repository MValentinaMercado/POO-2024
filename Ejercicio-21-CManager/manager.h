#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "login.h"
#include "ventana.h"
#include "admindb.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    Manager(QObject *parent = nullptr);
    void iniciar();

private:
    Login *login;
    Ventana *ventana;
    AdminDB *adminDB;

private slots:
    void slot_validarUsuario();
    void slot_mostrarLogin();
};

#endif // MANAGER_H
