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
    if (ui->leUsuario->text() == "admin" && ui->leClave->text() == "1111" ) {
        qDebug() << "Usuario válido";
        this->close();
        Formulario *form = new Formulario;
        form->show();

    } else {
        ui->leClave->clear();
        qDebug() << "Usuario no válido";

    }
}

login::~login()
{
    delete ui;
}

