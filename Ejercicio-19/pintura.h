#include <QtWidgets>

class Pintura : public QWidget {
    Q_OBJECT
public:
    Pintura(QWidget* parent = nullptr);
    void ampliarTrazo();
    void cambiarColor() ;
    void borrarTodo();

protected:
    virtual void paintEvent(QPaintEvent* ) ;
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void wheelEvent(QWheelEvent *event);
private:
    int trazo;
    QColor color;
    QImage lienzo;
    QPoint ultimoPunto;
};
