#include "customgameswindow.h"
#include "ui_customgameswindow.h"
#include <QDir>

CustomGamesWindow::CustomGamesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomGamesWindow)
{
    ui->setupUi(this);

    QDir directory("/home/pi/Custom Games");
    QStringList files = directory.entryList(QStringList() << "*.txt",QDir::Files);
    foreach(QString filename, files)
    {
        QString str = files.join("");
        ui -> listWidget -> addItem(str);
    }
}

CustomGamesWindow::~CustomGamesWindow()
{
    delete ui;
}

void CustomGamesWindow::getGamesList()
{
    QDir directory("/home/pi/Custom Games");
    QStringList images = directory.entryList(QStringList() << "*.txt",QDir::Files);
    foreach(QString filename, images)
    {
        QString str = images.join("");
        ui -> listWidget -> addItem(str);
    }
}
