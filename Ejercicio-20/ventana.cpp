#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>


ventana::ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventana){

    ui->setupUi(this);
    ui->Boton1->setTexto("Mi Dentista");
    ui->Boton1->setColor(Boton::ROJO);
    ui->Boton2->setTexto("Visistas");
    ui->Boton2->setColor(Boton::MAGENTA);
    ui->Boton3->setTexto("Tecnicas de Higene");
    ui->Boton3->setColor(Boton::MORADO);
    ui->Boton4->setTexto("Mi Boca");
    ui->Boton4->setColor(Boton::AZUL);
    ui->Boton5->setTexto("Hora de Cepillarse");
    ui->Boton5->setColor(Boton::VERDE);


    connect(ui->Boton1,SIGNAL(signal_click()),(this),SLOT(close()));
    connect(ui->Boton2,SIGNAL(signal_click()),(this),SLOT(close()));
    connect(ui->Boton3,SIGNAL(signal_click()),(this),SLOT(close()));
    connect(ui->Boton4,SIGNAL(signal_click()),(this),SLOT(close()));
    connect(ui->Boton5,SIGNAL(signal_click()),(this),SLOT(close()));

    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(imagenDescargada(QNetworkReply*)));
    QUrl url("https://i.pinimg.com/originals/11/c0/10/11c010d71f4e519b54878a8dab506f52.jpg");
    QNetworkRequest request(url);
    manager->get(request);

}

ventana::~ventana()
{
    delete ui;
}

void ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, imagenFondo.scaled(this->size()));
}

void ventana::imagenDescargada(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray imageData = reply->readAll();
        imagenFondo.loadFromData(imageData);
        update();
    } else {
        qDebug() << "Error al descargar la imagen:" << reply->errorString();
    }
    reply->deleteLater();
}
