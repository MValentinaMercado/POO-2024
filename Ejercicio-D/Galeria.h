#ifndef GALERIA_H
#define GALERIA_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Galeria : public QMainWindow
{
    Q_OBJECT

public:
    Galeria(QWidget *parent = nullptr);
    ~Galeria();

private slots:
    void cargarImagenesDesdeArchivo();
    void cargarImagen();
    void imagenAnterior();
    void imagenSiguiente();
    void slot_descargaFinalizada(QNetworkReply *reply);

private:
    QVBoxLayout *layoutPrincipal;
    QLabel *imagenLabel;
    QPushButton *anteriorButton;
    QPushButton *siguienteButton;
    QStringList urlsImagenes;
    int indiceImagenActual;
    QNetworkAccessManager *manager;
};

#endif // GALERIA_H
