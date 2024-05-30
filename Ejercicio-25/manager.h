#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "admindb.h"
#include "login.h"
#include "formulario.h"
#include "alta.h"

class Manager : public QObject {
    Q_OBJECT

public:
    explicit Manager(QObject *parent = nullptr);
    ~Manager();

    void iniciar();

private:
    AdminDB *adminDB;
    Login *login;
    Formulario *formulario;
    Alta *alta;

private slots:
    void slot_MostrarLogin();
    void slot_MostrarFormulario();
    void slot_MostrarAlta();
};

#endif // MANAGER_H
