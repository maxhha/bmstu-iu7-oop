#pragma once

#include <memory>
#include <string>
#include "Engine.h"

class WebGLEngine : public Engine
{
public:
    WebGLEngine(std::string _canvas) : canvas(_canvas){};

protected:
    std::shared_ptr<NodeSaverSolution> createNodeSaverSolution() override;
    std::shared_ptr<NodeLoaderSolution> createNodeLoaderSolution() override;
    std::shared_ptr<SceneTree> createSceneTree() override;
    std::shared_ptr<ScreenManager> createScreenManager() override;

private:
    std::string canvas;
};
