#pragma once

#include <string>
#include <vector>
#include <memory>

#include <engine/Transformation/Transformation.h>
#include "ObjectIterator.h"

class SceneMediator;

class Object
{
    friend SceneMediator;

public:
    Object(
        const std::string &_name,
        const Transformation &_transformation)
        : name(_name), transformation(_transformation){};

    virtual bool isSceneTree() const { return false; };
    virtual void appendChild(std::shared_ptr<Object> &object){};
    virtual std::shared_ptr<ObjectIterator> getDFIterator() { return std::make_shared<DepthFirstObjectIterator>(); };

protected:
    void setName(const std::string &_name) { name = _name; };
    const std::string &getName() const { return name; };

    void setTransformation(const Transformation &_transformation) { transformation = _transformation; };
    const Transformation &getTransformation() const { return transformation; };

private:
    std::string name;
    Transformation transformation;
};
