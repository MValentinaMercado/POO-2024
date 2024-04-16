// En login.h
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
#include <QPixmap>
#include <QPalette>
#include <QTimer>
#include "Formulario.h"

class login : public QWidget {
    Q_OBJECT
private:
    QLabel *lUsuario, *lClave, *lTemperatura;
    QLineEdit *leUsuario, *leClave;
    QPushButton *pbEntrar, *pbMostrarTemperatura;
    QGridLayout *layout;
    QNetworkAccessManager *networkManager;
    QString backgroundImageUrl;
    int intentosFallidos;
    QTimer bloqueoTimer;

public:
    login();
    void setBackgroundImage(const QString &imageUrl);

private slots:
    void slot_validarUsuario();
    void slot_temperaturaRecibida(QNetworkReply *reply);
    void slot_mostrarOcultarTemperatura();
    void slot_desbloquearUsuario();
};

#endif // LOGIN_H
