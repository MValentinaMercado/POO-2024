#include "AdminDB.h"
#include <QCryptographicHash>

AdminDB * AdminDB::instancia = nullptr;

AdminDB::AdminDB()  {
}

AdminDB * AdminDB::getInstancia()  {
    if( instancia == nullptr )  {
        instancia = new AdminDB;
    }
    return instancia;
}

void AdminDB::conectar()  {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Sqlite/DB/base.sqlite");

    if (!db.open()) {
        qDebug() << "Error: no se pudo conectar a la base de datos.";
    } else {
        qDebug() << "La base se encuentra conectada...";
    }
}

bool AdminDB::validarUsuario(const QString &usuario, const QString &clave) {
    QString hashedPassword = QString(QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex());
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", hashedPassword);

    if (query.exec()) {
        if (query.next()) {
            return true;
        }
    } else {
        qDebug() << "Error al validar usuario:" << query.lastError();
    }
    return false;
}
