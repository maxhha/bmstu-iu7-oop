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

void FileModelLoader::loadPoints()
{
    try
    {
        for (const auto &it : data["points"])
        {
            builder.addPoint(it[0].as<double>(), it[1].as<double>(), it[2].as<double>());
        }
    }
    catch (YAML::Exception &ex)
    {
        throw LoadModelException(__FILE__, __LINE__, ex.msg);
    }
}

void FileModelLoader::loadEdges()
{
    try
    {
        for (const auto &it : data["edges"])
        {
            builder.addEdge(it[0].as<int>(), it[1].as<int>());
        }
    }
    catch (YAML::Exception &ex)
    {
        throw LoadModelException(__FILE__, __LINE__, ex.msg);
    }
}
