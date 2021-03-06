#include "FileObjectSaverVisitor.h"
#include <engine/Object/Camera.h>
#include <engine/Object/Model.h>
#include <engine/Object/SceneTree/SceneTree.h>
#include <map>

void FileObjectSaverVisitor::visitSceneTree(SceneTree &sceneTree)
{
    out << YAML::BeginMap;
    out << YAML::Key << "type" << YAML::Value << "SceneTree";
    out << YAML::Key << "name" << YAML::Value << getName<SceneTree>(sceneTree);

    out << YAML::Key << "children" << YAML::Value << YAML::BeginSeq;

    for (auto &it : *getChildren(sceneTree))
    {
        it->accept(*this);
    }

    out << YAML::EndSeq << YAML::EndMap;
}

void FileObjectSaverVisitor::visitCamera(Camera &camera)
{
    out << YAML::BeginMap;
    out << YAML::Key << "type" << YAML::Value << "Camera";
    out << YAML::Key << "name" << YAML::Value << getName<Camera>(camera);
    out << YAML::Key << "transformation" << YAML::Value << YAML::BeginSeq;

    for (const auto &row : getData<Camera, Transformation>(camera)->getMatrix())
    {
        out << YAML::Flow << YAML::BeginSeq;

        for (const auto &it : row)
        {
            out << it;
        }

        out << YAML::EndSeq;
    }

    out << YAML::EndSeq << YAML::EndMap;
}

void FileObjectSaverVisitor::visitModel(Model &model)
{
    out << YAML::BeginMap;
    out << YAML::Key << "type" << YAML::Value << "Model";
    out << YAML::Key << "name" << YAML::Value << getName<Model>(model);

    out << YAML::Key << "points" << YAML::Value << YAML::BeginSeq;

    for (auto &p : getData<Model, ModelData>(model)->getPoints())
    {
        out << YAML::Flow << YAML::BeginSeq;
        out << p.getX() << p.getY() << p.getZ();
        out << YAML::EndSeq;
    }

    out << YAML::EndSeq;

    out << YAML::Key << "edges" << YAML::Value << YAML::BeginSeq;

    for (auto &edge : getData<Model, ModelData>(model)->getEdges())
    {
        out << YAML::Flow << YAML::BeginSeq;
        out << edge.getStartPoint() << edge.getEndPoint();
        out << YAML::EndSeq;
    }

    out << YAML::EndSeq << YAML::EndMap;
}
