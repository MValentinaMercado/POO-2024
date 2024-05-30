#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent),
    adminDB(AdminDB::getInstancia()),
    login(new Login(this)),
    formulario(new Formulario(this)),
    alta(new Alta(this))
{
    connect(login, &Login::signal_MostrarFormulario, this, &Manager::slot_MostrarFormulario);
    connect(login, &Login::signal_MostrarAlta, this, &Manager::slot_MostrarAlta);
    connect(formulario, &Formulario::signal_Volver, this, &Manager::slot_MostrarLogin);
    connect(alta, &Alta::signal_Volver, this, &Manager::slot_MostrarLogin);
}


Manager::~Manager() {
    delete adminDB;
    delete login;
    delete formulario;
    delete alta;
}

void Manager::iniciar() {
    login->show();
}

void Manager::slot_MostrarLogin() {
    formulario->hide();
    alta->hide();
    login->limpiarCampos();
    login->show();
}

void Manager::slot_MostrarFormulario() {
    login->hide();
    formulario->ActualizarDatos(); // Corregir el nombre del método aquí
    formulario->show();
}


void Manager::slot_MostrarAlta() {
    login->hide();
    alta->show();
}
