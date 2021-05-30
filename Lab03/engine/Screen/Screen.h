#pragma once

#include <engine/Object/SceneTree/SceneTree.h>
#include <engine/Visitor/RenderVisitor.h>

class Screen
{
public:
    Screen() = delete;
    explicit Screen(std::unique_ptr<RenderVisitor> _renderer)
        : renderer(std::move(_renderer)){};

    void setCamera(const std::weak_ptr<Camera> &_camera) { camera = _camera; };
    void render(const SceneTree &tree);

private:
    std::unique_ptr<RenderVisitor> renderer;
    std::weak_ptr<Camera> camera;
};
