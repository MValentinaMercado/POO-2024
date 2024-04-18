#ifndef HTML_WINDOW_H
#define HTML_WINDOW_H

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

class HtmlWindow : public QWidget {
    Q_OBJECT
public:
    HtmlWindow(QWidget *parent = nullptr);
    void loadHtmlFromUrl(const QUrl& url);

private slots:
    void handleUrlEntered();

private:
    QLineEdit *urlLineEdit;
    QTextEdit *htmlTextEdit;
    QGridLayout *layout;
    QNetworkAccessManager *networkManager;
};

#endif // HTML_WINDOW_H
