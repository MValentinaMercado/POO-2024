#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include "admindb.h"

class Manager;

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    Formulario(Manager *manager, QWidget *parent = nullptr);
    ~Formulario();
      void ActualizarDatos();

signals:
    void signal_Volver();

private slots:
    void slot_ActualizarDatos();

private:
    Ui::Formulario *ui;
    AdminDB *adminDB;
    Manager *manager;

    void cargarUsuarios();
};

#endif // FORMULARIO_H
