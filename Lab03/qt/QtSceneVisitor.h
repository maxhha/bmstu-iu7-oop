#pragma once

#include <QTreeWidget>
#include <engine/Visitor/Visitor.h>
#include <stack>

class QtSceneVisitor : public Visitor
{

public:
    QtSceneVisitor() = delete;
    QtSceneVisitor(QTreeWidget *_tree) : treeWidget(_tree){};

    void visitSceneTree(SceneTree &tree) override;
    void visitModel(Model &model) override;
    void visitCamera(Camera &model) override;

    ~QtSceneVisitor() override = default;

private:
    QTreeWidget *treeWidget;
    std::stack<QTreeWidgetItem *> stack;

    QTreeWidgetItem *createItem();
};