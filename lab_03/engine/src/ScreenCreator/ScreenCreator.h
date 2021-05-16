#pragma once

#include <memory>
#include "Screen/Screen.h"

class ScreenCreator
{
public:
    virtual std::shared_ptr<Screen> createScreen(int x, int y, int width, int height) = 0;
};
