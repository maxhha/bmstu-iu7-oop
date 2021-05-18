#include "ScreenManager.h"

ScreenManager::ScreenManager(std::shared_ptr<ScreenCreator> &_creator)
{
    creator = _creator;
    screens_size = 0;
}

std::shared_ptr<Screen> ScreenManager::addScreen(int x, int y, int width, int height)
{
    // #TODO: throw exception on no mem
    screen = creator->createScreen(x, y, width, height);
    screens_size++;

    return screen;
}
std::shared_ptr<Screen> ScreenManager::getScreen(int i)
{
    return screen;
}

ScreenIterator ScreenManager::getIterator()
{
    ScreenIterator iter;
    return iter;
}

void ScreenManager::render()
{
    screen->render();

    return;
}