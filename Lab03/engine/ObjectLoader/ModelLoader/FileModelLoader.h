#pragma once

#include <yaml-cpp/yaml.h>
#include "ModelLoader.h"

class FileModelLoader : public ModelLoader
{
public:
    ~FileModelLoader() override = default;

private:
    void open(const std::string &source) override;
    void close() override;

    void loadObjectInfo() override;
    void loadPoints() override;
    void loadEdges() override;

    YAML::Node data;
};
