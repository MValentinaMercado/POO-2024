// En login.cpp
#include "login.h"

login::login() {
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
    connect(pbMostrarTemperatura, SIGNAL(clicked()), this, SLOT(slot_mostrarOcultarTemperatura())); // Conectar el botón para mostrar/ocultar temperatura

        networkManager = new QNetworkAccessManager(this);
        connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_temperaturaRecibida(QNetworkReply*)));
    QUrl url("http://api.weatherapi.com/v1/current.json?key=23452d788ca74ae5acd154411241604&q=Cordoba&aqi=no");
    QNetworkRequest request(url);
    networkManager->get(request);

    setBackgroundImage("C:/Users/merca/Downloads/ubp.jpg");

    intentosFallidos = 0;
       bloqueoTimer.setSingleShot(true);
       bloqueoTimer.setInterval(300000);

}

void login::setBackgroundImage(const QString &imageUrl) {
    backgroundImageUrl = imageUrl;
    if (!backgroundImageUrl.isEmpty()) {
        QPixmap backgroundImage(backgroundImageUrl);
        QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        this->setPalette(palette);
    }
}

void login::slot_validarUsuario() {
    if (intentosFallidos >= 3) {
        // Si el usuario está bloqueado, no hacer nada
        return;
    }

    if (leUsuario->text() == "admin" && leClave->text() == "1111") {
        close();
        Formulario *formulario = new Formulario();
        formulario->show();
    } else {
        leClave->clear();
        intentosFallidos++;

        if (intentosFallidos >= 3) {
            // Si el usuario falla el tercer intento, bloquearlo y comenzar el temporizador de bloqueo
            pbEntrar->setEnabled(false);
            bloqueoTimer.start();
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

void login::slot_desbloquearUsuario() {
    pbEntrar->setEnabled(true);
    intentosFallidos = 0;
}
