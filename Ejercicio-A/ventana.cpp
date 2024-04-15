#include "Ventana.h"
#include <QPainter>
#include <QPixmap>

void Ventana::paintEvent(QPaintEvent *) {
    setWindowTitle("Ventana");
    QPainter painter(this);

    QPixmap disco("D:/Usuario Lab/Descargas/ubp.png");

    int x = (width() - disco.width()) / 2;
    int y = (height() - disco.height()) / 2;

    painter.drawPixmap(x, y, disco);
    QRect rect(x, y, disco.width(), disco.height());
    painter.drawRect(rect);
}
