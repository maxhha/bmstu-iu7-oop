#pragma once

#include <string>
#include <vector>
#include <memory>

#include <engine/Visitor/Visitor.h>
#include <engine/Transformation/Transformation.h>
#include "ObjectIterator.h"

class ObjectMediator;

class Object
{
    friend class ObjectMediator;

public:
    Object(
        const std::string &_name,
        const Transformation &_transformation)
        : name(_name), transformation(_transformation){};

    virtual bool isSceneTree() const { return false; };
    virtual void appendChild(const std::shared_ptr<Object> &object){};
    virtual std::shared_ptr<ObjectIterator> getDFIterator() { return std::make_shared<DepthFirstObjectIterator>(); };
    virtual void accept(Visitor &visitor) = 0;

protected:
    void setName(const std::string &_name)
    {
        name = _name;
    };
    const std::string &getName() const { return name; };

    void setTransformation(const Transformation &_transformation) { transformation = _transformation; };
    const Transformation &getTransformation() const { return transformation; };

private:
    std::string name;
    Transformation transformation;
};
