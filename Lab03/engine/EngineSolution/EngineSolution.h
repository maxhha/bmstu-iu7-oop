#pragma once

#include <vector>
#include <memory>
#include <map>
#include <string>
#include <yaml-cpp/yaml.h>
#include <engine/Engine/Engine.h>

#include "EngineCreator.h"

class EngineSolution
{
public:
    using VecStr = std::vector<std::string>;
    using CreatorPtr = std::shared_ptr<EngineCreator>;

    void readConfiguration(const std::string &configfile);
    void registration(const std::string &engineType, CreatorPtr &creator) { creators[engineType] = creator; }
    std::shared_ptr<Engine> createEngine();

    ~EngineSolution() = default;

private:
    YAML::Node config;
    std::map<std::string, CreatorPtr> creators;
};
