#include "Engine.h"

std::shared_ptr<ObjectLoaderSolution> Engine::getObjectLoaderSolution()
{
    if (objectLoaderSolution == nullptr)
    {
        objectLoaderSolution = createObjectLoaderSolution();
    }

    return objectLoaderSolution;
}

std::shared_ptr<ObjectSaverSolution> Engine::getObjectSaverSolution()
{
    if (objectSaverSolution == nullptr)
    {
        objectSaverSolution = createObjectSaverSolution();
    }

    return objectSaverSolution;
}

std::shared_ptr<ObjectMediator> Engine::getObjectMediator()
{
    if (objectMediator == nullptr)
    {
        objectMediator = createObjectMediator();
    }

    return objectMediator;
}

std::shared_ptr<ScreenManager> Engine::getScreenManager()
{
    if (screenManager == nullptr)
    {
        screenManager = createScreenManager();
    }

    return screenManager;
}