#pragma once

#include <memory>
#include "engine/Object/SceneTree.h"

class ObjectMediator
{
public:
    explicit ObjectMediator(std::shared_ptr<SceneTree> _tree) : tree(_tree){};
    virtual void appendChild(const std::string &target, const std::shared_ptr<Object> &object) = 0;

    virtual ~ObjectMediator() = default;

protected:
    std::shared_ptr<SceneTree> tree;
};
