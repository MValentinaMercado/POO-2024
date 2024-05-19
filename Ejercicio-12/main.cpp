#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label;
    QPixmap imagen;
    imagen.load("C:/Users/merca/Documents/U/ubp/SEMESTRE 5/POO/EJERCICIOS/Ejercicio-12/6c01b5589fd30cd9ceda9b12386ea1e8.jpg");
    label.setPixmap(imagen);
    label.resize(imagen.size());
    label.show();

    QTimer::singleShot(3000, [&app](){
        app.quit();
    });
    int valor_para_retornar = app.exec();  // Se le pasa el control a Qt
    return valor_para_retornar;
    //return app.exec();
}
