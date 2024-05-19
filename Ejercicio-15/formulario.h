#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QRandomGenerator>

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr);
    ~Formulario();

private:
    Ui::Formulario *ui;

private slots:
    void slot_validarFormulario();

};

#endif // FORMULARIO_H
