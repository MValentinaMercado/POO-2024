#include "Formulario.h"

Formulario::Formulario() {
    setWindowTitle("Form");
    lLegajo = new QLabel("Legajo:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    pbAlta = new QPushButton("Alta");
    layout = new QGridLayout;
    layout->addWidget(lLegajo, 0, 0);
    layout->addWidget(leLegajo, 0, 1);
    layout->addWidget(lNombre, 1, 0);
    layout->addWidget(leNombre, 1, 1);
    layout->addWidget(lApellido, 2, 0);
    layout->addWidget(leApellido, 2, 1);
    layout->addWidget(pbAlta, 3, 0, 1, 2);
    setLayout(layout);

   connect(pbAlta, SIGNAL(clicked()), this, SLOT(slot_UsuarioForm()));
}

void Formulario::slot_UsuarioForm() {
    if (leLegajo->text() == "148569" && leNombre->text() == "Morena" && leApellido->text() == "Mercado") {
        close();
    }
}


