#pragma once

#include <memory>
#include "engine/Object/SceneTree/SceneTree.h"

class ObjectMediator
{
public:
    explicit ObjectMediator(std::shared_ptr<SceneTree> _tree) : tree(_tree){};

    const SceneTree &getSceneTree() { return *tree; }
    virtual const std::shared_ptr<Object> &getNode(const std::string &name) = 0;
    virtual void appendChild(const std::string &target, const std::shared_ptr<Object> &object) = 0;

    virtual ~ObjectMediator() = default;

protected:
    const std::string &getName(Object &obj) { return obj.getName(); };

    std::shared_ptr<SceneTree> tree;
};
