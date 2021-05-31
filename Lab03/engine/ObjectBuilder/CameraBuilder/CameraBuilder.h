#pragma once

#include "../ObjectBuilder.h"
#include <engine/Transformation/Transformation.h>

class CameraBuilder : public ObjectBuilder
{
public:
    void setTransformation(const std::vector<std::vector<double>> &t) { transformation = Transformation(t); };
    std::shared_ptr<Object> build() override;

    virtual ~CameraBuilder() = default;

private:
    Transformation transformation;
};