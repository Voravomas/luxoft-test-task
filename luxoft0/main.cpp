#include "mainwindow.h"

#include <QApplication>

// changed size of application.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(300,500);
    w.show();
    return a.exec();
}
