#ifndef CUSTOMGAMESWINDOW_H
#define CUSTOMGAMESWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class CustomGamesWindow;
}

class CustomGamesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomGamesWindow(QWidget *parent = nullptr);
    ~CustomGamesWindow();

private slots:

    void getGamesList();

private:
    Ui::CustomGamesWindow *ui;

    QListWidgetItem listWidget;
};

#endif // CUSTOMGAMESWINDOW_H
