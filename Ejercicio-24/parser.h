#ifndef PARSER_H
#define PARSER_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QDir>

class Parser : public QWidget {
    Q_OBJECT
public:
    explicit Parser(QWidget *parent = nullptr);
    void HtmlDesdeUrl(QUrl url, QString DDirectorio);

signals:
    void htmlDescargado(QString html);
    void errorDescarga(QString msjError);

private slots:
    void ADRecursos(QString html, QUrl urlBase);
    void DescargarR(QUrl url, QString ruta);

private:
    QString Ruta_Tipo(QString extension);
    bool esRValido(QString extension);

    QNetworkAccessManager *Manager;
    QString directorioD;
    QStringList listaR;
};

#endif // PARSER_H
