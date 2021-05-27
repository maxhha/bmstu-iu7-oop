#pragma once

#include <QGraphicsScene>
#include <engine/EngineSolution/EngineCreator.h>

class QtEngineCreator : public EngineCreator
{
public:
    using VecStr = std::vector<std::string>;

    QtEngineCreator() = delete;
    explicit QtEngineCreator(QGraphicsScene *_scene) : scene(_scene){};

    std::shared_ptr<Engine> create(const VecStr &loaders, const VecStr &savers) override;

    ~QtEngineCreator() override = default;

private:
    QGraphicsScene *scene;
};