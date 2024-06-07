#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>
#include "instrumento.h"
#include "guitarra.h"
#include "viento.h"
#include "teclado.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Formulario; }
QT_END_NAMESPACE

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);
    ~Formulario();

private slots:
    void slot_agregar();
    void slot_verStock();
    void slot_tipoInstrumento(int index);

private:
    Ui::Formulario *ui;
    QVector<Instrumento*> instrumentos;
};

#endif // FORMULARIO_H
