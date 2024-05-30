#include "admindb.h"

AdminDB *AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
}

AdminDB *AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB;
        instancia->db = QSqlDatabase::addDatabase("QSQLITE");
        instancia->db.setDatabaseName("C:/Sqlite/DB/base_datos.db");

        if (!instancia->db.open()) {
            qDebug() << "Error al abrir la base de datos:" << instancia->db.lastError().text();
        } else {
            qDebug() << "Conexión a la base de datos establecida correctamente.";
        }
    }
    return instancia;
}

bool AdminDB::validarUsuario(const QString& usuario, const QString& clave) {
    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
    QSqlQuery query(db);
    query.prepare("SELECT usuario FROM usuarios WHERE usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", claveMd5);
    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}

bool AdminDB::registrarUsuario(const QString& usuario, const QString& clave) {
    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();
    QSqlQuery query(db);
    query.prepare("INSERT INTO usuarios (usuario, clave) VALUES (:usuario, :clave)");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", claveMd5);
    return query.exec();
}

bool AdminDB::actualizarUsuario(const QString& usuarioOriginal, const QString& claveOriginal, const QString& nuevoUsuario, const QString& nuevaClave) {
    QSqlQuery query(db);
    query.prepare("UPDATE usuarios SET usuario = :nuevoUsuario, clave = :nuevaClave WHERE usuario = :usuarioOriginal AND clave = :claveOriginal");
    query.bindValue(":nuevoUsuario", nuevoUsuario);
    query.bindValue(":nuevaClave", nuevaClave);
    query.bindValue(":usuarioOriginal", usuarioOriginal);
    query.bindValue(":claveOriginal", claveOriginal);

    return query.exec();
}
