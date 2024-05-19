#include "login.h"
#include "ui_login.h"
#include "formulario.h"
#include "adminDB.h"
#include <QPainter>
#include <QUrl>
#include <QDebug>
#include <QNetworkRequest>

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
    , networkManager(new QNetworkAccessManager(this))
    , networkManagerImagen(new QNetworkAccessManager(this))
    , adminDB(new AdminDB(this))

{
    ui->setupUi(this);
    ui->leClave->setEchoMode(QLineEdit::Password);

    connect(ui->Ingresar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

    //api
    connect(ui->Temperatura, SIGNAL(clicked()), this, SLOT(slot_mostrarOcultarTemperatura()));
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_temperaturaRecibida(QNetworkReply*)));
    QUrl url("http://api.weatherapi.com/v1/current.json?key=23452d788ca74ae5acd154411241604&q=Cordoba&aqi=no");
    QNetworkRequest request(url);
    networkManager->get(request);

    // Inicialización del timer para el bloqueo
    connect(&bloqueoTimer, SIGNAL(timeout()), this, SLOT(slot_desbloquearUsuario()));
    intentosFallidos = 0;


    // imagen
    setImagenUrl("https://i.pinimg.com/originals/33/e0/5b/33e05b7be71b432630bc8eef534e4db1.jpg");

    // AdminDB
    if (adminDB->conectar("C:/Sqlite/Base_MD5" )) {
        qDebug() << "La base se abrió bien";
    } else {
        qDebug() << "Error al abrir la base de datos";
    }

}


void login::slot_validarUsuario() {
    if (intentosFallidos >= 3) {
        return;
    }
    QStringList datosPersonales = adminDB->validarUsuario("usuarios", ui->leUsuario->text(), ui->leClave->text());
    // usuario: jlopez
    // clave: 1234 / 81dc9bdb52d04dc20036dbd8313ed055
    if (!datosPersonales.isEmpty()) {
        emit signal_usuarioValidado(ui->leUsuario->text());
        qDebug() << "Usuario válido";
        this->close();
        Formulario *form = new Formulario(adminDB);
        form->show();
        adminDB->getDB().close();
    } else {
        ui->leClave->clear();
        qDebug() << "Usuario no válido";
        intentosFallidos++;

        if (intentosFallidos >= 3) {
            ui->Ingresar->setEnabled(false);
            bloqueoTimer.start(300000); // 5 minutos
        }
    }

}


void login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    if (!imageData.isEmpty()) {
        QImage imagenFondo;
        imagenFondo.loadFromData(imageData);
        painter.drawImage(0, 0, imagenFondo.scaled(size()));
    }
}

void login::slot_imagenDescargada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Imagen descargada correctamente";
        imageData = reply->readAll();
        update();
    } else {
        qDebug() << "Error al descargar la imagen:" << reply->errorString();
    }
    reply->deleteLater();
}

void login::slot_temperaturaRecibida(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Respuesta recibida correctamente";
        QByteArray responseData = reply->readAll();
        qDebug() << "Datos de respuesta:" << responseData;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();
        QJsonObject currentObject = jsonObject.value("current").toObject();
        double temperatura = currentObject.value("temp_c").toDouble();
        ui->lTemperatura->setText(QString("Temperatura: %1°C").arg(temperatura));
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
        ui->lTemperatura->setText("Error al obtener la temperatura: " + reply->errorString());
    }
    reply->deleteLater();
}

void login::slot_mostrarOcultarTemperatura() {
    ui->lTemperatura->setVisible(!ui->lTemperatura->isVisible());
}

void login::setImagenUrl(const QString &url) {
    QUrl imageUrl(url);
    QNetworkRequest request(imageUrl);
    connect(networkManagerImagen, &QNetworkAccessManager::finished, this, &login::slot_imagenDescargada);
    networkManagerImagen->get(request);
}


void login::slot_desbloquearUsuario() {
    ui->Ingresar->setEnabled(true);
    intentosFallidos = 0;
}


