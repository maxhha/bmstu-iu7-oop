#pragma once

#include <string>
#include "ScreenCreator.h"


class WebGLScreenCreator : public ScreenCreator
{
public:
    explicit WebGLScreenCreator(std::string _canvas) : canvas(_canvas) {};
    std::shared_ptr<Screen> createScreen(int x, int y, int width, int height) override;
private:
    std::string canvas;
};
