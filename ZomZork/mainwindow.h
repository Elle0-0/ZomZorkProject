#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "room.h"

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

private:
    Ui::MainWindow *ui;
    void changeRoom(int index);
    int currentRoomIndex;
    room *currentRoom;
};
#endif // MAINWINDOW_H
