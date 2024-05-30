#include "login.h"
#include "ui_login.h"
#include "manager.h"

Login::Login(Manager *manager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Login), manager(manager)
{
    ui->setupUi(this);
    adminDB = AdminDB::getInstancia();

    // Conexión de la señal signal_pressed de ui->lRegistrarse a la ranura slot_Alta de esta clase (Login)
    connect(ui->lRegistrarse, SIGNAL(signal_pressed()), this, SLOT(slot_Alta()));

    // Conexión de la señal returnPressed de ui->leClave a la ranura slot_IniciarSesion de esta clase (Login)
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_IniciarSesion()));

    // Conexión de la señal clicked de ui->pbIngresar a la ranura slot_IniciarSesion de esta clase (Login)
    connect(ui->pbIngresar, SIGNAL(clicked()), this, SLOT(slot_IniciarSesion()));

}

Login::~Login()
{
    delete ui;
}

void Login::limpiarCampos()
{
    ui->leUsuario->clear();
    ui->leClave->clear();
}

void Login::slot_Alta()
{
    emit signal_MostrarAlta();
}

void Login::slot_IniciarSesion()
{
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();

    if (adminDB->validarUsuario(usuario, clave)) {
        qDebug() << "Inicio de sesión exitoso";
        emit signal_MostrarFormulario();
    } else {
        qDebug() << "Inicio de sesión fallido";
    }
}
