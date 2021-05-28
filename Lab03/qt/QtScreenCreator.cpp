#include "QtScreenCreator.h"
#include "QtRenderVisitor.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLayout>
#include <QGridLayout>

std::shared_ptr<Screen> QtScreenCreator::createScreen(int x, int y, int width, int height)
{
    auto view = new QGraphicsView(widget);
    auto scene = new QGraphicsScene(view);

    view->setGeometry(x, y, width + 2, height + 2);
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, width, height);
    // view->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // if (widget->layout() == nullptr)
    // {
    //     widget->setLayout(new QGridLayout(widget));
    // }

    // auto layout = widget->layout();

    // layout->addWidget(view);

    return std::make_shared<Screen>(
        x, y, width, height,
        std::make_unique<QtRenderVisitor>(scene));
}
