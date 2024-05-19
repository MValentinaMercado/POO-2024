#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include "adminDB.h"

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario (AdminDB *adminDB);
    ~Formulario();

private:
    Ui::Formulario *ui;
    AdminDB *adminDB;

private slots:
    void slot_validarFormulario();

};

#endif // FORMULARIO_H
