#pragma once

#include <memory>
#include "ScreenCreator/ScreenCreator.h"
#include "ScreenIterator.h"
#include "Vector/Vector.h"

class ScreenManager
{
public:
    explicit ScreenManager(std::shared_ptr<ScreenCreator> &_creator);

    std::shared_ptr<Screen> addScreen(int x, int y, int width, int height);
    std::shared_ptr<Screen> getScreen(int i);
    ScreenIterator getIterator();
    void render();

private:
    std::shared_ptr<ScreenCreator> creator;
    std::shared_ptr<Vector<std::shared_ptr<Screen>>> screens;
};
