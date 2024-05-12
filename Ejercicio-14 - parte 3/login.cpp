#include "login.h"
#include <QPainter>
#include <QUrl>
#include <QDebug>
#include <QNetworkRequest>

login::login(QWidget *parent)
    : QWidget(parent),
      networkManager(new QNetworkAccessManager(this)),
      networkManagerImagen(new QNetworkAccessManager(this)),
      adminDB(new AdminDB(this))
{
    setWindowTitle("Login");
    setFixedSize(400, 300);

    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    lTemperatura = new QLabel("Cargando temperatura...");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
    pbEntrar = new QPushButton("Entrar");
    pbMostrarTemperatura = new QPushButton("Temperatura");
    layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbEntrar, 2, 1, 1, 1);
    layout->addWidget(lTemperatura, 3, 0, 1, 3);
    layout->addWidget(pbMostrarTemperatura, 4, 0, 1, 3);
    setLayout(layout);

    connect(pbEntrar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

    // Conectamos la API
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_temperaturaRecibida(QNetworkReply*)));
    QUrl url("http://api.weatherapi.com/v1/current.json?key=23452d788ca74ae5acd154411241604&q=Cordoba&aqi=no");
    QNetworkRequest request(url);
    networkManager->get(request);
    // conectamos el botón para la temperatura
    connect(pbMostrarTemperatura, SIGNAL(clicked()), this, SLOT(slot_mostrarOcultarTemperatura()));

    // Inicializamos el timer
    intentosFallidos = 0;
    bloqueoTimer.setSingleShot(true);
    bloqueoTimer.setInterval(40000);
    connect(&bloqueoTimer, SIGNAL(timeout()), this, SLOT(slot_desbloquearUsuario()));




    // URL de la imagen
    setImagenUrl("https://th.bing.com/th/id/OIP.wZt12NN-HGUOhWST3INsVAAAAA?rs=1&pid=ImgDetMain");

    qDebug() << "La base se abrió bien" << adminDB->conectar("C:/Sqlite/DB/base_prueba");

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

void login::slot_validarUsuario() {
    //usuario:cgomez
    //clave:1234
    QStringList datosPersonales = adminDB->validarUsuario("usuarios", leUsuario->text(), leClave->text());
    if (!datosPersonales.isEmpty()) {
        //usuario valido
        emit signal_usuarioValidado(leUsuario->text());
        qDebug() << "Usuario valido";
        Formulario *formulario = new Formulario(adminDB);
        formulario->show();
           adminDB->getDB().close();
        this->close();
    } else {
        //usuario no valido
        leClave->clear();
        intentosFallidos++;
        qDebug() << "Usuario no valido";

        if (intentosFallidos >= 3) {
            bloqueoTimer.start();
            disconnect(pbEntrar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
            disconnect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
            pbEntrar->setEnabled(false);
            qDebug() << "Usuario bloqueado";
        }
    }

}

void login::slot_temperaturaRecibida(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Respuesta recibida correctamente";
        QByteArray responseData = reply->readAll();
        qDebug() << "Datos de respuesta:" << responseData;
        QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDocument.object();
        // Cambiamos el acceso al objeto de temperatura según la estructura de la respuesta de WeatherAPI
        QJsonObject currentObject = jsonObject.value("current").toObject();
        double temperatura = currentObject.value("temp_c").toDouble();
        lTemperatura->setText(QString("Temperatura: %1°C").arg(temperatura));
    } else {
        qDebug() << "Error al obtener la temperatura:" << reply->errorString();
        lTemperatura->setText("Error al obtener la temperatura: " + reply->errorString());
    }
    reply->deleteLater();
}

void login::slot_mostrarOcultarTemperatura() {
    lTemperatura->setVisible(!lTemperatura->isVisible());
}

void login::setImagenUrl(const QString &url) {
    QUrl imageUrl(url);
    QNetworkRequest request(imageUrl);
    connect(networkManagerImagen, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_imagenDescargada(QNetworkReply*)));
    networkManagerImagen->get(request);
}

void login::slot_desbloquearUsuario() {
    pbEntrar->setEnabled(true);
    connect(pbEntrar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    intentosFallidos = 0;
}
