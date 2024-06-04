#include "mainwindow.h"

#include <QApplication>

// This is the github repo: https://github.com/Elle0-0/ZomZorkProject
// thanks

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
