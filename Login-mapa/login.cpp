#include "login.h"

login::login() {
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");
    leUsuario = new QLineEdit;
    leClave = new QLineEdit;
    pbEntrar = new QPushButton("Entrar");
    layout = new QGridLayout;
    layout->addWidget(lUsuario, 0, 0, 1, 1);
    layout->addWidget(lClave, 1, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 2);
    layout->addWidget(leClave, 1, 1, 1, 2);
    layout->addWidget(pbEntrar, 2, 1, 1, 1);
    setLayout(layout);

    connect(pbEntrar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));

}

void login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234") {
        close();
        Mapa *mapa = new Mapa;
        mapa->show();
    }
}
