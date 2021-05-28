#pragma once

#include <QWidget>
#include <engine/EngineSolution/EngineCreator.h>
class QtEngineCreator : public EngineCreator
{
public:
    using VecStr = std::vector<std::string>;

    QtEngineCreator() = delete;
    explicit QtEngineCreator(QWidget *_widget) : widget(_widget){};

    std::shared_ptr<Engine> create(const VecStr &loaders, const VecStr &savers) override;

    ~QtEngineCreator() override = default;

private:
    QWidget *widget;
};