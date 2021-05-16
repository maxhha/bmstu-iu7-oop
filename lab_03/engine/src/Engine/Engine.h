#pragma once

#include <memory>
#include "NodeLoaderSolution/NodeLoaderSolution.h"
#include "NodeSaverSolution/NodeSaverSolution.h"
#include "Nodes/SceneTree/SceneTree.h"
#include "ScreenManager/ScreenManager.h"

class Engine
{
public:
    std::shared_ptr<NodeSaverSolution> getNodeSaverSolution();
    std::shared_ptr<NodeLoaderSolution> getNodeLoaderSolution();
    std::shared_ptr<SceneTree> getSceneTree();
    std::shared_ptr<ScreenManager> getScreenManager();

protected:
    virtual std::shared_ptr<NodeSaverSolution> createNodeSaverSolution() = 0;
    virtual std::shared_ptr<NodeLoaderSolution> createNodeLoaderSolution() = 0;
    virtual std::shared_ptr<SceneTree> createSceneTree() = 0;
    virtual std::shared_ptr<ScreenManager> createScreenManager() = 0;

private:
    std::shared_ptr<NodeSaverSolution> nodeSaverSolution;
    std::shared_ptr<NodeLoaderSolution> nodeLoaderSolution;
    std::shared_ptr<SceneTree> sceneTree;
    std::shared_ptr<ScreenManager> screenManager;
};