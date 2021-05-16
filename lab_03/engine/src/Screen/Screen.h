#pragma once

#include <memory>

#include "Nodes/Camera/Camera.h"
#include "Visitor/RenderVisitor.h"

class Screen
{
public:
    Screen(std::shared_ptr<RenderVisitor> _visitor, int _x, int _y, int _width, int _height) : visitor(_visitor), x(_x), y(_y), width(_width), height(_height){};

    void setCamera(std::weak_ptr<Camera> _camera) { camera = _camera; };

    int getX() { return x; };
    int getY() { return y; };
    int getWidth() { return width; };
    int getHeight() { return height; };

    void render();

private:
    int x;
    int y;
    int width;
    int height;
    std::weak_ptr<Camera> camera;
    std::shared_ptr<RenderVisitor> visitor;
};