#include "login.h"
#include "HTML.h"
#include <QDebug>

login::login() {
    setWindowTitle("Login");
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    leClave->setEchoMode(QLineEdit::Password);
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
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        qDebug() << "Usuario Valido";
        Html *HTML = new Html;
        HTML->show();
    } else {
        leClave->clear();
    }
}
