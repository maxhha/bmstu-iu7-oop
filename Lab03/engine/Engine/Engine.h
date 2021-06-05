#pragma once

#include <memory>

#include <engine/ObjectLoaderSolution/ObjectLoaderSolution.h>
#include <engine/ObjectSaverSolution/ObjectSaverSolution.h>
#include <engine/ObjectManager/ObjectManager.h>
#include <engine/ScreenManager/ScreenManager.h>

class Engine
{
public:
    std::shared_ptr<ObjectLoaderSolution> getObjectLoaderSolution();
    std::shared_ptr<ObjectSaverSolution> getObjectSaverSolution();
    std::shared_ptr<ObjectManager> getObjectManager();
    std::shared_ptr<ScreenManager> getScreenManager();

    virtual ~Engine() = default;

private:
    virtual std::shared_ptr<ObjectLoaderSolution> createObjectLoaderSolution() = 0;
    virtual std::shared_ptr<ObjectSaverSolution> createObjectSaverSolution() = 0;
    virtual std::shared_ptr<ObjectManager> createObjectManager() = 0;
    virtual std::shared_ptr<ScreenManager> createScreenManager() = 0;

    std::shared_ptr<ObjectLoaderSolution> objectLoaderSolution;
    std::shared_ptr<ObjectSaverSolution> objectSaverSolution;
    std::shared_ptr<ObjectManager> objectManager;
    std::shared_ptr<ScreenManager> screenManager;
};
