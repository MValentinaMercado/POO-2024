#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class ventana; }
QT_END_NAMESPACE

class ventana : public QWidget
{
    Q_OBJECT

public:
    ventana(QWidget *parent = nullptr);
    ~ventana();

protected:
   void paintEvent(QPaintEvent *);

private slots:
    void imagenDescargada(QNetworkReply *reply);

private:
    Ui::ventana *ui;
    QImage imagenFondo;
    QNetworkAccessManager *manager;
};
#endif // VENTANA_H
