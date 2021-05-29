#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <qt/QtEngineCreator.h>
#include <engine/EngineSolution/EngineSolution.h>
#include <engine/Object/Camera.h>
#include <engine/Command/Commands.h>

using VecStr = std::vector<std::string>;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    EngineSolution solution;

    std::shared_ptr<EngineCreator> qtEngine = std::make_shared<QtEngineCreator>(ui->screenFrame);

    solution.registration("qt", qtEngine);

    solution.readConfiguration("../Lab03/config.yml");

    engine = solution.createEngine();

    auto loader = engine->getObjectLoaderSolution()->create("FileModel");
    auto object = loader->load("../Lab03/model.yml");

    auto camera = std::make_shared<Camera>("cam0", Transformation({25.0, 0.0, 0.0, 50.0,
                                                                   0.0, 25.0, 0.0, 50.0,
                                                                   0.0, 0.0, 25.0, 0.0,
                                                                   0.0, 0.0, 0.0, 1.0}));
    auto camera1 = std::make_shared<Camera>("cam1", Transformation({0.0, -25.0, 0.0, 50.0,
                                                                    25.0, 0.0, 0.0, 50.0,
                                                                    0.0, 0.0, 50.0, 0.0,
                                                                    0.0, 0.0, 0.0, 1.0}));
    engine->getObjectMediator()->appendChild("root", object);
    engine->getObjectMediator()->appendChild("root", camera);
    engine->getObjectMediator()->appendChild("root", camera1);
    engine->getScreenManager()->addScreen(0, 0, 100, 100);
    engine->getScreenManager()->addScreen(120, 0, 100, 100);
    engine->getScreenManager()->addScreen(0, 120, 100, 100);
    engine->getScreenManager()->setCamera(0, camera);
    engine->getScreenManager()->setCamera(1, camera);
    engine->getScreenManager()->setCamera(2, camera1);

    RenderCommand(engine).execute();
}

MainWindow::~MainWindow()
{
    delete ui;
}
