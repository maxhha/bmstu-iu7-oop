#pragma once

#include <memory>
#include <vector>
#include <engine/Screen/Screen.h>
#include <engine/ScreenCreator/ScreenCreator.h>
#include <engine/Object/SceneTree/SceneTree.h>

class ScreenManager
{
public:
    explicit ScreenManager(std::unique_ptr<ScreenCreator> _creator)
        : creator(std::move(_creator)){};
    void addScreen(int x, int y, int width, int height);
    void setCamera(int screen, const std::shared_ptr<Camera> &camera);
    void render(const SceneTree &tree);

    ~ScreenManager() = default;

private:
    std::vector<std::shared_ptr<Screen>> screens;
    std::unique_ptr<ScreenCreator> creator;
};