#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    check = new Check_User(this);
    check->show();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

