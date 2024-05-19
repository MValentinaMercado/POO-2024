#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("QLabel");
    QWidget widget;
    QPushButton button("QPushButton");
    QLineEdit lineEdit;

    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    int valor_para_retornar = app.exec();  // Se le pasa el control a Qt
    return valor_para_retornar;
    //return app.exec();
}
