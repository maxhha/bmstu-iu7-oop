#include <yaml-cpp/yaml.h>
#include <fmt/format.h>
#include <engine/Exception/Exceptions.h>
#include <engine/ObjectBuilder/CameraBuilder/CameraBuilder.h>
#include <engine/ObjectBuilder/ModelBuilder/ModelBuilder.h>
#include "FileSceneTreeLoader.h"

std::shared_ptr<Object> loadSceneTreeChild(const YAML::Node &child);

std::shared_ptr<Object> loadModel(const YAML::Node &data)
{
    ModelBuilder builder;

    builder.setName(data["name"].as<std::string>());

    for (const auto &it : data["points"])
    {
        builder.addPoint(it[0].as<double>(), it[1].as<double>(), it[2].as<double>());
    }

    for (const auto &it : data["edges"])
    {
        builder.addEdge(it[0].as<int>(), it[1].as<int>());
    }

    return builder.build();
}

std::shared_ptr<Object> loadCamera(const YAML::Node &data)
{
    CameraBuilder builder;
    std::vector<std::vector<double>> matrix;

    builder.setName(data["name"].as<std::string>());

    for (const auto &row : data["transformation"])
    {
        std::vector<double> m_row;

        for (const auto &it : row)
        {
            m_row.push_back(it.as<double>());
        }

        matrix.push_back(m_row);
    }

    builder.setTransformation(matrix);

    return builder.build();
}

std::shared_ptr<Object> loadSceneTree(const YAML::Node &data)
{
    SceneTreeBuilder builder;

    builder.setName(data["name"].as<std::string>());

    for (const auto &child : data["children"])
    {
        builder.appendChild(loadSceneTreeChild(child));
    }

    return builder.build();
}

std::shared_ptr<Object> loadSceneTreeChild(const YAML::Node &child)
{
    static std::map<
        std::string,
        std::shared_ptr<Object> (*)(const YAML::Node &)>
        childLoader{
            {"SceneTree", loadSceneTree},
            {"Model", loadModel},
            {"Camera", loadCamera},
        };

    auto childType = child["type"].as<std::string>();

    if (childLoader.count(childType) == 0)
    {
        throw LoadSceneTreeException(
            __FILE__,
            __LINE__,
            fmt::format("Unknown child type '{}'", childType));
    }

    return childLoader[childType](child);
}

void FileSceneTreeLoader::open(const std::string &source)
{
    try
    {
        data = YAML::LoadFile(source);

        if (data["type"] && data["type"].as<std::string>() != "SceneTree")
        {
            throw LoadSceneTreeException(
                __FILE__,
                __LINE__,
                fmt::format(
                    "Field 'type' in file must be 'SceneTree', not '{}'",
                    data["type"].as<std::string>()));
        }
    }
    catch (YAML::Exception &ex)
    {
        throw LoadSceneTreeException(__FILE__, __LINE__, ex.msg);
    }
}

void FileSceneTreeLoader::close() {}

void FileSceneTreeLoader::loadObjectInfo()
{
    try
    {
        builder.setName(data["name"].as<std::string>());
    }
    catch (YAML::Exception &ex)
    {
        throw LoadSceneTreeException(__FILE__, __LINE__, ex.msg);
    }
}

bool FileSceneTreeLoader::hasMoreChildren()
{
    return data["children"].IsSequence() && currentChild < data["children"].size();
}

void FileSceneTreeLoader::loadChild()
{
    try
    {
        auto child = data["children"][currentChild++];

        builder.appendChild(loadSceneTreeChild(child));
    }
    catch (YAML::Exception &ex)
    {
        throw LoadSceneTreeException(__FILE__, __LINE__, ex.msg);
    }
}
