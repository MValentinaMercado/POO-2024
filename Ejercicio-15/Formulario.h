#ifndef FORMULARIO_H
#define FORMULARIO_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QRandomGenerator>

class Formulario : public QWidget {
    Q_OBJECT
private:
    QLabel *lLegajo,*lNombre, *lApellido, *lCaptcha;
    QLineEdit *leLegajo,*leNombre, *leApellido, *leCaptcha;
    QPushButton *pbAlta;
    QGridLayout *layout;

public:
    Formulario();

private slots:
    void slot_UsuarioForm();
};

#endif // FORMULARIO_H
