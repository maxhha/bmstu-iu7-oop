#include "ScreenManager.h"

ScreenManager::ScreenManager(std::shared_ptr<ScreenCreator> &_creator) : creator(_creator), screens(new Vector<std::shared_ptr<Screen>>())
{
}

std::shared_ptr<Screen> ScreenManager::addScreen(int x, int y, int width, int height)
{
    // #TODO: throw exception on no mem
    auto screen = creator->createScreen(x, y, width, height);
    screens->pushBack(screen);

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