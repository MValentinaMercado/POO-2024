#include "Formulario.h"
#include <QDebug>

Formulario::Formulario(AdminDB *adminDB) : adminDB(adminDB)  {
    setWindowTitle("Formulario");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    lMail = new QLabel("Mail:");
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    leMail = new QLineEdit;
    pbAlta = new QPushButton("Alta");
    layout = new QGridLayout;
    layout->addWidget(lNombre, 0, 0);
    layout->addWidget(leNombre, 0, 1);
    layout->addWidget(lApellido, 1, 0);
    layout->addWidget(leApellido, 1, 1);
    layout->addWidget(lMail, 2, 0);
    layout->addWidget(leMail, 2, 1);
    layout->addWidget(pbAlta, 3, 0, 1, 2);
    setLayout(layout);

    qDebug() << "La base se abrio bien" << adminDB->conectar( "C:/Sqlite/DB/base_prueba" );

    connect(pbAlta, SIGNAL(clicked()), this, SLOT(slot_UsuarioForm()));
}


void Formulario::slot_UsuarioForm() {

    //|Carlos|Gomez|cgomez@gmail.com

    if (adminDB->validarFormulario("usuarios", leNombre->text(),leApellido->text(), leMail->text())) {
        // Cerrar la conexión de la base de datos
        adminDB->getDB().close();
        close();
    } else {
        qDebug() << "Formulario no válido";
    }
}


