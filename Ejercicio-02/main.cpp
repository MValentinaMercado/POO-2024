#include <QCoreApplication>
#include <QDebug>
#include <QLibrary>
#include <iostream>

typedef void (*PrintMessageFunc)();

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

   // QLibrary library("C:/Users/merca/Downloads/Ejercicio-02/MyLibrary.dll");//ruta directa
    QLibrary library("MyLibrary");

       if (!library.load()) {
           qDebug() << "No se pudo cargar la biblioteca:" << library.errorString();
           qDebug() << "Ruta buscada:" << qgetenv("PATH");
           return -1;
       }

       PrintMessageFunc printMessage = (PrintMessageFunc) library.resolve("printMessage");
       if (printMessage) {
           printMessage();
       } else {
           qDebug() << "No se pudo resolver la función printMessage";
       }

       return a.exec();
   }
