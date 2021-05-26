#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), engineCreator()
{
    ui->setupUi(this);
    engineCreator.readConfiguration("../Lab03/config.yml");
    auto loader = engineCreator.getEngine()->getObjectLoaderSolution()->create("FileModel");

    auto object = loader->load("../Lab03/model.yml");


    qDebug() << "LoadedObject name = " << QString(object->getName().c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}
