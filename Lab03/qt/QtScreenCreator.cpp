#include "QtScreenCreator.h"
#include "QtRenderVisitor.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>

std::shared_ptr<Screen> QtScreenCreator::createScreen(int id, int x, int y, int width, int height)
{
    auto view = new QGraphicsView(widget);
    auto scene = new QGraphicsScene(view);

    view->setGeometry(x, y, width + 2, height + 2);
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, width, height);

    auto label = new QLabel(view);
    label->setText(QString::number(id));
    label->setGeometry(2, 0, 100, 20);

    view->show();

    return std::make_shared<Screen>(
        std::make_unique<QtRenderVisitor>(view));
}
