#include "estoque.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    estoque w;
    w.show();
    return a.exec();
}
