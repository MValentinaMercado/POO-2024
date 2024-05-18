#ifndef HTML_H
#define HTML_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class Html : public QWidget {
    Q_OBJECT
public:
    Html(QWidget *parent = nullptr);
    void HtmlDesdeUrl(const QUrl& url);

private slots:
    void UrlIngresada();

private:
    QLineEdit *lurl;
    QTextEdit *lehtml;
    QGridLayout *layout;
    QNetworkAccessManager *networkManager;
};

#endif // HTML_H
