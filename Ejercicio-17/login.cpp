#include "login.h"
#include "ventana.h"
#include <QDebug>

login::login() {
    setWindowTitle("Login");
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
    pbEntrar = new QPushButton("Entrar");
    layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbEntrar, 2, 1, 1, 1);
    setLayout(layout);

    connect(pbEntrar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(slot_descargaFinalizada(QNetworkReply *)));
    QNetworkRequest request(QUrl("https://th.bing.com/th/id/R.abce8f0d4e845a2bf9fb623772893b9a?rik=IllBhmSbWYY5MQ&riu=http%3a%2f%2f3.bp.blogspot.com%2f-TkbHeMs6L3I%2fUSfK6c8kwqI%2fAAAAAAAA350%2fVXiChaTsrzE%2fs1600%2fEstrellas-de-Colores_Fondos-de-Pantalla-de-Estrellas.jpg&ehk=GGD4nZktyxe8MRThaln9k7lTehXzTh7TuLgpDuflXMs%3d&risl=&pid=ImgRaw&r=0"));
    manager->get(request);
}

void login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        qDebug() << "Usuario Valido";
        Ventana *ventana = new Ventana;
        ventana->setImage(im);
    } else {
        leClave->clear();
    }
}

void login::slot_descargaFinalizada(QNetworkReply *reply) {
    im = QImage::fromData(reply->readAll());
    this->repaint();
}

void login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(0, 0, im.scaled(this->width(), this->height()));
}
