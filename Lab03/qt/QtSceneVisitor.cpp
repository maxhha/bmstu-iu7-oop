#include "QtSceneVisitor.h"
#include <engine/Object/SceneTree/SceneTree.h>
#include <engine/Object/Model.h>
#include <engine/Object/Camera.h>

QTreeWidgetItem *QtSceneVisitor::createItem()
{
    QTreeWidgetItem *item = stack.size() == 0
                                ? new QTreeWidgetItem(treeWidget)
                                : new QTreeWidgetItem(stack.top());

    item->setExpanded(true);

    return item;
}

void QtSceneVisitor::visitSceneTree(SceneTree &tree)
{
    auto item = createItem();
    item->setData(0, Qt::DisplayRole, QString("SceneTree"));
    item->setData(1, Qt::DisplayRole, QString::fromStdString(getName<SceneTree>(tree)));

    stack.push(item);

    for (auto &it : *getChildren(tree))
    {
        it->accept(*this);
    }

    stack.pop();
}

void QtSceneVisitor::visitModel(Model &model)
{
    QTreeWidgetItem *item = createItem();

    item->setData(0, Qt::DisplayRole, QString("Model"));
    item->setData(1, Qt::DisplayRole, QString::fromStdString(getName<Model>(model)));
}

void QtSceneVisitor::visitCamera(Camera &camera)
{
    QTreeWidgetItem *item = createItem();

    item->setData(0, Qt::DisplayRole, QString("Camera"));
    item->setData(1, Qt::DisplayRole, QString::fromStdString(getName<Camera>(camera)));
}
