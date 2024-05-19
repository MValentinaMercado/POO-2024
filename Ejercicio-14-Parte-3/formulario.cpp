#include "formulario.h"
#include "ui_formulario.h"
#include <QDebug>

Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);
     connect(ui->Alta, SIGNAL(clicked()), this, SLOT(slot_validarFormulario()));
}
void Formulario::slot_validarFormulario()
{
    if (ui->leLegajo->text() == "148965" && ui->leNombre->text() == "Morena" && ui->leApellido->text() == "Mercado" ) {
        qDebug() << "Usuario válido";
        this->close();

    } else {
        qDebug() << "Usuario no válido";
    }
}
Formulario::~Formulario()
{
    delete ui;
}
