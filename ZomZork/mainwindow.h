#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "room.h"
#include "Inventory.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_eastButton_clicked();
    void on_westButton_clicked();

    void on_startGameButton_clicked();

    void on_pillsButton_clicked();

    void on_knifeButton_clicked();

    void on_passwordButton_clicked();

    void on_puzzleGoBackButton_clicked();

    void on_PuzzleSubmitButton_clicked();

    void on_keyButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::MainWindow *ui;
    void changeRoom(int index);
    void itemClicked(int index);
    int currentRoomIndex;
    room *currentRoom;
    Inventory userInventory;
    vector<Entity*> allItems;
    vector<room*> allRooms;
    void setStoryLine();
};
#endif // MAINWINDOW_H
