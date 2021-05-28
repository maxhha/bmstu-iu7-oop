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

    auto modelData = getData<Model, ModelData>(model);

    for (const auto &edge : modelData.getEdges())
    {
        auto x1 = edge.getStartPoint()->getX() * 100 + 50;
        auto y1 = edge.getStartPoint()->getY() * 100 + 50;
        auto x2 = edge.getEndPoint()->getX() * 100 + 50;
        auto y2 = edge.getEndPoint()->getX() * 100 + 50;

        scene->addLine(x1, y1, x2, y2);
    }
}

void QtRenderVisitor::render(const SceneTree &tree)
{
    visitSceneTree(const_cast<SceneTree &>(tree));
}