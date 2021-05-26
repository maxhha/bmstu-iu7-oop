#pragma once

#include <memory>
#include <string>
#include <yaml-cpp/yaml.h>
#include <engine/Engine/Engine.h>

class EngineCreator
{
public:
    void readConfiguration(const std::string &configfile);
    std::shared_ptr<Engine> getEngine();

private:
    std::shared_ptr<Engine> createEngine();
    std::shared_ptr<Engine> engine;
    YAML::Node config;
};
