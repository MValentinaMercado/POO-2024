#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Login *ui;
    QNetworkAccessManager * manager;
    QImage image;
    bool se_descargo;
private slots:
    void slot_validarUsuario();
    void slot_descargafinalizada(QNetworkReply * reply);

};
#endif // LOGIN_H
