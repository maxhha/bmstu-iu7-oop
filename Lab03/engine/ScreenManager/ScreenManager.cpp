#include "ScreenManager.h"

void ScreenManager::addScreen(int x, int y, int width, int height)
{
    screens[nextScreenId] = (creator->createScreen(nextScreenId, x, y, width, height));
    nextScreenId++;
}

void ScreenManager::removeScreen(int id)
{
    screens.erase(id);
}

void ScreenManager::render(const SceneTree &tree)
{
    for (const auto &it : screens)
    {
        it.second->render(tree);
    }
}

void ScreenManager::setCamera(int screen, const std::shared_ptr<Camera> &camera)
{
    screens[screen]->setCamera(camera);
}