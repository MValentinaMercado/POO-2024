#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admindb.h"

class Manager;

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(Manager *manager, QWidget *parent = nullptr);
    ~Login();
    void limpiarCampos();

signals:
    void signal_MostrarFormulario();
    void signal_MostrarAlta();

private slots:
    void slot_Alta();
    void slot_IniciarSesion();

private:
    Ui::Login *ui;
    AdminDB *adminDB;
    Manager *manager;
};

#endif // LOGIN_H
