#pragma once

#include <map>
#include <string>
#include <memory>
#include <yaml-cpp/yaml.h>
#include "./SceneTreeLoader.h"

class FileSceneTreeLoader : public SceneTreeLoader
{
protected:
    void open(const std::string &source) override;
    void close() override;

    void loadObjectInfo() override;
    bool hasMoreChildren() override;
    void loadChild() override;

private:
    YAML::Node data;
    int currentChild = 0;
};