#pragma once

#include <engine/Transformation/Transformation.h>
#include "Object.h"

class Camera : public Object
{
    friend class Visitor;
    friend class ObjectManager;

public:
    explicit Camera(
        const std::string &_name)
        : Object(_name), data(std::make_unique<Transformation>()){};

    Camera(
        const std::string &_name,
        std::unique_ptr<Transformation> &_data)
        : Object(_name), data(std::move(_data)){};

    void accept(Visitor &visitor) override { visitor.visitCamera(*this); };

    ~Camera() override = default;

protected:
    std::unique_ptr<Transformation> data;
};
