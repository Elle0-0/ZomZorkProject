#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

#include "item.h"
#include "RoomStory.h"
#include "CustomExceptions.h"

int globalAnswer = 323;

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

    allRooms.push_back(bedroom);
    allRooms.push_back(bathroom);
    allRooms.push_back(kitchen);
    allRooms.push_back(balcony);
    allRooms.push_back(trainStatiom);
    allRooms.push_back(trainInside);

    Item *pills = new Item(1, "pills", "weird looking pills on the floor");
    Item *knife = new Item(2, "knife", "might be usefull later?");
    Item *key = new Item(3, "key", "the key to the balcony");

    // use of bit structure
    key->setWeight(34);

    allItems.push_back(pills);
    allItems.push_back(knife);
    allItems.push_back(key);

    setStoryLine();
}

MainWindow::~MainWindow()
{
    for (Entity* item : allItems) {
        delete item;
    }
    for (room* rooms : allRooms) {
        delete rooms;
    }
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
        throw InvalidRoomException( "Error: No exit in that direction.");
    }
}

void MainWindow::itemClicked(int index)
{
    for (int i = 0; i < allItems.size(); i++) {
        if( allItems[i]->getIndex() == index) {
            userInventory.addItemToInventory(allItems[i]);
            cout << allItems[i]->getName();
        }
    }
}

void MainWindow::setStoryLine() {
    QString text1 = QString::fromStdString(storyline::bedroom::getText());
    ui->text_1->setText(text1);
    QString text2 = QString::fromStdString(storyline::bathroom::getText());
    ui->text_2->setText(text2);
    QString text3 = QString::fromStdString(storyline::kitchen::getText());
    ui->text_3->setText(text3);
    QString text4 = QString::fromStdString(storyline::balcony::getText());
    ui->text_4->setText(text4);
    QString text5 = QString::fromStdString(storyline::trainStation::getText());
    ui->text_5->setText(text5);
    QString text6 = QString::fromStdString(storyline::insideTrain::getText());
    ui->text_6->setText(text6);
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
        if (ansToNum == globalAnswer) {
            ui->label_10->setText("right answer you got a key!");
            ui->keyButton->setVisible(true);
            ui->PuzzleSubmitButton->setVisible(false);
        }
        else {
            ui->label_10->setText("wrong answer try again !(");
        }

    } else {
        qDebug() << "failed !";
        ui->label_10->setText("enter a 3 digit number!");
    }
}



void MainWindow::on_closeButton_clicked()
{
    close();
}

