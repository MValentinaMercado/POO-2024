#include "Galeria.h"
#include <QFile>
#include <QTextStream>

Galeria::Galeria(QWidget *parent)
    : QMainWindow(parent)
{
    layoutPrincipal = new QVBoxLayout;
    imagenLabel = new QLabel;
    anteriorButton = new QPushButton("Anterior");
    siguienteButton = new QPushButton("Siguiente");
    manager = new QNetworkAccessManager(this);

    connect(anteriorButton, &QPushButton::clicked, this, &Galeria::imagenAnterior);
    connect(siguienteButton, &QPushButton::clicked, this, &Galeria::imagenSiguiente);

    layoutPrincipal->addWidget(imagenLabel);
    layoutPrincipal->addWidget(anteriorButton);
    layoutPrincipal->addWidget(siguienteButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layoutPrincipal);
    setCentralWidget(centralWidget);

    cargarImagenesDesdeArchivo();
}

Galeria::~Galeria()
{
    delete layoutPrincipal;
    delete imagenLabel;
    delete anteriorButton;
    delete siguienteButton;
}

void Galeria::cargarImagenesDesdeArchivo()
{
    QFile file("urls.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString url = in.readLine();
        urlsImagenes.append(url);
    }

    file.close();

    indiceImagenActual = 0;
    cargarImagen();
}

void Galeria::cargarImagen()
{
    // Desconectar cualquier conexión previa
    disconnect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));

    QUrl url(urlsImagenes.at(indiceImagenActual));
    QNetworkRequest request(url);
    manager->get(request);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));
}

void Galeria::imagenAnterior()
{
    if (indiceImagenActual > 0) {
        indiceImagenActual--;
        cargarImagen();
    }
}

void Galeria::imagenSiguiente()
{
    if (indiceImagenActual < urlsImagenes.size() - 1) {
        indiceImagenActual++;
        cargarImagen();
    }
}

void Galeria::slot_descargaFinalizada(QNetworkReply *reply)
{
    QByteArray imageData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(imageData);
    imagenLabel->setPixmap(pixmap);
    imagenLabel->setScaledContents(true);
    reply->deleteLater();
}
