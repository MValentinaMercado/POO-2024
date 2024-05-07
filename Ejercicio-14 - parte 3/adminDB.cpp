#include "adminDB.h"

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );//conectamos al archivo de base de datos

    if( db.open() )//abrimos la conexion
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    if ( db.open() )  {
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" +
                                   usuario + "' AND clave = '" + clave + "'" );

        while( query.next() )  {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }

    return false;
}

bool AdminDB::validarFormulario(QString tabla, QString nombre, QString apellido, QString mail)
{
    if (db.open()) {
        QSqlQuery query = db.exec("SELECT nombre, apellido FROM " + tabla + " WHERE nombre = '" +
                                  nombre + "' AND apellido = '" + apellido + "' AND mail = '" + mail + "'");

        while (query.next()) {
            qDebug() << query.value(0).toString() << " " << query.value(1).toString();
            return true;
        }
    }

    return false;
}


