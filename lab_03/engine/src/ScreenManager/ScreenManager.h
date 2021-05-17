#pragma once

#include <memory>
#include "ScreenCreator/ScreenCreator.h"
#include "ScreenIterator.h"

#define MAX_SCREEN_SIZE 6

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
    std::shared_ptr<std::shared_ptr<Screen>[MAX_SCREEN_SIZE]> screens;
    int screens_size;
};
