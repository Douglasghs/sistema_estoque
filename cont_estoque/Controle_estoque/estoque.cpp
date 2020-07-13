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
}

estoque::~estoque()
{
    delete ui;
}

