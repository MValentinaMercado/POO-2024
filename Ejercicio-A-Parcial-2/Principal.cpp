#include "Principal.h"
#include "ui_Principal.h"
#include <QSqlError>
#include <QDebug>
#include <QPainter>

Principal::Principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    cargarLineasDesdeDB();
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cargarLineasDesdeDB()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query("SELECT x_inicial, y_inicial, x_final, y_final FROM lineas", db);

    if (!query.exec()) {
        qDebug() << "Error al realizar la consulta:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int x_inicial = query.value(0).toInt();
        int y_inicial = query.value(1).toInt();
        int x_final = query.value(2).toInt();
        int y_final = query.value(3).toInt();

        Linea linea(x_inicial, y_inicial, x_final, y_final);
        lineas.append(linea);
    }

    qDebug() << "Lineas cargadas desde la base de datos:" << lineas.size();
}

void Principal::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for (const Linea &linea : lineas) {
        painter.drawLine(linea.getXInicial(), linea.getYInicial(),
                         linea.getXFinal(), linea.getYFinal());
    }
}
