#ifndef ADMINDB_H
#define ADMINDB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class AdminDB  {

private:
    static AdminDB *instancia;
    QSqlDatabase db;
    AdminDB();

public:
    static AdminDB * getInstancia();
    void conectar(const QString &databasePath);

};

#endif // ADMINDB_H
