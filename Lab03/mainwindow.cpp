#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), engineCreator()
{
    ui->setupUi(this);
    engineCreator.readConfiguration("../Lab03/config.yml");
    engineCreator.getEngine();
}

MainWindow::~MainWindow()
{
    delete ui;
}
