#pragma once

#include <memory>
#include "engine/Object/SceneTree/SceneTree.h"

class ObjectMediator
{
public:
    explicit ObjectMediator(std::shared_ptr<SceneTree> _tree) : tree(_tree){};

    std::shared_ptr<SceneTree> getSceneTree() { return tree; }
    virtual void appendChild(const std::string &target, const std::shared_ptr<Object> &object) = 0;

    virtual ~ObjectMediator() = default;

protected:
    const std::string &getName(Object &obj) { return obj.getName(); };

    std::shared_ptr<SceneTree> tree;
};
