#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <qt/QtEngineCreator.h>
#include <engine/EngineSolution/EngineSolution.h>
#include <engine/Object/Camera.h>
#include <engine/Command/Commands.h>
#include <QMessageBox>
#include <QMenu>
#include <engine/Exception/Exception.h>
#include <math.h>

void MainWindow::execute(Command &command)
{
    try
    {
        command.execute();
        RenderCommand(engine)
            .execute();
    }
    catch (EngineException &ex)
    {
        QMessageBox mb;
        mb.setText(ex.what());
        mb.exec();
    }
}

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

    // auto loader = engine->getObjectLoaderSolution()->create("FileModel");
    // auto object = loader->load("../Lab03/model.yml");

    // auto camera = std::make_shared<Camera>("cam0", Transformation({25.0, 0.0, 0.0, 50.0,
    //                                                                0.0, 25.0, 0.0, 50.0,
    //                                                                0.0, 0.0, 25.0, 0.0,
    //                                                                0.0, 0.0, 0.0, 1.0}));
    // auto camera1 = std::make_shared<Camera>("cam1", Transformation({0.0, -25.0, 0.0, 50.0,
    //                                                                 25.0, 0.0, 0.0, 50.0,
    //                                                                 0.0, 0.0, 50.0, 0.0,
    //                                                                 0.0, 0.0, 0.0, 1.0}));
    // engine->getObjectMediator()->appendChild("root", object);
    // engine->getObjectMediator()->appendChild("root", camera);
    // engine->getObjectMediator()->appendChild("root", camera1);
    // engine->getScreenManager()->addScreen(0, 0, 100, 100);
    // engine->getScreenManager()->addScreen(120, 0, 100, 100);
    // engine->getScreenManager()->addScreen(0, 120, 100, 100);
    // engine->getScreenManager()->setCamera(0, camera);
    // engine->getScreenManager()->setCamera(1, camera);
    // engine->getScreenManager()->setCamera(2, camera1);

    // engine->getScreenManager()->removeScreen(1);

    // engine->getObjectSaverSolution()->create("FileSceneTree")->save("../Lab03/temp.yml", engine->getObjectMediator()->getSceneTree());

    auto object = engine->getObjectLoaderSolution()->create("FileSceneTree")->load("../Lab03/temp.yml");
    engine->getObjectMediator()->appendChild("root", object);

    {
        auto camera0 = std::dynamic_pointer_cast<Camera>(engine->getObjectMediator()->get("cam0"));
        auto camera1 = std::dynamic_pointer_cast<Camera>(engine->getObjectMediator()->get("cam1"));

        engine->getScreenManager()->addScreen(0, 0, 100, 100);
        engine->getScreenManager()->addScreen(120, 0, 100, 100);
        engine->getScreenManager()->addScreen(0, 120, 100, 100);

        engine->getScreenManager()->setCamera(0, camera0);
        engine->getScreenManager()->setCamera(1, camera0);
        engine->getScreenManager()->setCamera(2, camera1);
    }

    //    engine->getObjectMediator()->remove("cam0");

    RenderCommand(engine)
        .execute();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonTranslate_clicked()
{
    auto target = ui->inputTranslateTarget->text().toStdString();
    double x = ui->inputTranslateX->value();
    double y = ui->inputTranslateY->value();
    double z = ui->inputTranslateZ->value();

    TranslateObjectCommand cmd(engine, target, x, y, z);

    execute(cmd);
}

void MainWindow::on_buttonScale_clicked()
{
    auto target = ui->inputScaleTarget->text().toStdString();
    double x = ui->inputScaleX->value();
    double y = ui->inputScaleY->value();
    double z = ui->inputScaleZ->value();

    ScaleObjectCommand cmd(engine, target, x, y, z);

    execute(cmd);
}

void MainWindow::on_buttonRotate_clicked()
{
    auto target = ui->inputRotateTarget->text().toStdString();
    double x = ui->inputRotateX->value();
    double y = ui->inputRotateY->value();
    double z = ui->inputRotateZ->value();
    double a = ui->inputRotateAngle->value() * M_PI / 180;

    double l = x*x + y*y + z*z;
    if (l == 0)
        return;

    RotateObjectCommand cmd(engine, target, x / l, y / l, z / l, a);

    execute(cmd);
}

void MainWindow::on_buttonSetCamera_clicked()
{
    int id = ui->inputSetCameraScreen->value();
    std::string camera = ui->inputCameraScreen->text().toStdString();

    SetScreenCameraCommand cmd(engine, id, camera);

    execute(cmd);
}

void MainWindow::on_buttonRemoveScreen_clicked()
{
    int id = ui->inputRemoveScreen->value();

    RemoveScreenCommand cmd(engine, id);

    execute(cmd);
}

void MainWindow::on_buttonAddScreen_clicked()
{
    int x1 = ui->inputScreenX1->value();
    int x2 = ui->inputScreenX2->value();
    int y1 = ui->inputScreenY1->value();
    int y2 = ui->inputScreenY2->value();

    AddScreenCommand cmd(engine, x1, y1, x2, y2);

    execute(cmd);
}

void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    auto val = ui->sceneTreeWidget->itemAt(pos);

    QMenu *menu = new QMenu(ui->centralwidget);

    menu->addAction(new QAction("Action1", menu));
    menu->addAction(new QAction("Action2", menu));
    menu->addAction(new QAction("Action3", menu));

    menu->popup(ui->sceneTreeWidget->viewport()->mapToGlobal(pos));
}
