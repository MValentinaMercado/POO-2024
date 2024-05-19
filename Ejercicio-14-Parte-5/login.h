#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QTimer>


#include "adminDB.h"
#include "formulario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget {
    Q_OBJECT
private:
    Ui::login *ui;
    QNetworkAccessManager *networkManager;
    QByteArray imageData;
    QNetworkAccessManager *networkManagerImagen;
    int intentosFallidos;
    QTimer bloqueoTimer;
    AdminDB * adminDB;

public:
      login(QWidget *parent = nullptr);
       void setImagenUrl(const QString &url);

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_validarUsuario();
    void slot_temperaturaRecibida(QNetworkReply *reply);
    void slot_mostrarOcultarTemperatura();
    void slot_desbloquearUsuario();
    void slot_imagenDescargada(QNetworkReply *reply);

signals:
    void signal_usuarioValidado( QString usuario );

};

#endif // LOGIN_H
