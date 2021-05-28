#include <engine/ObjectLoader/ModelLoader/FileModelLoader.h>
#include <engine/ObjectMediator/SceneMediator.h>
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include "QtEngine.h"
#include "QtScreenCreator.h"

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

std::shared_ptr<ObjectMediator> QtEngine::createObjectMediator()
{
    return std::shared_ptr<ObjectMediator>(new SceneMediator());
}

std::shared_ptr<ScreenManager> QtEngine::createScreenManager()
{
    return std::make_shared<ScreenManager>(
        std::make_unique<QtScreenCreator>(widget));
}
