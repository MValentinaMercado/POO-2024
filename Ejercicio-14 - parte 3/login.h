#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QTimer>


#include "adminDB.h"
#include "Formulario.h"

class login : public QWidget {
    Q_OBJECT
private:
    QLabel *lUsuario, *lClave, *lTemperatura;
    QLineEdit *leUsuario, *leClave;
    QPushButton *pbEntrar, *pbMostrarTemperatura;
    QGridLayout *layout;
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
