#include <algorithm>
#include <engine/ObjectLoader/ModelLoader/FileModelLoader.h>
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include "QtEngine.h"

std::shared_ptr<ObjectLoaderSolution> QtEngine::createObjectLoaderSolution()
{
    auto solution = std::shared_ptr<ObjectLoaderSolution>(new ObjectLoaderSolution());

    for (const auto &loaderName : loaders)
    {
        if (loaderName == "file")
        {
            solution->registration(
                "FileModel",
                []() -> std::shared_ptr<ObjectLoader> {
                    return std::make_shared<FileModelLoader>();
                });
        }
        else
        {
            throw ParseConfigException(
                __FILE__,
                __LINE__,
                fmt::format("Unknown loader type '{}' for QtEngine", loaderName));
        }
    }

    return solution;
}

std::shared_ptr<ObjectSaverSolution> QtEngine::createObjectSaverSolution()
{
    return std::shared_ptr<ObjectSaverSolution>(new ObjectSaverSolution());
}

std::shared_ptr<SceneMediator> QtEngine::createSceneMediator()
{
    return std::shared_ptr<SceneMediator>(new SceneMediator());
}

std::shared_ptr<ScreenManager> QtEngine::createScreenManager()
{
    return std::shared_ptr<ScreenManager>(new ScreenManager());
}
