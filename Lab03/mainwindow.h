#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <engine/EngineSolution/EngineSolution.h>
#include <engine/Command/Command.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonTranslate_clicked();

    void on_buttonScale_clicked();

    void on_buttonRotate_clicked();

    void on_buttonSetCamera_clicked();

    void on_buttonRemoveScreen_clicked();

    void on_buttonAddScreen_clicked();

    void on_sceneTreeWidget_customContextMenuRequested(const QPoint &pos);

    void on_buttonLoadModel_clicked();

    void on_buttonSaveScene_clicked();

    void on_buttonLoadScene_clicked();

    void on_buttonAddCamera_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Engine> engine;
    QGraphicsScene *_scene;

    void execute(Command &cmd);
};
#endif // MAINWINDOW_H
