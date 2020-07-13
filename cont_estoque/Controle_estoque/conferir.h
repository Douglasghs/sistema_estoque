#ifndef CONFERIR_H
#define CONFERIR_H

#include <QDialog>

namespace Ui {
class conferir;
}

class conferir : public QDialog
{
    Q_OBJECT

public:
    explicit conferir(QWidget *parent = nullptr);
    ~conferir();

private slots:
    void on_pushButton_4_clicked();

    void on_PB_registar_clicked();

private:
    Ui::conferir *ui;
};

#endif // CONFERIR_H
