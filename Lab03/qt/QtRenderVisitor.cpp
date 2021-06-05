#include <engine/Object/Model.h>
#include <engine/Object/Camera.h>
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

    const auto points = getData<Model, ModelData>(model)->getPoints();

    for (const auto &edge : getData<Model, ModelData>(model)->getEdges())
    {
        auto p1 = transformation.transform(points[edge.getStartPoint()]);
        auto p2 = transformation.transform(points[edge.getEndPoint()]);

        view->scene()->addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
}

void QtRenderVisitor::visitCamera(Camera &camera){};

void QtRenderVisitor::render(const SceneTree &tree, const std::weak_ptr<Camera> &camera)
{
    view->scene()->clear();
    if (camera.expired())
        return;
    transformation = *getData<Camera, Transformation>(*camera.lock());
    visitSceneTree(const_cast<SceneTree &>(tree));
}
