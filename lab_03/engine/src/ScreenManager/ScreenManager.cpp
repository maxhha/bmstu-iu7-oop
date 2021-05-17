#include "ScreenManager.h"

ScreenManager::ScreenManager(std::shared_ptr<ScreenCreator> &_creator)
{
    creator = _creator;
    screens = std::make_shared<std::shared_ptr<Screen>[MAX_SCREEN_SIZE]>();
    screens_size = 0;
}

std::shared_ptr<Screen> ScreenManager::addScreen(int x, int y, int width, int height)
{
    // #TODO: throw exception on no mem
    auto screen = creator->createScreen(x, y, width, height);

    *(screens.get() + screens_size) = screen;
    screens_size++;

    return screen;
}
std::shared_ptr<Screen> ScreenManager::getScreen(int i)
{
    return *(screens.get() + i);
}

ScreenIterator ScreenManager::getIterator()
{
    ScreenIterator iter;
    return iter;
}

void ScreenManager::render()
{
    (*screens)->render();

    return;
}