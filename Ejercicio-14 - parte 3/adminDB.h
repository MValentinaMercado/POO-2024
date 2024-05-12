#ifndef ADMINDB_H
#define ADMINDB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QObject>
#include <QDebug>
#include <QCryptographicHash>
#include <QSqlRecord>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    QStringList validarUsuario( QString tabla, QString usuario, QString clave );
    bool validarFormulario( QString tabla, QString nombre, QString apellido, QString mail );

    QVector< QStringList > select( QString comando );

private:
    QSqlDatabase db;

};
#endif // ADMINDB_H
