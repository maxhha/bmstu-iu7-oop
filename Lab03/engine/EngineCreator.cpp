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
    return std::shared_ptr<Engine>(new Engine());
}