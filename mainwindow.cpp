#include "mainwindow.h"
#include "customgameswindow.h"
#include "ui_mainwindow.h"
#include "ui_customgameswindow.h"
#include <QProcess>
#include <QDebug>
#include <QString>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

float UP = -100;
float DOWN = 100;

int selection = 2;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->emulatorButton->setStyleSheet("border: .5px solid black;");
    ui->customGames->setStyleSheet("border: .5px solid black;");

    tmr.setInterval(15);
    connect(&tmr,SIGNAL(timeout()),this,SLOT(inputListener()));
    tmr.start();
}

void MainWindow::inputListener()
{
    sf::Joystick::update();

    //would like to change to a just switching between the two, no matter which way it goes ie: if they have custom games selected it should change to emulator regardless of which way they push (up or down)

    if(sf::Joystick::getAxisPosition(0,sf::Joystick::Y) == UP)
    {
        ui->customGames->setStyleSheet("border: 5px solid black;");
        ui->emulatorButton->setStyleSheet("border: .5px solid black;");
        selection = 0;
    }
    else if (sf::Joystick::getAxisPosition(0,sf::Joystick::Y) == DOWN)
    {
        ui->emulatorButton->setStyleSheet("border: 5px solid black;");
        ui->customGames->setStyleSheet("border: .5px solid black;");
        selection = 1;
    }

    //meed to add support for the second joystick so it doesnt matter wich joystick is used, also, figure out if want a specific button or just set it up for all buttons

    if(sf::Joystick::isButtonPressed(0,0) ||
            sf::Joystick::isButtonPressed(0,1) ||
            sf::Joystick::isButtonPressed(0,2) ||
            sf::Joystick::isButtonPressed(0,3) ||
            sf::Joystick::isButtonPressed(0,4) ||
            sf::Joystick::isButtonPressed(0,5) ||
            sf::Joystick::isButtonPressed(0,6))
    {
        if(selection == 0)
        {
            //opens multiple sometimes, i think it has to do with button debouncing
            qInfo("custom games selected");
            CustomGamesWindow *customGames = new CustomGamesWindow();
            customGames->setWindowState(Qt::WindowMaximized);
            customGames->show();
        }
        else if(selection == 1)
        {
            qInfo("emulator selected");
            QProcess process;
            process.execute("emulationstation");
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
