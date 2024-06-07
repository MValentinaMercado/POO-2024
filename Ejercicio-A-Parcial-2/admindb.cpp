#include "admindb.h"
#include <QDebug>

AdminDB * AdminDB::instancia = nullptr;

AdminDB::AdminDB()  {
}

AdminDB * AdminDB::getInstancia()  {
    if( instancia == nullptr )  {
        instancia = new AdminDB;
    }
    return instancia;
}

void AdminDB::conectar(const QString &databasePath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath);

    if (!db.open()) {
        qDebug() << "Error: No se pudo conectar a la base de datos.";
        qDebug() << db.lastError().text();
    } else {
        qDebug() << "La base se encuentra conectada...";
    }
}
