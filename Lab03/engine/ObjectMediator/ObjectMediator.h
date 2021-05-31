#pragma once

#include <memory>
#include "engine/Object/SceneTree/SceneTree.h"

class ObjectMediator
{
public:
    explicit ObjectMediator(std::shared_ptr<SceneTree> _tree) : tree(_tree){};

    const SceneTree &getSceneTree() { return *tree; }
    virtual std::shared_ptr<Object> get(const std::string &name) = 0;
    virtual void rename(const std::string &target, const std::string &newName) = 0;
    virtual void remove(const std::string &target) = 0;
    virtual void appendChild(const std::string &target, const std::shared_ptr<Object> &object) = 0;

    virtual ~ObjectMediator() = default;

protected:
    const std::string &getName(Object &obj) { return obj.getName(); };
    void setName(Object &obj, const std::string &name) { obj.setName(name); };

    std::shared_ptr<SceneTree> tree;
};
