#include "login.h"

login::login() {
    setWindowTitle("Login");
    resize(250,150);
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);//agregamos EchoMode para los asteriscos
    pbIngresar = new QPushButton("Ingresar");
    layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbIngresar, 2, 1, 1, 1);
    setLayout(layout);

    connect(pbIngresar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));

    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    //conectamos returnPressed() para que cuando estemos en el campo de la clave
    //y le presionemos al enter simule la pulsacion del boton de entrada

}

void login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "123") {
        close();
       Editor *editor = new Editor;
       editor->show();
    }else {
        leClave->clear();

    }
}
