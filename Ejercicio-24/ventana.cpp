#include "ventana.h"
#include "ui_ventana.h"

ventana::ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventana)
    , parser(new Parser(this))
{
    ui->setupUi(this);

    connect(ui->Buscar, SIGNAL(clicked()), this, SLOT(UrlIngresada()));
    connect(ui->seleccuinarImagen, SIGNAL(clicked()), this, SLOT(Imagen()));
    connect(parser, SIGNAL(errorDescarga(QString)), this, SLOT(DError(QString)));
}

ventana::~ventana() {
    delete ui;
}

void ventana::UrlIngresada() {
    QUrl url = QUrl(ui->leUrl->text());
    DDirectorio = QFileDialog::getExistingDirectory(this, tr("Seleccione el directorio para descargar los recursos"));
    if (!DDirectorio.isEmpty()) {
        parser->HtmlDesdeUrl(url, DDirectorio);
    }
}

void ventana::DError(QString errorString) {
      qDebug() << "Error al descargar el HTML: " << errorString;
}

void ventana::Imagen() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Seleccione una imagen"), "", tr("Imágenes (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        imagen.load(fileName);
        update();
    }
}

void ventana::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    if (!imagen.isNull()) {
        QImage imagenEscalada = imagen.scaled(rect().size(), Qt::KeepAspectRatio);
        painter.drawImage(rect(), imagenEscalada);
    }
}
