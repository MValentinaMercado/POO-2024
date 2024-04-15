#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

class Ventana : public QWidget {
    Q_OBJECT

public:
    Ventana() {}

protected:
    void paintEvent(QPaintEvent *);

};

#endif // VENTANA_H
