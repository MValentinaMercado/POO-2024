#include "parser.h"

Parser::Parser(QWidget *parent)
    : QWidget(parent), Manager(new QNetworkAccessManager(this)) {}

void Parser::HtmlDesdeUrl(QUrl url, QString DDirectorio) {
    this->directorioD = DDirectorio;
    QNetworkRequest request(url);
    QNetworkReply *reply = Manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString html = QString::fromUtf8(reply->readAll());
            emit htmlDescargado(html);
            ADRecursos(html, url);
        } else {
            emit errorDescarga(reply->errorString());
        }
        reply->deleteLater();
    });
}

void Parser::ADRecursos(QString html, QUrl urlBase) {
    QStringList tags = {"img", "link", "script"};
    QStringList attributes = {"src", "href"};

    for (QString tag : tags) {
        for (QString attribute : attributes) {
            int pos = 0;
            while ((pos = html.indexOf("<" + tag, pos, Qt::CaseInsensitive)) != -1) {
                int endPos = html.indexOf(">", pos);
                if (endPos == -1) break;

                QString element = html.mid(pos, endPos - pos + 1);
                int attrPos = element.indexOf(attribute + "=\"", 0, Qt::CaseInsensitive);
                if (attrPos != -1) {
                    int start = attrPos + attribute.length() + 2;
                    int end = element.indexOf("\"", start);
                    QString resourceUrl = element.mid(start, end - start);

                    QUrl absoluteUrl = urlBase.resolved(QUrl(resourceUrl));
                    QString extension = QFileInfo(absoluteUrl.path()).suffix();

                    if (esRValido(extension)) {
                        QString folderPath = directorioD + "/" + Ruta_Tipo(extension);
                        QDir().mkpath(folderPath);
                        QString filePath = folderPath + "/" + QFileInfo(absoluteUrl.path()).fileName();
                        DescargarR(absoluteUrl, filePath);
                    }
                }
                pos = endPos;
            }
        }
    }
}

void Parser::DescargarR(QUrl url, QString ruta) {
    QNetworkRequest request(url);
    QNetworkReply *reply = Manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QFile file(ruta);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(reply->readAll());
                file.close();
                qDebug() << "Recurso descargado: " << ruta;
            } else {
                qDebug() << "No se pudo abrir el archivo para escribir: " << ruta;
            }
        } else {
            qDebug() << "Error al descargar el recurso: " << reply->errorString();
        }
        reply->deleteLater();
    });
}

QString Parser::Ruta_Tipo(QString extension) {
    if (extension == "jpg" || extension == "jpeg" || extension == "png" || extension == "gif" || extension == "bmp") {
        return "imagenes";
    } else if (extension == "css") {
        return "css";
    } else if (extension == "js") {
        return "scripts";
    } else {
        return "";
    }
}

bool Parser::esRValido(QString extension) {
    return (extension == "jpg" || extension == "jpeg" || extension == "png" || extension == "gif" || extension == "bmp" ||
            extension == "css" || extension == "js");
}
