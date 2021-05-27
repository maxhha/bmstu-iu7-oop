#pragma once

#include <QGraphicsScene>
#include <engine/Engine/Engine.h>

class QtEngine : public Engine
{
public:
    using VecStr = std::vector<std::string>;

    QtEngine() = delete;
    QtEngine(const VecStr &_loaders, const VecStr &_savers, QGraphicsScene *_scene)
        : loaders(_loaders), savers(_savers), scene(_scene){};

    ~QtEngine() override = default;

private:
    std::shared_ptr<ObjectLoaderSolution> createObjectLoaderSolution() override;
    std::shared_ptr<ObjectSaverSolution> createObjectSaverSolution() override;
    std::shared_ptr<ObjectMediator> createObjectMediator() override;
    std::shared_ptr<ScreenManager> createScreenManager() override;

    VecStr loaders;
    VecStr savers;
    QGraphicsScene *scene;
};
