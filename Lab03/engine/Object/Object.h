#pragma once

#include <string>
#include <memory>

#include <engine/Transformation/Transformation.h>

class Object
{
public:
    Object(
        const std::string &_name,
        const Transformation &_transformation)
        : name(_name), transformation(_transformation){};

    const std::string &getName() { return name; };

protected:
    void setName(const std::string &_name) { name = _name; };

    void setTransformation(const Transformation &_transformation) { transformation = _transformation; };
    const Transformation &getTransformation() { return transformation; };

private:
    std::string name;
    Transformation transformation;
};