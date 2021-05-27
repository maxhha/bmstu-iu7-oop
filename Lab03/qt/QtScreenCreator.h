#pragma once

#include <QGraphicsScene>
#include <engine/ScreenCreator/ScreenCreator.h>

class QtScreenCreator : public ScreenCreator
{
public:
    QtScreenCreator() = delete;
    explicit QtScreenCreator(QGraphicsScene *_scene) : scene(_scene){};

    std::shared_ptr<Screen> createScreen(int x, int y, int width, int height) override;
    ~QtScreenCreator() override = default;

private:
    QGraphicsScene *scene;
};