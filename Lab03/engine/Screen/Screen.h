#pragma once

#include <engine/Object/SceneTree/SceneTree.h>
#include <engine/Visitor/RenderVisitor.h>

class Screen
{
public:
    Screen() = delete;
    Screen(int _x, int _y, int _width, int _height, std::unique_ptr<RenderVisitor> _renderer)
        : x(_x),
          y(_y),
          width(_width),
          height(_height),
          renderer(std::move(_renderer)){};

    void render(const SceneTree &tree);

private:
    int x;
    int y;
    int width;
    int height;
    std::unique_ptr<RenderVisitor> renderer;
};
