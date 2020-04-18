#include "mainwindow.h"
#include "customgameswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();

    return a.exec();
}
