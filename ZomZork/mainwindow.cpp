#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "room.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    setFixedSize(1190, 680);

    room *room1, *room2, *room3, *room4, *room5;

    room1 = new room("room1", 0);
    room2 = new room("room2", 1);
    room3 = new room("room3", 2);
    room4 = new room("room4", 3);
    room5 = new room("room5", 4);

    room1->setExits(room2, room3, room4, room5);
    room2->setExits(nullptr, room1, nullptr, nullptr);
    room3->setExits(room1, nullptr, nullptr, nullptr);
    room4->setExits(nullptr, nullptr, nullptr, room1);
    room5->setExits(nullptr, nullptr, room1, nullptr);

    currentRoom = room1;
    cout << currentRoom->getRoomIndex() << endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeRoom(int index) {
    room *nextRoom = currentRoom->getExit(index);
    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        cout << currentRoom->getRoomIndex() << endl;
        ui->stackedWidget->setCurrentIndex(currentRoom->getRoomIndex());
    } else {
        qDebug() << "Error: No exit in that direction.";
    }
}

void MainWindow::on_northButton_clicked()
{
    changeRoom(0);
}
void MainWindow::on_southButton_clicked()
{
    changeRoom(1);
}
void MainWindow::on_eastButton_clicked()
{
    changeRoom(2);
}
void MainWindow::on_westButton_clicked()
{
    changeRoom(3);
}

