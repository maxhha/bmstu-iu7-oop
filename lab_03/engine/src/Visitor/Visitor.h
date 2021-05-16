#pragma once

#include "Nodes/SceneTree/SceneTree.h"
#include "Nodes/Camera/Camera.h"
#include "Nodes/Model/Model.h"

class Visitor
{
public:
    virtual void visitSceneTree(SceneTree &sceneTree) = 0;
    virtual void visitCamera(Camera &camera) = 0;
    virtual void visitModel(Model &model) = 0;
};
