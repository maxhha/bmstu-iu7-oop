#include <string>
#include <engine/Exception/Exceptions.h>
#include <engine/Engine/QtEngine.h>
#include <fmt/format.h>
#include "EngineCreator.h"

std::shared_ptr<Engine> EngineCreator::getEngine()
{
    if (engine == nullptr)
    {
        engine = createEngine();
    }

    return engine;
}

void EngineCreator::readConfiguration(const std::string &configfile)
{
    if (engine != nullptr)
    {
        throw AlreadyConfiguredEngineException(__FILE__, __LINE__);
    }

    config = YAML::LoadFile(configfile);
}

std::shared_ptr<Engine> EngineCreator::createEngine()
{
    if (!config.IsDefined())
    {
        throw NoConfigException(__FILE__, __LINE__);
    }

    std::shared_ptr<Engine> engine;

    try
    {
        std::string engineType = config["engine"].as<std::string>();

        if (engineType == "qt")
        {
            engine = std::shared_ptr<Engine>(new QtEngine());
        }
        else
        {
            throw ParseConfigException(
                __FILE__,
                __LINE__,
                fmt::format("Unknown engine '{}'", engineType));
        }
    }
    catch (YAML::Exception &ex)
    {
        throw ParseConfigException(__FILE__, __LINE__, ex.msg);
    }

    return engine;
}