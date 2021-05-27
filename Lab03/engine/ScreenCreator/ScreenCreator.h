#pragma once

#include <memory>
#include <engine/Screen/Screen.h>

class ScreenCreator
{
public:
    virtual std::shared_ptr<Screen> createScreen(int x, int y, int width, int height) = 0;
    virtual ~ScreenCreator() = default;
};