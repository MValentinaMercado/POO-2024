#include "Login.h"
#include "ui_Login.h"
#include "AdminDB.h"

Login * Login::instancia = nullptr;

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->pbIngresar,SIGNAL(clicked()),this,SLOT(slot_conectar()));
}

Login::~Login()
{
    delete ui;
}

Login *Login::getInstancia()
{
    if ( instancia == nullptr )  {
        instancia = new Login;
    }
    return instancia;
}

void Login::slot_conectar(){
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();
    bool valido = AdminDB::getInstancia()->validarUsuario(usuario,clave);
    emit signal_usuarioValido(valido);

}
