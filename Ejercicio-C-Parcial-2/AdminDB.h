#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>

#include <QSqlQuery>

#include <QSqlError>

#include <QDebug>

class AdminDB  {

private:
    static AdminDB * instancia;
    QSqlDatabase db;
    AdminDB();

public:
    static AdminDB * getInstancia();
    void conectar();
    bool validarUsuario(const QString &usuario, const QString &clave);
};

#endif // ADMINDB_H
