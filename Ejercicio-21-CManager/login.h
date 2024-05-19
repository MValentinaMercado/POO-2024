#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    QString getUsuario();
    QString getClave();

signals:
    void validarUsuario();

private:
    Ui::Login *ui;

private slots:
    void on_leClave_returnPressed();
};

#endif // LOGIN_H
