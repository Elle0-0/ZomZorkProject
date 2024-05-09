#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "room.h"
#include <iostream>

#include "Entity.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    setFixedSize(1190, 680);

    room *bedroom, *bathroom, *kitchen, *balcony, *trainStatiom, *trainInside;

    bedroom = new room("room1", 0);
    bathroom = new room("room2", 1);
    kitchen = new room("room3", 2);
    balcony = new room("room4", 3);
    trainStatiom = new room("room5", 4);
    trainInside = new room("room6", 5);

    bedroom->setExits(nullptr, balcony, kitchen, bathroom);
    bathroom->setExits(nullptr, nullptr, bedroom, nullptr);
    kitchen->setExits(nullptr, nullptr, nullptr, bedroom);
    balcony->setExits(bedroom, trainStatiom, nullptr, nullptr);
    trainStatiom->setExits(balcony, nullptr, nullptr, trainInside);
    trainInside->setExits(nullptr, nullptr, trainStatiom, nullptr);

    currentRoom = bedroom;

    Entity entity("Object");
    cout << entity.getName() << endl;

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

