#include "login.h"
#include "ventana.h"
#include "ui_login.h"
#include <QPainter>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , manager(new QNetworkAccessManager(this))
    , se_descargo(false)
{
    ui->setupUi(this);
    ui->leClave->setEchoMode(QLineEdit::Password);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargafinalizada(QNetworkReply*)));
    QUrl url("https://i.pinimg.com/564x/2a/f4/4b/2af44b48ec2df06ad86fbb8f05146b35.jpg");
    QNetworkRequest request(url);
    manager->get(request);

    connect(ui->Ingresar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

}

void Login::slot_validarUsuario()
{
    if (ui->leUsuario->text() == "admin" && ui->leClave->text() == "1111" ) {
        qDebug() << "Usuario válido";
        this->close();
        Ventana *ventana = new Ventana;
        ventana->show();

    } else {
        qDebug() << "Usuario no válido";
    }
}

void Login::paintEvent(QPaintEvent *)
{
    if (se_descargo) {
        QPainter painter(this);
        painter.drawImage(0, 0, this->image.scaled(this->size(), Qt::KeepAspectRatio));
    }
}

void Login::slot_descargafinalizada(QNetworkReply *reply)
{
    this->image = QImage::fromData(reply->readAll());
    this->se_descargo = true;
    this->setFixedSize(this->image.size()); // Ajusta el tamaño de la ventana al tamaño de la imagen
    this->repaint();
}

Login::~Login()
{
    delete ui;
    delete manager;
}
