#pragma once

#include <engine/ModelData/ModelData.h>
#include "Object.h"

class Model : public Object
{
    friend class Visitor;
    friend class ObjectManager;

public:
    Model(
        const std::string &_name,
        std::unique_ptr<ModelData> &_data)
        : Object(_name), data(std::move(_data)){};

    void accept(Visitor &visitor) override { visitor.visitModel(*this); }

    ~Model() override = default;

protected:
    std::unique_ptr<ModelData> data;
};
