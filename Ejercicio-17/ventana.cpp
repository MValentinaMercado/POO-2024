#include "ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent) {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);

    QVBoxLayout *layout = new QVBoxLayout(this);
    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);
    setLayout(layout);
}

void Ventana::setImage(const QImage &image) {
    imageLabel->setPixmap(QPixmap::fromImage(image));
    showFullScreen();
}
