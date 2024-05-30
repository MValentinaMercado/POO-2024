#ifndef ALTA_H
#define ALTA_H

#include <QWidget>
#include "admindb.h"

class Manager;

namespace Ui {
class Alta;
}

class Alta : public QWidget
{
    Q_OBJECT

public:
    Alta(Manager *manager, QWidget *parent = nullptr);
    ~Alta();

signals:
    void signal_Volver();

private slots:
    void slot_Volver();
    void slot_Registrar();

private:
    Ui::Alta *ui;
    AdminDB *adminDB;
    Manager *manager;
};

#endif // ALTA_H
