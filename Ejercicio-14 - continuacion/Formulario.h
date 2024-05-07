#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "adminDB.h"

class Formulario : public QWidget {
    Q_OBJECT
private:
    QLabel  *lNombre, *lApellido, *lMail;
    QLineEdit *leNombre, *leApellido, *leMail;
    QPushButton *pbAlta;
    QGridLayout *layout;
    AdminDB *adminDB;

public:
    Formulario();

private slots:
    void slot_UsuarioForm();

};

#endif // FORMULARIO_H
