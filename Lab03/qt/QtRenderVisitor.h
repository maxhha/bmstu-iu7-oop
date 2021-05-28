#pragma once

#include <QGraphicsScene>
#include <engine/Transformation/Transformation.h>
#include <engine/Visitor/RenderVisitor.h>

class QtRenderVisitor : public RenderVisitor
{
public:
    QtRenderVisitor() = delete;
    explicit QtRenderVisitor(QGraphicsScene *_scene) : scene(_scene){};

    void visitSceneTree(SceneTree &tree) override;
    void visitModel(Model &model) override;
    void visitCamera(Camera &camera) override;

    void render(const SceneTree &tree, const std::weak_ptr<Camera> &camera) override;

    ~QtRenderVisitor() override = default;

private:
    QGraphicsScene *scene;
    Transformation transformation;
};