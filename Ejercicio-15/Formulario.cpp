#include "Formulario.h"

Formulario::Formulario() {
    setWindowTitle("Form");

    lLegajo = new QLabel("Legajo:");
    lNombre = new QLabel("Nombre:");
    lApellido = new QLabel("Apellido:");
    lCaptcha = new QLabel("Captcha:");

    leLegajo = new QLineEdit;
    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    leCaptcha = new QLineEdit;

    pbAlta = new QPushButton("Alta");

    layout = new QGridLayout;
    layout->addWidget(lLegajo, 0, 0);
    layout->addWidget(leLegajo, 0, 1);
    layout->addWidget(lNombre, 1, 0);
    layout->addWidget(leNombre, 1, 1);
    layout->addWidget(lApellido, 2, 0);
    layout->addWidget(leApellido, 2, 1);
    layout->addWidget(lCaptcha, 3, 0);
    layout->addWidget(leCaptcha, 3, 1);
    layout->addWidget(pbAlta, 4, 0, 1, 2);
    setLayout(layout);

    int captchaNumber = QRandomGenerator::global()->bounded(1, 10001);
    lCaptcha->setText(QString::number(captchaNumber));

    connect(pbAlta, SIGNAL(clicked()), this, SLOT(slot_UsuarioForm()));
}

void Formulario::slot_UsuarioForm() {
    bool camposCorrectos = true;

    if (leLegajo->text() != "148569") {
        camposCorrectos = false;
        leLegajo->clear();
    }

    if (leNombre->text() != "Morena") {
        camposCorrectos = false;
        leNombre->clear();
    }

    if (leApellido->text() != "Mercado") {
        camposCorrectos = false;
        leApellido->clear();
    }

    int captchaNumber = lCaptcha->text().toInt();
    int enteredCaptcha = leCaptcha->text().toInt();

    if (enteredCaptcha != captchaNumber) {
        camposCorrectos = false;
        captchaNumber = QRandomGenerator::global()->bounded(1, 10001);
        lCaptcha->setText(QString::number(captchaNumber));
        leCaptcha->clear();
    }

    if (camposCorrectos) {
        // Aquí todos los campos son correctos, puedes cerrar el programa.
        close();
    }
}

