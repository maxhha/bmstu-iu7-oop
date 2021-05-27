#pragma once

#include <QGraphicsScene>
#include <engine/Visitor/RenderVisitor.h>

class QtRenderVisitor : public RenderVisitor
{
public:
    QtRenderVisitor() = delete;
    explicit QtRenderVisitor(QGraphicsScene *_scene) : scene(_scene){};

    void visitSceneTree(SceneTree &tree) override;
    void visitModel(Model &model) override;

    void render(const SceneTree &tree) override;

    ~QtRenderVisitor() override = default;

private:
    QGraphicsScene *scene;
};