#include "ventana.h"
#include "ui_ventana.h"
#include "login.h"
#include <QPainter>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventana)
    , manager(new QNetworkAccessManager(this))
    , se_descargo(false)
{
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargafinalizada(QNetworkReply*)));
    QUrl url("https://i.pinimg.com/originals/71/8c/9c/718c9cf3612cd820f94ba706a9585698.jpg");
    QNetworkRequest request(url);
    manager->get(request);
}

void Ventana::paintEvent(QPaintEvent *)
{
    if (se_descargo) {
        QPainter painter(this);
        painter.drawImage(0, 0, this->image);
    }
}

void Ventana::slot_descargafinalizada(QNetworkReply *reply)
{
    this->image = QImage::fromData(reply->readAll());
    this->se_descargo = true;
    this->resize(this->image.size()); // Ajusta el tamaño de la ventana al tamaño de la imagen
    this->repaint();
}

Ventana::~Ventana()
{
    delete ui;
    delete manager;
}
