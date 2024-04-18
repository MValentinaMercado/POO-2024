#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QTimer>
#include <QPushButton>

class Ventana : public QWidget
{
    Q_OBJECT
public:
    Ventana(QWidget *parent = nullptr);

private slots:
    void actualizarParametros();

private:
    QGroupBox *groupBox;
    QLabel *bolaLabel;
    QTimer *timer;
    QPushButton *botonActualizar;
    int diametro;
    int velocidad;
    int posicion;
    int direccion;
};

#endif // VENTANA_H
