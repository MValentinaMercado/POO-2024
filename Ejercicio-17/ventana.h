#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class ventana; }
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::ventana *ui;
    QNetworkAccessManager * manager;
    QImage image;
    bool se_descargo;

private slots:
    void slot_descargafinalizada(QNetworkReply * reply);
};



#endif // VENTANA_H
