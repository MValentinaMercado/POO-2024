#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>

class login : public QWidget {
    Q_OBJECT
private:
    QLabel *lUsuario, *lClave;
    QLineEdit *leUsuario, *leClave;
    QPushButton *pbEntrar;
    QGridLayout *layout;
    QNetworkAccessManager * manager;
    QImage im;

public:
    login();
protected:
    void paintEvent( QPaintEvent * );

private slots:
    void slot_validarUsuario();
    void slot_descargaFinalizada(QNetworkReply * reply );
};

#endif // LOGIN_H
