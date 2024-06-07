#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QVector>

#include "AdminDB.h"
#include "Login.h"
#include "Ventana.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager( QObject * parent = 0 );

    void iniciar();

private:
    Ventana * ventana;
    Login * login;
    AdminDB * admindb;

private slots:
    void slot_ingreso( bool valido );

};

#endif // MANAGER_H
