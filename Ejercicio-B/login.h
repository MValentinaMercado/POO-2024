#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "Editor.h"

class login : public QWidget {
    Q_OBJECT
private:
    QLabel *lUsuario, *lClave;
    QLineEdit *leUsuario, *leClave;
    QPushButton *pbIngresar;
    QGridLayout *layout;

public:
    login();

private slots:
    void slot_validarUsuario();
};

#endif // LOGIN_H
