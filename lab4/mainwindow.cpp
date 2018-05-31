#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mcabin = new cabin(nullptr);
}

MainWindow::~MainWindow()
{
    delete mcabin;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mcabin->onPushButton(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    mcabin->onPushButton(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    mcabin->onPushButton(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    mcabin->onPushButton(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    mcabin->onPushButton(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    mcabin->onPushButton(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    mcabin->onPushButton(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    mcabin->onPushButton(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    mcabin->onPushButton(9);
}

void MainWindow::on_pushButton_10_clicked()
{
    mcabin->onPushButton(10);
}
