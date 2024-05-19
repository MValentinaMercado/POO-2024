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

QStringList AdminDB::validarUsuario(QString tabla, QString usuario, QString clave) {
    QStringList datosPersonales;

    if (!db.isOpen())
        return datosPersonales;

    QSqlQuery query(db);
    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();

    query.exec("SELECT nombre, apellido FROM " +
               tabla + " WHERE usuario = '" + usuario +
               "' AND clave = '" + claveMd5 + "'");

    while (query.next()) {
        QSqlRecord registro = query.record();

        datosPersonales << query.value(registro.indexOf("nombre")).toString();
        datosPersonales << query.value(registro.indexOf("apellido")).toString();
    }

    return datosPersonales;
}


bool AdminDB::validarFormulario(QString tabla, QString nombre, QString apellido, QString mail)
{
    if (db.open()) {
        QSqlQuery query = db.exec("SELECT nombre, apellido, mail FROM " + tabla +
                                  " WHERE nombre = '" + nombre + "' AND apellido = '" + apellido +
                                  "' AND mail = '" + mail + "'");

        while (query.next()) {
            qDebug() << "Nombre:" << query.value(0).toString() << ", Apellido:" << query.value(1).toString()
                     << ", Mail:" << query.value(2).toString();
            return true;
        }
    }

    return false;
}

/**
 * @brief Método que ejecuta una consulta SQL a la base de datos que ya se encuentra conectado.
          Utiliza QSqlQuery para ejecutar la consulta, con el método next() se van extrayendo
          los registros que pueden ser analizados con QSqlRecord para conocer la cantidad de
          campos por registro.
 * @param comando es una consulta como la siguiente: SELECT nombre, apellido, id FROM usuarios
 * @return Devuelve un QVector donde cada elemento es un registro, donde cada uno de estos registros
           están almacenados en un QStringList que contiene cada campo de cada registro.
 */
QVector<QStringList> AdminDB::select(QString comando) {
    QVector<QStringList> registros;

    if (!db.isOpen())
        return registros;

    QSqlQuery query(db);
    query.exec(comando);

    while (query.next()) {
        QSqlRecord registro = query.record();
        QStringList campos;

        for (int i = 0; i < registro.count(); ++i) {
            campos << query.value(i).toString();
        }

        registros << campos;
    }

    return registros;
}
