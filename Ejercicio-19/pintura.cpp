#include <QtWidgets>
#include "pintura.h"

Pintura::Pintura(QWidget* parent) : QWidget(parent) {
    setMaximumSize(800, 600);
    color = Qt::black;
    trazo = 2;
    QSize lienzoSize(800,600);
    lienzo = QImage(lienzoSize, QImage::Format_RGB32);
    QPainter painter(&lienzo);
    painter.fillRect(lienzo.rect(), Qt::white);
}


void Pintura::paintEvent(QPaintEvent* ) {
    QPainter painter(this);
    painter.drawImage(0, 0, lienzo);
}

void Pintura::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        ultimoPunto = event->pos();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent* event) {
    if ((event->buttons() & Qt::LeftButton) && ultimoPunto != QPoint()) {
        QPainter painter(&lienzo);
        painter.setPen(QPen(color, trazo, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(ultimoPunto, event->pos());
        ultimoPunto = event->pos();
        update();
    }
}

void Pintura::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_R) {
        color = Qt::red;
    } else if (event->key() == Qt::Key_G) {
        color = Qt::green;
    }  else if (event->key() == Qt::Key_B) {
        color = Qt::blue;
    }   else if (event->key() == Qt::Key_Escape){
         borrarTodo();
    }
}

void Pintura::wheelEvent(QWheelEvent* event) {
    if (event->angleDelta().y() > 0) {
        ampliarTrazo();
    } else {
        trazo = qMax(1, trazo - 1);
    }
}

void Pintura::ampliarTrazo() {
    trazo++;
}

void Pintura::borrarTodo() {
    QPainter painter(&lienzo);
    painter.fillRect(lienzo.rect(), Qt::white);
    update();
}








