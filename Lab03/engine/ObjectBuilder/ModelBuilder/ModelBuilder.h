#pragma once

#include <engine/ModelData/ModelData.h>

#include "../ObjectBuilder.h"

class ModelBuilder : public ObjectBuilder
{
public:
    void addPoint(double x, double y, double z) { modelData.addPoint(x, y, z); };
    void addEdge(int p1, int p2) { modelData.addEdge(p1, p2); };
    std::shared_ptr<Object> build() override;

private:
    ModelData modelData;
};