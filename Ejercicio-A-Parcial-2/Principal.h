#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include "linea.h"
#include "admindb.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *);


private:
    Ui::Principal *ui;
    QVector<Linea> lineas;

    void cargarLineasDesdeDB();

};

#endif // PRINCIPAL_H
