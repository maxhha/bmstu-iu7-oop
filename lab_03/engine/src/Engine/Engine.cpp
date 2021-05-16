#include "Engine.h"

std::shared_ptr<NodeSaverSolution> Engine::getNodeSaverSolution()
{
    if (!nodeSaverSolution)
    {
        nodeSaverSolution = createNodeSaverSolution();
    }

    return nodeSaverSolution;
}

std::shared_ptr<NodeLoaderSolution> Engine::getNodeLoaderSolution()
{
    if (!nodeLoaderSolution)
    {
        nodeLoaderSolution = createNodeLoaderSolution();
    }

    return nodeLoaderSolution;
}

std::shared_ptr<SceneTree> Engine::getSceneTree()
{
    if (!sceneTree)
    {
        sceneTree = createSceneTree();
    }

    return sceneTree;
}

std::shared_ptr<ScreenManager> Engine::getScreenManager()
{
    if (!screenManager)
    {
        screenManager = createScreenManager();
    }

    return screenManager;
}
