#include "formulario.h"
#include "ui_formulario.h"
#include "manager.h"

Formulario::Formulario(Manager *manager, QWidget *parent)
    : QWidget(parent), ui(new Ui::Formulario), manager(manager)
{
    ui->setupUi(this);
      adminDB = AdminDB::getInstancia();
      cargarUsuarios();
        connect(ui->pbActualizar, SIGNAL(clicked()), this, SLOT(slot_ActualizarDatos()));

}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::ActualizarDatos()
{
    slot_ActualizarDatos();
}

void Formulario::cargarUsuarios()
{
    ui->treeWidget->clear();

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList() << "Usuario" << "Clave");

    QSqlQuery query;
    query.exec("SELECT usuario, clave FROM usuarios");

    while(query.next()) {
        QString usuario = query.value(0).toString();
        QString clave = query.value(1).toString();

        // Nuevos
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, usuario);
        item->setText(1, clave);

        // Originales
        item->setData(0, Qt::UserRole, usuario);
        item->setData(1, Qt::UserRole, clave);

        item->setFlags(item->flags() | Qt::ItemIsEditable);
    }
}

void Formulario::slot_ActualizarDatos()
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(i);
        QString nuevoUsuario = item->text(0);
        QString nuevaClave = item->text(1);
        QString usuarioOriginal = item->data(0, Qt::UserRole).toString();
        QString claveOriginal = item->data(1, Qt::UserRole).toString();

        if (nuevoUsuario != usuarioOriginal || nuevaClave != claveOriginal) {
            QString nuevaClaveMD5 = QCryptographicHash::hash(nuevaClave.toUtf8(), QCryptographicHash::Md5).toHex();

            if (adminDB->actualizarUsuario(usuarioOriginal, claveOriginal, nuevoUsuario, nuevaClaveMD5)) {
                qDebug() << "Actualización exitosa ";
            } else {
                qDebug() << "Error al actualizar " ;
            }
        }
    }

    cargarUsuarios();
}
