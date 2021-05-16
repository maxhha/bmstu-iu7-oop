#include "ScreenManager.h"

std::shared_ptr<Screen> ScreenManager::addScreen(int x, int y, int width, int height)
{
    auto screen = creator->createScreen(x, y, width, height);
    screens->push_back(creator->createScreen(x, y, width, height));

    return screen;
}
std::shared_ptr<Screen> ScreenManager::getScreen(int i)
{
    return (*screens)[i];
}

ScreenIterator ScreenManager::getIterator()
{
    ScreenIterator iter;
    return iter;
}

void ScreenManager::render()
{
    for (auto &screen : *screens)
    {
        screen->render();
    }

    return;
}