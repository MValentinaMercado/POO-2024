#include "Formulario.h"
#include "ui_Formulario.h"

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->comboInstrumentos->addItems({"Guitarra", "Viento", "Teclado"});

    // Ocultar campos específicos al iniciar
    ui->SpinBoxcuerdas->hide();
    ui->SpinBoxteclas->hide();
    ui->leMetal->hide();
    ui->lcuerdas->hide();
    ui->lteclas->hide();
    ui->lMetal->hide();
    ui->leMarca->hide();
    ui->SpinBoxprecio->hide();
    ui->lMarca->hide();
    ui->lprecio->hide();

    connect(ui->comboInstrumentos, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_tipoInstrumento(int )));
    connect(ui->pbAgregar, SIGNAL(clicked()), this, SLOT(slot_agregar()));
    connect(ui->pbVerStock, SIGNAL(clicked()), this, SLOT(slot_verStock()));
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::slot_agregar()
{
    Instrumento *instrumento = nullptr;
    QString tipo = ui->comboInstrumentos->currentText();

    if (tipo == "Guitarra") {
        Guitarra *guitarra = new Guitarra();
        guitarra->marca = ui->leMarca->text();
        guitarra->precio = ui->SpinBoxprecio->value();
        guitarra->cantidad_de_cuerdas = ui->SpinBoxcuerdas->value();
        instrumento = guitarra;
    } else if (tipo == "Viento") {
        Viento *viento = new Viento();
        viento->marca = ui->leMarca->text();
        viento->precio = ui->SpinBoxprecio->value();
        viento->metal_usado = ui->leMetal->text();
        instrumento = viento;
    } else if (tipo == "Teclado") {
        Teclado *teclado = new Teclado();
        teclado->marca = ui->leMarca->text();
        teclado->precio = ui->SpinBoxprecio->value();
        teclado->cantidad_de_teclas = ui->SpinBoxteclas->value();
        instrumento = teclado;
    }

    if (instrumento) {
        instrumentos.append(instrumento);
        qDebug() << "Instrumento agregado";
    }
}

void Formulario::slot_verStock()
{
    for (auto instrumento : instrumentos) {
        instrumento->afinar();
    }
}

void Formulario::slot_tipoInstrumento(int index)
{



    // Mostrar campos y etiquetas comunes (marca y precio)
    ui->leMarca->show();
    ui->SpinBoxprecio->show();
    ui->lMarca->show();
    ui->lprecio->show();

    // Ocultar todos los campos y etiquetas inicialmente
    ui->SpinBoxcuerdas->hide();
    ui->lcuerdas->hide();
    ui->SpinBoxteclas->hide();
    ui->lteclas->hide();
    ui->lMetal->hide();
    ui->leMetal->hide();


    // Mostrar los campos y etiquetas según el tipo de instrumento seleccionado
    if (index == 0) { // Guitarra
        ui->SpinBoxcuerdas->show();
        ui->lcuerdas->show();
    } else if (index == 1) { // Viento
        ui->leMetal->show();
        ui->lMetal->show();
    } else if (index == 2) { // Teclado
        ui->SpinBoxteclas->show();
        ui->lteclas->show();
    }
}
