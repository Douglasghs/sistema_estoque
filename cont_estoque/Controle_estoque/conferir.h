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

private:
    Ui::conferir *ui;
};

#endif // CONFERIR_H
