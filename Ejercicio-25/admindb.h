#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QCryptographicHash>

class AdminDB : public QObject {
    Q_OBJECT

private:
    static AdminDB *instancia;
    QSqlDatabase db;

    AdminDB();

public:
    static AdminDB *getInstancia();

    bool validarUsuario(const QString& usuario, const QString& clave);
    bool registrarUsuario(const QString& usuario, const QString& clave);
     bool actualizarUsuario(const QString& usuarioOriginal, const QString& claveOriginal, const QString& nuevoUsuario, const QString& nuevaClave);

};

#endif // ADMINDB_H
