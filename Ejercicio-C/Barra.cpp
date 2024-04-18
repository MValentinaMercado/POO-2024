#include "Barra.h"
#include <QVBoxLayout>
#include <QNetworkRequest>

Barra::Barra(QWidget *parent) : QWidget(parent)
{
    // Crear la barra de progreso
    barraProgreso = new QProgressBar(this);
    barraProgreso->setMinimum(0);
    barraProgreso->setMaximum(100);

    // Aplicar estilo a la barra de progreso
    QString estilo = "QProgressBar {"
                     "border: 2px solid lightblue;"  // Borde celeste
                     "border-radius: 5px;"            // Borde redondeado
                     "background-color: white;"       // Fondo blanco
                     "}"
                     "QProgressBar::chunk {"
                     "background-color: lightblue;"   // Color celeste
                     "margin: 2px;"                   // Espacio entre la barra y el borde
                     "}";
    barraProgreso->setStyleSheet(estilo);

    // Ocultar el porcentaje
    barraProgreso->setTextVisible(false);

    // Crear la etiqueta para mostrar el porcentaje
    etiquetaPorcentaje = new QLabel(this);
    etiquetaPorcentaje->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    etiquetaPorcentaje->setStyleSheet("color: lightblue;"); // Color de texto celeste

    // Crear el layout y añadir la barra de progreso y la etiqueta
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(barraProgreso);
    layout->addWidget(etiquetaPorcentaje);

    setLayout(layout);

    // Iniciar la descarga
    iniciarDescarga();
}

void Barra::iniciarDescarga()
{
    manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://th.bing.com/th/id/OIP.59ODqd23GHrf4WIRAFWxIQHaE7?w=283&h=189&c=7&r=0&o=5&dpr=1.3&pid=1.7"));
    reply = manager->get(request);

    connect(reply, &QNetworkReply::downloadProgress, this, &Barra::actualizarProgreso);
}

void Barra::actualizarProgreso(qint64 bytesRecibidos, qint64 bytesTotales)
{
    if (bytesTotales > 0) {
        int porcentaje = static_cast<int>((bytesRecibidos * 100) / bytesTotales);
        barraProgreso->setValue(porcentaje);
        etiquetaPorcentaje->setText(QString("%1%").arg(porcentaje));
    }
}
