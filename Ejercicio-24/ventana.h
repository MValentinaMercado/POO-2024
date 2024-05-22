#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QFileDialog>
#include <QPainter>
#include <QImage>
#include "parser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ventana; }
QT_END_NAMESPACE

class ventana : public QWidget {
    Q_OBJECT
public:
    explicit ventana(QWidget *parent = nullptr);
    ~ventana();

private slots:
    void UrlIngresada();
    void Imagen();
    void DError(QString errorString);

protected:
    void paintEvent(QPaintEvent * );

private:
    Ui::ventana *ui;
    Parser *parser;
    QImage imagen;
    QString DDirectorio;
};

#endif // VENTANA_H
