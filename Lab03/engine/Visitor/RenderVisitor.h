#pragma once

#include <memory>
#include "Visitor.h"

class Camera;

class RenderVisitor : public Visitor
{
public:
    virtual void render(const SceneTree &tree, const std::weak_ptr<Camera> &camera) = 0;
};