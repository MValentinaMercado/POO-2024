#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "adminDB.h"
namespace Ui {
class Formulario;
}

class Formulario : public QWidget {
    Q_OBJECT
private:
     Ui::Formulario *ui;
    AdminDB *adminDB;

public:
     Formulario(AdminDB *adminDB);

private slots:
     void slot_validarFormulario();

};

#endif // FORMULARIO_H
