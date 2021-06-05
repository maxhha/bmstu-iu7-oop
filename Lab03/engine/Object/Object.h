#pragma once

#include <string>
#include <vector>
#include <memory>

#include <engine/Visitor/Visitor.h>
#include <engine/Transformation/Transformation.h>
#include "ObjectIterator.h"

class ObjectManager;

class Object
{
    friend class ObjectManager;

public:
    Object() = delete;
    explicit Object(
        const std::string &_name)
        : name(_name){};

    const std::string &getName() const { return name; };
    virtual bool isSceneTree() const { return false; };
    virtual void appendChild(const std::shared_ptr<Object> &object){};
    virtual void removeChild(const std::shared_ptr<Object> &object){};
    virtual std::shared_ptr<ObjectIterator> getDFIterator() { return std::make_shared<DepthFirstObjectIterator>(); };
    virtual std::shared_ptr<ObjectIterator> getPathIterator() { return std::make_shared<DepthFirstObjectIterator>(); };
    virtual void accept(Visitor &visitor) = 0;

    virtual ~Object() = default;

protected:
    void setName(const std::string &_name) { name = _name; };

private:
    std::string name;
};
