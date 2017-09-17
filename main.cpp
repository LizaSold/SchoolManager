#include "mainwindow.h"
#include <QApplication>
#include "DBModels/studentdb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    StudentDB s1();
    return a.exec();
}
