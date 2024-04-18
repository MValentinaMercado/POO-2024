#include "htmlwindow.h"
#include <QDebug>

HtmlWindow::HtmlWindow(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout(this);
    urlLineEdit = new QLineEdit(this);
    htmlTextEdit = new QTextEdit(this);
    layout->addWidget(new QLabel("URL:"), 0, 0);
    layout->addWidget(urlLineEdit, 0, 1);
    layout->addWidget(htmlTextEdit, 1, 0, 1, 2);

    networkManager = new QNetworkAccessManager(this);
    connect(urlLineEdit, &QLineEdit::returnPressed, this, &HtmlWindow::handleUrlEntered);
}

void HtmlWindow::handleUrlEntered() {
    QUrl url = QUrl(urlLineEdit->text());
    loadHtmlFromUrl(url);
}

void HtmlWindow::loadHtmlFromUrl(const QUrl& url) {
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString html = QString::fromUtf8(reply->readAll());
            htmlTextEdit->setPlainText(html);
        } else {
            htmlTextEdit->setPlainText("Error fetching HTML: " + reply->errorString());
        }
        reply->deleteLater();
    });
}
