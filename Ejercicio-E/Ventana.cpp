#include "Ventana.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QRandomGenerator>

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Configuración de la bola");

    bolaLabel = new QLabel;
    QPixmap pixmap("C:/Users/merca/Documents/U/ubp/SEMESTRE 5/POO/EJERCICIOS/Ejercicio-E/bola8.png");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    bolaLabel->setPixmap(pixmap);

    botonActualizar = new QPushButton("Actualizar parámetros");
    connect(botonActualizar, &QPushButton::clicked, this, &Ventana::actualizarParametros);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(bolaLabel);
    layout->addWidget(botonActualizar);
    groupBox->setLayout(layout);

    diametro = 50;
    velocidad = 100;
    posicion = 0;
    direccion = 1;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() {
        posicion += direccion * 10;
        if (posicion <= 0 || posicion >= width() - diametro) {
            direccion *= -1;
        }
        bolaLabel->move(posicion, (height() - diametro) / 2);
    });
    timer->start(velocidad);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(groupBox);
    setLayout(mainLayout);
}


void Ventana::actualizarParametros()
{
    diametro = QRandomGenerator::global()->bounded(50, 151);
    velocidad = QRandomGenerator::global()->bounded(10, 101);
    posicion = QRandomGenerator::global()->bounded(width() - diametro);
    bolaLabel->move(posicion, (height() - diametro) / 2);
    timer->start(velocidad);
}

