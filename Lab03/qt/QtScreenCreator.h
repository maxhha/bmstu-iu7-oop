#pragma once

#include <QWidget>
#include <engine/ScreenCreator/ScreenCreator.h>

class QtScreenCreator : public ScreenCreator
{
public:
    QtScreenCreator() = delete;
    explicit QtScreenCreator(QWidget *_widget) : widget(_widget){};

    std::shared_ptr<Screen> createScreen(int x, int y, int width, int height) override;
    ~QtScreenCreator() override = default;

private:
    QWidget *widget;
};