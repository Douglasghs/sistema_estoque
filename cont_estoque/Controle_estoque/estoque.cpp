#include "estoque.h"
#include "ui_estoque.h"
#include "conferir.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPixmap>

estoque::estoque(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::estoque)
{
    ui->setupUi(this);

    QPixmap logo(":/new/prefix1/img/mercado-livre-vagas-1280x720.png");
    ui->label->setPixmap(logo.scaled(1100,600,Qt::KeepAspectRatio));
}

estoque::~estoque()
{
    delete ui;
}


void estoque::on_pushButton_clicked()
{
    conferir form;
    form.exec();
}
