#include "formulario.h"
#include "ui_formulario.h"
#include <QDebug>

Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);
     connect(ui->Alta, SIGNAL(clicked()), this, SLOT(slot_validarFormulario()));
     int captchaNumber = QRandomGenerator::global()->bounded(1, 10001);
     ui->lCaptcha->setText(QString::number(captchaNumber));
}
void Formulario::slot_validarFormulario()
{
    bool camposCorrectos = true;

    if (ui->leLegajo->text() != "148569") {
        camposCorrectos = false;
        ui->leLegajo->clear();
    }

    if (ui->leNombre->text() != "Morena") {
        camposCorrectos = false;
        ui->leNombre->clear();
    }

    if (ui->leApellido->text() != "Mercado") {
        camposCorrectos = false;
        ui->leApellido->clear();
    }

    int captchaNumber = ui->lCaptcha->text().toInt();
    int enteredCaptcha = ui->leCaptcha->text().toInt();

    if (enteredCaptcha != captchaNumber) {
        camposCorrectos = false;
        captchaNumber = QRandomGenerator::global()->bounded(1, 10001);
        ui->lCaptcha->setText(QString::number(captchaNumber));
        ui->leCaptcha->clear();
    }

    if (camposCorrectos) {
        // Aquí todos los campos son correctos, puedes cerrar el programa.
        close();
    }
}
Formulario::~Formulario()
{
    delete ui;
}
