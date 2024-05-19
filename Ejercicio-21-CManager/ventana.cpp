#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    connect(ui->Volver, SIGNAL(clicked()), this, SLOT(slot_Volverclicked()));
}

void Ventana::slot_Volverclicked()
{
    emit volverLogin();
}

Ventana::~Ventana()
{
    delete ui;
}
