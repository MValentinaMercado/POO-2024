#include "login.h"

Editor::Editor() {
    setWindowTitle("Login");
    resize(250,250);

    editar = new QTextEdit;
    buscalinea =new QLineEdit;
    pbuscar = new QPushButton("Buscar");
    resultado = new  QLabel;
    pguardar = new QPushButton("Guardar");
    nArchivo =new QLineEdit;

    layout = new QGridLayout;
    layout->addWidget(editar, 0, 0, 1, 1);
    layout->addWidget(buscalinea, 1, 0, 1, 1);
    layout->addWidget(pbuscar, 2, 0, 1, 1);
    layout->addWidget(resultado, 3, 0, 1, 1);
    layout->addWidget(nArchivo, 4, 0, 1, 1);
    layout->addWidget(pguardar, 5, 0, 1, 1);
    setLayout(layout);

    connect(pbuscar, SIGNAL(clicked()), this, SLOT(slot_buscar()));
    connect(pguardar, SIGNAL(clicked()), this, SLOT(slot_guardar()));

}

void Editor::slot_buscar() {
QString buscatexto=buscalinea->text();
QString text = editar->toPlainText();
int count = text.count(buscatexto);
resultado-> setText(QString::number(count) + " ocurrencias.");
}

void Editor::slot_guardar() {
    QString nombreArchivoTexto = nArchivo->text();
    QString texto = editar->toPlainText();

    QFile file(nombreArchivoTexto);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << texto;
        file.close();
    }
   // close();
}
