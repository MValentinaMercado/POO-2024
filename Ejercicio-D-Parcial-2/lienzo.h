#ifndef LIENZO_H
#define LIENZO_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include "milabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lienzo; }
QT_END_NAMESPACE

class Lienzo : public QWidget {
    Q_OBJECT
public:
    enum GrosorTrazo {
        TrazoFino = 2,
        TrazoMediano = 5,
        TrazoGrueso = 8
    };

    Lienzo(QWidget* parent = nullptr);
    void borrarTodo();
    void setGrosor(GrosorTrazo grosor);

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);

private slots:
    void slot_MiLabel();

private:
    int trazo;
    QColor color;
    QImage lienzo;
    QPoint ultimoPunto;
    bool dibujar;
    Ui::Lienzo *ui;
};
#endif // LIENZO_H
