#include "mapa.h"
#include <QPainter>
#include <QPixmap>

void Mapa::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawLine(0, 0, this->width(), this->height());

    QPixmap disco("C:/Users/merca/Documents/U/ubp/SEMESTRE 5/POO/Login-mapa/img.png");
    painter.drawPixmap(50, 50, 500, 500, disco);
}
