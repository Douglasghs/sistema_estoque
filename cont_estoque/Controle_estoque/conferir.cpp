#include "conferir.h"
#include "ui_conferir.h"

#include <QPixmap>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

QSqlDatabase banco01 = QSqlDatabase::addDatabase("QSQLITE");

conferir::conferir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conferir)
{
    ui->setupUi(this);

    banco01.setDatabaseName("C:/Users/infot/OneDrive/Área de Trabalho/Cods/QT/cont_estoque/Controle_estoque/estoque_banco.db");
    if(!banco01.open())
    {
        qDebug("banco 2 n foi aberto");
        return;
    }

    QPixmap logo(":/new/prefix1/img/mercado-livre-vagas-1280x720.png");
    ui->label->setPixmap(logo.scaled(1000,700,Qt::KeepAspectRatio));
}

conferir::~conferir()
{
    delete ui;
}

void conferir::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.prepare("select * from produtos");
    if(!query.exec())
    {
        qDebug("query selecionar todos n rodou");
        return;
    }
    else
    {
        int cont=0;
        ui->tableWidget->setColumnCount(4);
        while(query.next())
        {
            ui->tableWidget->insertRow(cont);
            ui->tableWidget->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setRowHeight(cont,20);
            cont++;
        }
    }
}
