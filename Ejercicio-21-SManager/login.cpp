
#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ventana = new Ventana;
    connect(ventana, SIGNAL(volverLogin()), this, SLOT(slot_mostrarLogin()));

    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

    adminDB = new AdminDB( this );
    if (adminDB->conectar("C:/Sqlite/DB/db.sqlite" )) {
        qDebug() << "La base se abrió bien";
    } else {
        qDebug() << "Error al abrir la base de datos";
    }

}


void Login::slot_validarUsuario()
{

    if ( adminDB->validarUsuario( "usuarios", ui->leUsuario->text(), ui->leClave->text() ) )  {
        this->close();
        ventana->show();
        qDebug() << "Usuario válido";
    }
    else  {
        this->close();
        qDebug() << "Usuario no válido";
    }
}

void Login::slot_mostrarLogin()
{
    this->show();
    ventana->close();


}

Login::~Login()
{
    delete ui;
}
