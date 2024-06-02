#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

#include "Item.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->startScreen->setVisible(true);
    ui->puzzleWidget->setVisible(false);

    ui->keyButton->setVisible(false);

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

    Item *pills, *knife, *key;

    pills = new Item(1, "pills");
    knife = new Item(2, "knife");
    key = new Item(3, "key");

    allItems = {*pills, *knife, *key};

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeRoom(int index)
{
    room *nextRoom = currentRoom->getExit(index);
    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        cout << currentRoom->getRoomIndex() << endl;
        ui->stackedWidget->setCurrentIndex(currentRoom->getRoomIndex());
    } else {
        qDebug() << "Error: No exit in that direction.";
    }
}

void MainWindow::itemClicked(int index)
{
    for (int i = 0; i <allItems.size(); i++) {
        if( allItems[i].getIndex() == index) {
            userInventory.addItemToInventory(&allItems[i]);
            cout << allItems[i].getName();
        }
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


void MainWindow::on_startGameButton_clicked()
{
    ui->startScreen->setVisible(false);
}


void MainWindow::on_pillsButton_clicked()
{
    itemClicked(1);
    ui->pillsButton->setVisible(false);
}
void MainWindow::on_knifeButton_clicked()
{
    itemClicked(2);
    ui->knifeButton->setVisible(false);
}
void MainWindow::on_keyButton_clicked()
{
    itemClicked(3);
    ui->keyButton->setVisible(false);
}


void MainWindow::on_passwordButton_clicked()
{
    ui->puzzleWidget->setVisible(true);
}


void MainWindow::on_puzzleGoBackButton_clicked()
{
    ui->puzzleWidget->setVisible(false);
}


void MainWindow::on_PuzzleSubmitButton_clicked()
{
    QString answer = ui->lineEdit->text();
    bool ok;
    int ansToNum = answer.toInt(&ok);
    if (ok) {
        qDebug() << "converted successfully!";
        if (ansToNum == 323) {
            ui->label_10->setText("right answer you got a key!");
            ui->keyButton->setVisible(true);
        }
        else {
            ui->label_10->setText("wrong answer try again !(");
        }

    } else {
        qDebug() << "failed !";
        ui->label_10->setText("enter a 3 digit number!");
    }

}


