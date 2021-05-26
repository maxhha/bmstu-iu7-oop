#pragma once

#include "Engine.h"

#include <vector>

class QtEngine : public Engine
{
public:
    using VecStr = std::vector<std::string>;
    QtEngine(const VecStr &_loaders, const VecStr &_savers) : loaders(_loaders), savers(_savers){};
    ~QtEngine() override = default;

private:
    std::shared_ptr<ObjectLoaderSolution> createObjectLoaderSolution() override;
    std::shared_ptr<ObjectSaverSolution> createObjectSaverSolution() override;
    std::shared_ptr<SceneMediator> createSceneMediator() override;
    std::shared_ptr<ScreenManager> createScreenManager() override;

    VecStr loaders;
    VecStr savers;
};
