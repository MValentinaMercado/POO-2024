#include "lienzo.h"
#include "ui_lienzo.h"


Lienzo::Lienzo(QWidget* parent) : QWidget(parent), dibujar(false) {
    ui->setupUi(this);
    color = Qt::black;
    trazo = TrazoFino;
    QSize lienzoSize(800, 600);
    lienzo = QImage(lienzoSize, QImage::Format_RGB32);
    QPainter painter(&lienzo);
    painter.fillRect(lienzo.rect(), Qt::white);

    connect(ui->lBorrar, SIGNAL(signal_pressed()), this, SLOT(slot_MiLabel()));
}

void Lienzo::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0, 0, lienzo);
}

void Lienzo::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && dibujar) {
        ultimoPunto = event->pos();
    }
}

void Lienzo::mouseMoveEvent(QMouseEvent* event) {
    if (dibujar && ultimoPunto != QPoint()) {
        QPainter painter(&lienzo);
        painter.setPen(QPen(color, trazo, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(ultimoPunto, event->pos());
        ultimoPunto = event->pos();
        update();
    }
}

void Lienzo::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
    case Qt::Key_A:
        dibujar = true;
        break;
    case Qt::Key_D:
        dibujar = false;
        break;
    case Qt::Key_R:
        color = Qt::red;
        break;
    case Qt::Key_G:
        color = Qt::green;
        break;
    case Qt::Key_B:
        color = Qt::blue;
        break;
    case Qt::Key_V:
        color = Qt::black;
        break;
    case Qt::Key_Escape:
        borrarTodo();
        break;
    case Qt::Key_1:
        setGrosor(TrazoFino);
        break;
    case Qt::Key_2:
        setGrosor(TrazoMediano);
        break;
    case Qt::Key_3:
        setGrosor(TrazoGrueso);
        break;
    }
}

void Lienzo::borrarTodo() {
    QPainter painter(&lienzo);
    painter.fillRect(lienzo.rect(), Qt::white);
    update();
}

void Lienzo::setGrosor(GrosorTrazo grosor) {
    trazo = grosor;
}

void Lienzo::slot_MiLabel() {
    borrarTodo();
}

