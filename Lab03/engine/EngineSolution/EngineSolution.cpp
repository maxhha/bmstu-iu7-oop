#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include "EngineSolution.h"

void EngineSolution::readConfiguration(const std::string &configfile)
{
    try
    {
        config = YAML::LoadFile(configfile);
    }
    catch (YAML::Exception &ex)
    {
        throw ReadConfigException(__FILE__, __LINE__, ex.msg);
    }
}

std::shared_ptr<Engine> EngineSolution::createEngine()
{
    if (!config.IsDefined())
    {
        throw NoConfigException(__FILE__, __LINE__);
    }

    std::shared_ptr<Engine> engine;
    std::string engineType;
    std::vector<std::string> loaders, savers;

    try
    {
        engineType = config["engine"].as<std::string>();

        if (config["loaders"])
        {
            for (const auto &it : config["loaders"])
            {
                loaders.push_back(it.as<std::string>());
            }
        }

        if (config["savers"])
        {
            for (const auto &it : config["savers"])
            {
                savers.push_back(it.as<std::string>());
            }
        }
    }
    catch (YAML::Exception &ex)
    {
        throw ParseConfigException(__FILE__, __LINE__, ex.msg);
    }

    if (creators.count(engineType) == 0)
    {
        throw ParseConfigException(
            __FILE__,
            __LINE__,
            fmt::format("Unknown engine '{}'", engineType));
    }

    engine = creators[engineType]->create(loaders, savers);

    return engine;
}