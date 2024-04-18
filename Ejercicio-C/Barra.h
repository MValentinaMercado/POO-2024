#ifndef BARRA_H
#define BARRA_H

#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QNetworkReply>

class Barra : public QWidget
{
    Q_OBJECT

public:
    Barra(QWidget *parent = nullptr);

private slots:
    void actualizarProgreso(qint64 bytesRecibidos, qint64 bytesTotales);
    void iniciarDescarga();

private:
    QProgressBar *barraProgreso;
    QLabel *etiquetaPorcentaje;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
};

#endif // BARRA_H
