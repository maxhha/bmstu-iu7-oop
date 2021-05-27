#include <engine/Object/Model.h>
#include <engine/Object/SceneTree/SceneTree.h>
#include "QtRenderVisitor.h"
#include <QDebug>
#include <QString>

void QtRenderVisitor::visitSceneTree(SceneTree &tree)
{
    qDebug() << "Render tree \"" << getName(tree).c_str() << "\"";

    for (auto &obj : *Visitor::getChildren(tree))
    {
        obj->accept(*this);
    }
}

void QtRenderVisitor::visitModel(Model &model)
{
    qDebug() << "Render model \"" << getName(model).c_str() << "\"";
}

void QtRenderVisitor::render(const SceneTree &tree)
{
    visitSceneTree(const_cast<SceneTree &>(tree));
}