#pragma once

#include <memory>

#include <engine/ObjectLoaderSolution/ObjectLoaderSolution.h>
#include <engine/ObjectSaverSolution/ObjectSaverSolution.h>
#include <engine/SceneMediator/SceneMediator.h>
#include <engine/ScreenManager/ScreenManager.h>

class Engine
{
public:
    std::shared_ptr<ObjectLoaderSolution> getObjectLoaderSolution();
    std::shared_ptr<ObjectSaverSolution> getObjectSaverSolution();
    std::shared_ptr<SceneMediator> getSceneMediator();
    std::shared_ptr<ScreenManager> getScreenManager();

    virtual ~Engine() = default;

protected:
    virtual std::shared_ptr<ObjectLoaderSolution> createObjectLoaderSolution() = 0;
    virtual std::shared_ptr<ObjectSaverSolution> createObjectSaverSolution() = 0;
    virtual std::shared_ptr<SceneMediator> createSceneMediator() = 0;
    virtual std::shared_ptr<ScreenManager> createScreenManager() = 0;

private:
    std::shared_ptr<ObjectLoaderSolution> objectLoaderSolution;
    std::shared_ptr<ObjectSaverSolution> objectSaverSolution;
    std::shared_ptr<SceneMediator> sceneMediator;
    std::shared_ptr<ScreenManager> screenManager;
};
