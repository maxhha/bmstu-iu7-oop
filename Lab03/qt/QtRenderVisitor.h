#pragma once

#include <QGraphicsView>
#include <engine/Transformation/Transformation.h>
#include <engine/Visitor/RenderVisitor.h>

class QtRenderVisitor : public RenderVisitor
{
public:
    QtRenderVisitor() = delete;
    explicit QtRenderVisitor(QGraphicsView *_view) : view(_view){};

    void visitSceneTree(SceneTree &tree) override;
    void visitModel(Model &model) override;
    void visitCamera(Camera &camera) override;

    void render(const SceneTree &tree, const std::weak_ptr<Camera> &camera) override;

    ~QtRenderVisitor() override { delete view; };

private:
    QGraphicsView *view;
    Transformation transformation;
};