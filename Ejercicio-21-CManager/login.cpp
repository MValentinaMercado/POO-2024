#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(on_leClave_returnPressed()));
}

Login::~Login()
{
    delete ui;
}

QString Login::getUsuario()
{
    return ui->leUsuario->text();
}

QString Login::getClave()
{
    return ui->leClave->text();
}

void Login::on_leClave_returnPressed()
{
    emit validarUsuario();
}
