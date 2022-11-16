#include "mainwindow.h"
#include <QApplication>

//executa a aplicação
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
