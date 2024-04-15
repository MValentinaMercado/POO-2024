#include "login.h"

login::login() {
    setWindowTitle("Login");
    resize(250,120);
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
    layout->addWidget(pbIngresar, 2, 3, 3, 3);
    setLayout(layout);

    intentos=0;

    connect(pbIngresar, SIGNAL(clicked()), this, SLOT(slot_validarUsuario()));

    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
    //conectamos returnPressed() para que cuando estemos en el campo de la clave
    //y le presionemos al enter simule la pulsacion del boton de entrada

}

void login::slot_validarUsuario() {
    if (leUsuario->text() == "44897560" && leClave->text() == "560") {
        close();
        Ventana *ventana = new Ventana;
        ventana->show();
    }else {
        leClave->clear();
        intentos++;
        if(intentos>=3){
            QMessageBox::critical(this,"Error","Vuelve a intentarlo");
            close();
        }
    }
}

