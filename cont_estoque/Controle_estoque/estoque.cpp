#include "estoque.h"
#include "ui_estoque.h"
#include "conferir.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPixmap>

QSqlDatabase banco= QSqlDatabase::addDatabase("QSQLITE");

estoque::estoque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::estoque)
{
    ui->setupUi(this);
    banco.setDatabaseName("C:/Users/infot/OneDrive/Área de Trabalho/Cods/QT/Controle_estoque/entrada_banco.db");
    if(!banco.open())
    {
        qDebug("Banco n aberto");
    }
    QPixmap logo(":/new/prefix1/img/mercado-livre-vagas-1280x720.png");
    ui->label->setPixmap(logo.scaled(1000,700,Qt::KeepAspectRatio));
    banco.close();
}

estoque::~estoque()
{
    delete ui;
}

void estoque::on_pushButton_clicked()
{
  QString nome=ui->LN_usuario->text();
  QString senha = ui->LN_senha->text();

  if(!banco.isOpen())
  {
      qDebug("Banco off");
      return;
  }
  QSqlQuery query;
  if(!query.exec("select * from logi where usuario='"+nome+"' and senha='"+senha+"'"))
  {
      QMessageBox::about(this,"ERRO","Usuário ou senha incorreto");
      qDebug("Query erro");
      return;
  }
  else
  {
     this->close();
     conferir form;
     form.exec();
  }
}

void estoque::on_pushButton_2_clicked()
{
    QString nome = ui->LN_usuario->text();
    QString senha = ui->LN_senha->text();

    QSqlQuery query;
    if(!query.exec("insert into logi(usuario,senha) values('"+nome+"','"+senha+"')"))
    {
        QMessageBox::about(this,"ERRO","Usuário não foi registrado");
        ui->LN_usuario->clear();
        ui->LN_senha->clear();
        return;
    }
    else
    {
        QMessageBox::about(this,"SUCESSO","Usuário foi registrado");
        ui->LN_usuario->clear();
        ui->LN_senha->clear();
        return;
    }
}
