#pragma once

#include "Engine.h"

class QtEngine : public Engine
{
public:
    ~QtEngine() override = default;

protected:
    std::shared_ptr<ObjectLoaderSolution> createObjectLoaderSolution() override;
    std::shared_ptr<ObjectSaverSolution> createObjectSaverSolution() override;
    std::shared_ptr<SceneMediator> createSceneMediator() override;
    std::shared_ptr<ScreenManager> createScreenManager() override;
};
