#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <qt/QtEngineCreator.h>
#include <engine/EngineSolution/EngineSolution.h>

using VecStr = std::vector<std::string>;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto _scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto rcontent = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, rcontent.width(), rcontent.height());

    EngineSolution solution;

    std::shared_ptr<EngineCreator> qtEngine = std::make_shared<QtEngineCreator>(_scene);

    solution.registration("qt", qtEngine);

    solution.readConfiguration("../Lab03/config.yml");

    engine = solution.createEngine();

    auto loader = engine->getObjectLoaderSolution()->create("FileModel");
    auto object = loader->load("../Lab03/model.yml");

    engine->getObjectMediator()->appendChild("root", object);
    engine->getScreenManager()->addScreen(0, 0, 100, 100);
    engine->getScreenManager()->render(*engine->getObjectMediator()->getSceneTree());
}

MainWindow::~MainWindow()
{
    delete ui;
}
