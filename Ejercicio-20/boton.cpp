#include "boton.h"
#include "ui_boton.h"
#include <QPainter>
#include <QColor>

Boton::Boton( QWidget * parent ) : QWidget( parent ),
    ui( new Ui::Boton ),
    color( BLANCO )
{
    ui->setupUi(this);
}

Boton::~Boton()
{
    delete ui;
}

void Boton::setTexto(QString texto)
{
    ui->lTexto->setText( texto );
}

void Boton::setColor( Color color )
{
    this->color = color;
    this->repaint();
}

void Boton::mousePressEvent(QMouseEvent *e)
{
    if ( e->button() == Qt::LeftButton )  {
        emit signal_click();
    }
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    switch (color) {
    case BLANCO:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 255, 255,60));
        break;
    case ROJO:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 0, 0,60));
        break;
    case MAGENTA:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 0, 255,60));
        break;
    case MORADO:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(128, 0, 128,60));
        break;
    case AZUL:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(0, 0, 255,60));
        break;
    case VERDE:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(0, 255, 0,60));
        break;
    default:
        painter.fillRect(0, 0, this->width(), this->height(), QColor(255, 255, 255,60));
        break;
    }
}


