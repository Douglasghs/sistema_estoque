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
    ui->tableWidget->clear();
    QSqlQuery query;
    query.prepare("select * from produtos");
    if(!query.exec())
    {
        ui->textEdit->setText("Query selecionar todos n rodou");
        return;
    }
    else
    {
        int cont=0;
        ui->tableWidget->setColumnCount(5);
        while(query.next())
        {
            ui->tableWidget->insertRow(cont);
            ui->tableWidget->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget->setRowHeight(cont,20);
            cont++;
        }
    }
}

void conferir::on_PB_registar_clicked()
{
    QString tipo= ui->LE_produto->text();
    QString marca = ui->LE_marca->text();
    QString quantidade= ui->LN_quantidade->text();
    QString validade= ui->LN_validade->text();

    QSqlQuery query;
    query.prepare("insert into produtos(tipo,marca,quantidade,validade) values('"+tipo+"','"+marca+"','"+quantidade+"','"+validade+"')");
    if(!query.exec())
    {
        ui->textEdit->setText("Query de registramento n executada");
        return;
    }
    else
    {
        ui->textEdit->clear();
        ui->textEdit->setText("Produto armazenado com sucesso");
        ui->LE_produto->clear();
        ui->LE_marca->clear();
        ui->LN_validade->clear();
        ui->LN_quantidade->clear();
        ui->LE_produto->setFocus();
        return;
    }
}

void conferir::on_pushButton_3_clicked()
{
    QString marca= ui->LE_marca->text();
    QSqlQuery query;
    query.prepare("delete from produtos where marca='"+marca+"'");
    if(!query.exec())
    {
        ui->textEdit->setText("Query de delete n executada");
        ui->LE_marca->clear();
        return;
    }
    else
    {
        ui->textEdit->setText("Produto removido com sucesso");
        ui->LE_marca->clear();
        return;

    }
}
