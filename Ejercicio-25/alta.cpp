#include "alta.h"
#include "ui_alta.h"
#include "manager.h"

Alta::Alta(Manager *manager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Alta), manager(manager)
{
    ui->setupUi(this);
    adminDB = AdminDB::getInstancia();

    connect(ui->pbAlta,SIGNAL (clicked()), this, SLOT (slot_Registrar()));
    connect(ui->pbAlta,SIGNAL (clicked()), this, SLOT (slot_Volver()));
    connect(ui->leClave,SIGNAL (returnPressed()), this, SLOT (slot_Registrar()));
}

Alta::~Alta()
{
    delete ui;
}

void Alta::slot_Volver()
{
    emit signal_Volver();
}

void Alta::slot_Registrar()
{
    QString usuario = ui->leUsuario->text();
    QString clave = ui->leClave->text();

    if (adminDB->registrarUsuario(usuario, clave)) {
        qDebug() << "Usuario registrado exitosamente";
        emit signal_Volver();
    } else {
        qDebug() << "Error al registrar usuario";
    }
}
