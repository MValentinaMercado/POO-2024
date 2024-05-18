#include "HTML.h"
#include <QDebug>

Html::Html(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout(this);
    lurl = new QLineEdit(this);
    lehtml = new QTextEdit(this);
    layout->addWidget(new QLabel("URL:"), 0, 0);
    layout->addWidget(lurl, 0, 1);
    layout->addWidget(lehtml, 1, 0, 1, 2);

    networkManager = new QNetworkAccessManager(this);
    connect(lurl, SIGNAL(returnPressed()), this, SLOT(UrlIngresada()));

}

void Html::UrlIngresada() {
    QUrl url = QUrl(lurl->text());
    HtmlDesdeUrl(url);
}

void Html::HtmlDesdeUrl(const QUrl& url) {
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString html = QString::fromUtf8(reply->readAll());
            lehtml->setPlainText(html);
        } else {
            lehtml->setPlainText("Error al obtener el HTML: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
