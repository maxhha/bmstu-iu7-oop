#include <engine/ObjectLoader/ModelLoader/FileModelLoader.h>
#include <engine/ObjectSaver/SceneTreeSaver/FileSceneTreeSaver.h>
#include <engine/ObjectMediator/SceneMediator.h>
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include "QtEngine.h"
#include "QtScreenCreator.h"

std::shared_ptr<ObjectLoaderSolution> QtEngine::createObjectLoaderSolution()
{
    auto solution = std::make_shared<ObjectLoaderSolution>();

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
    auto solution = std::make_shared<ObjectSaverSolution>();

    for (const auto &saverName : savers)
    {
        if (saverName == "file")
        {
            solution->registration(
                "FileSceneTree",
                []() -> std::shared_ptr<ObjectSaver> {
                    return std::make_shared<FileSceneTreeSaver>();
                });
        }
        else
        {
            throw ParseConfigException(
                __FILE__,
                __LINE__,
                fmt::format("Unknown saver type '{}' for QtEngine", saverName));
        }
    }

    return solution;
}

std::shared_ptr<ObjectMediator> QtEngine::createObjectMediator()
{
    return std::make_shared<SceneMediator>();
}

std::shared_ptr<ScreenManager> QtEngine::createScreenManager()
{
    return std::make_shared<ScreenManager>(
        std::make_unique<QtScreenCreator>(widget));
}
