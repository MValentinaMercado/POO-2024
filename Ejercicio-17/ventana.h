#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

class Ventana : public QWidget {
    Q_OBJECT
public:
    explicit Ventana(QWidget *parent = nullptr);
    void setImage(const QImage &image);

private:
    QLabel *imageLabel;
};

#endif // VENTANA_H
