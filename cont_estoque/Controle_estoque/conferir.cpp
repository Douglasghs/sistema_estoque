#include "conferir.h"
#include "ui_conferir.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

QSqlDatabase banco01 = QSqlDatabase::connectionNames("QSQLITE");

conferir::conferir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conferir)
{
    ui->setupUi(this);

    banco01.setDatabaseName("C:/Users/infot/OneDrive/Área de Trabalho/Cods/QT/Controle_estoque/estoque_banco.db");
    if(!banco01.open())
    {
        qDebug("banco 2 n foi aberto");
        return;
    }
}

conferir::~conferir()
{
    delete ui;
}
