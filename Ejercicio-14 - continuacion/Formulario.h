#ifndef FORMULARIO_H
#define FORMULARIO_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Formulario : public QWidget {
    Q_OBJECT
private:
    QLabel *lLegajo,*lNombre, *lApellido;
    QLineEdit *leLegajo,*leNombre, *leApellido;
    QPushButton *pbAlta;
    QGridLayout *layout;

public:
    Formulario();

private slots:
    void slot_UsuarioForm();

};

#endif // FORMULARIO_H
