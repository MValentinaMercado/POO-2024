#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include "formulario.h"

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    ui->leClave->setEchoMode(QLineEdit::Password);

    connect(ui->Ingresar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
}

void login::slot_validarUsuario()
{
    if (ui->leUsuario->text() == "admin" ) {
        qDebug() << "Usuario válido";
        slot_validarClave();

    } else {
        ui->leUsuario->clear();
        qDebug() << "Usuario no válido";

    }
}

void login::slot_validarClave() {
    if (ui->leClave->text() == "1111") {
        close();
        Formulario *formulario = new Formulario();
        formulario->show();
    }else {
        ui->leClave->clear();
    }
}

login::~login()
{
    delete ui;
}

