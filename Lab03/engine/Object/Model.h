#pragma once

#include <engine/ModelData/ModelData.h>
#include "Object.h"

class Model : public Object
{
    friend class Visitor;

public:
    Model(
        const std::string &_name,
        const Transformation &_transformation,
        const ModelData &_data)
        : Object(_name, _transformation), data(_data){};

    void accept(Visitor &visitor) override { visitor.visitModel(*this); }

private:
    ModelData data;
};