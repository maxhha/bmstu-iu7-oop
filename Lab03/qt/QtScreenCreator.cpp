#include "QtScreenCreator.h"
#include "QtRenderVisitor.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>

std::shared_ptr<Screen> QtScreenCreator::createScreen(int x, int y, int width, int height)
{
    auto view = new QGraphicsView(widget);
    auto scene = new QGraphicsScene(view);

    view->setGeometry(x, y, width + 2, height + 2);
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, width, height);

    auto label = new QLabel(widget);
    label->setText(QString::number(widget->children().count() / 2));
    label->setGeometry(x + 2, y, 100, 20);

    return std::make_shared<Screen>(
        x, y, width, height,
        std::make_unique<QtRenderVisitor>(scene));
}
