#include <yaml-cpp/yaml.h>
#include <engine/Exception/Exceptions.h>
#include "FileModelLoader.h"

void FileModelLoader::open(const std::string &source)
{
    try
    {
        data = YAML::LoadFile(source);
    }
    catch (YAML::Exception &ex)
    {
        throw LoadModelException(__FILE__, __LINE__, ex.msg);
    }
}

void FileModelLoader::close() {}

void FileModelLoader::loadObjectInfo()
{
    try
    {
        builder.setName(data["name"].as<std::string>());
    }
    catch (YAML::Exception &ex)
    {
        throw LoadModelException(__FILE__, __LINE__, ex.msg);
    }
}

void FileModelLoader::loadPoints() {}
void FileModelLoader::loadEdges() {}
