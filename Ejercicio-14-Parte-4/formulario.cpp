#include "formulario.h"
#include "ui_formulario.h"
#include <QDebug>

Formulario::Formulario (AdminDB *adminDB) :  ui(new Ui::Formulario) , adminDB(adminDB)
{
    ui->setupUi(this);
     connect(ui->Alta, SIGNAL(clicked()), this, SLOT(slot_validarFormulario()));
     // AdminDB
     if (adminDB->conectar("C:/Sqlite/DB/Base_Original")) {
         qDebug() << "La base se abrió bien";
     } else {
         qDebug() << "Error al abrir la base de datos";
     }
}
void Formulario::slot_validarFormulario()
{
    //|Carlos|Gomez|cgomez@gmail.com
    if (adminDB->validarFormulario("usuarios", ui->leNombre->text() , ui->leApellido->text(), ui->leMail->text() ) ){
        qDebug() << "Usuario válido";
        this->close();
        adminDB->getDB().close();

    } else {
        qDebug() << "Usuario no válido";
    }
}
Formulario::~Formulario()
{
    delete ui;
}
