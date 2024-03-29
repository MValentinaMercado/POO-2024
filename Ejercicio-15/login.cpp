#include "login.h"

login::login() {
    setWindowTitle("Login");
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);//agregamos EchoMode para los asteriscos
    pbEntrar = new QPushButton("Entrar");
    layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbEntrar, 2, 1, 1, 1);
    setLayout(layout);

    connect(pbEntrar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));

    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

}

void login::slot_validarUsuario() {
    if (leUsuario->text() == "admin") {
       slot_validarClave();
    }else {
        leUsuario->clear();
    }
}
void login::slot_validarClave() {
    if (leClave->text() == "1111") {
        close();
        Formulario *formulario = new Formulario();
        formulario->show();
    }else {
        leClave->clear();
    }
}


