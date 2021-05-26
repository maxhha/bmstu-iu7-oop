#include "QtEngine.h"

std::shared_ptr<ObjectLoaderSolution> QtEngine::createObjectLoaderSolution()
{
    return std::shared_ptr<ObjectLoaderSolution>(new ObjectLoaderSolution());
}

std::shared_ptr<ObjectSaverSolution> QtEngine::createObjectSaverSolution()
{
    return std::shared_ptr<ObjectSaverSolution>(new ObjectSaverSolution());
}

std::shared_ptr<SceneMediator> QtEngine::createSceneMediator()
{
    return std::shared_ptr<SceneMediator>(new SceneMediator());
}

std::shared_ptr<ScreenManager> QtEngine::createScreenManager()
{
    return std::shared_ptr<ScreenManager>(new ScreenManager());
}
