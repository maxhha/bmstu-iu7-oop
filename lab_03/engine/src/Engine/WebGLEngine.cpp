#include "ScreenCreator/WebGLScreenCreator.h"
#include "WebGLEngine.h"

std::shared_ptr<NodeSaverSolution> WebGLEngine::createNodeSaverSolution()
{
    return std::shared_ptr<NodeSaverSolution>(new NodeSaverSolution());
}

std::shared_ptr<NodeLoaderSolution> WebGLEngine::createNodeLoaderSolution()
{
    return std::shared_ptr<NodeLoaderSolution>(new NodeLoaderSolution());
}

std::shared_ptr<SceneTree> WebGLEngine::createSceneTree()
{
    return std::shared_ptr<SceneTree>(new SceneTree());
}

std::shared_ptr<ScreenManager> WebGLEngine::createScreenManager()
{
    auto creator = std::shared_ptr<ScreenCreator>(new WebGLScreenCreator(canvas));
    auto manager = std::shared_ptr<ScreenManager>(new ScreenManager(creator));

    manager->addScreen(0, 0, 1024, 720);

    return manager;
}
