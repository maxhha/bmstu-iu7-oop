#pragma once

#include <QWidget>
#include <engine/Engine/Engine.h>

class QtEngine : public Engine
{
public:
    using VecStr = std::vector<std::string>;

    QtEngine() = delete;
    QtEngine(const VecStr &_loaders, const VecStr &_savers, QWidget *_widget)
        : loaders(_loaders), savers(_savers), widget(_widget){};

    ~QtEngine() override = default;

private:
    std::shared_ptr<ObjectLoaderSolution> createObjectLoaderSolution() override;
    std::shared_ptr<ObjectSaverSolution> createObjectSaverSolution() override;
    std::shared_ptr<ObjectMediator> createObjectMediator() override;
    std::shared_ptr<ScreenManager> createScreenManager() override;

    VecStr loaders;
    VecStr savers;
    QWidget *widget;
};
