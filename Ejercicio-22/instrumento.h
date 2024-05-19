#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QString>
#include <QDebug>

class Instrumento { // clase base de instrumentos
public:
    Instrumento(QString marca = "Yamaha");
    virtual ~Instrumento();

    virtual void sonar() = 0; //funcion virtual pura
    virtual void verlo();//virtual por defecto

protected:
    QString marca;
};

#endif // INSTRUMENTO_H
