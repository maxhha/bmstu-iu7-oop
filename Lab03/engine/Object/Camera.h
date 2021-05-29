#pragma once

#include <engine/Transformation/Transformation.h>
#include "Object.h"

class Camera : public Object
{
    friend Visitor;

public:
    Camera(
        const std::string &_name,
        const Transformation &_data)
        : Object(_name), data(_data){};

    void accept(Visitor &visitor) override { visitor.visitCamera(*this); };

    ~Camera() override = default;

protected:
    Transformation data;
};