#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>

class Editor : public QWidget {
    Q_OBJECT
private:
    QTextEdit *editar;
    QLineEdit *buscalinea;
    QPushButton *pbuscar;
    QPushButton *pguardar;
    QLineEdit *nArchivo;
    QLabel *resultado;
    QGridLayout *layout;

public:
    Editor();

private slots:
    void slot_buscar();
    void slot_guardar();
};

#endif // EDITOR_H
