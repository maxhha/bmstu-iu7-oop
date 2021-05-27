#include "ScreenManager.h"

void ScreenManager::addScreen(int x, int y, int width, int height)
{
    screens.push_back(creator->createScreen(x, y, width, height));
}

void ScreenManager::render(const SceneTree &tree)
{
    for (const auto &screen : screens)
    {
        screen->render(tree);
    }
}