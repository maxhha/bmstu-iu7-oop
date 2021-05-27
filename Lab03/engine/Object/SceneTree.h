#pragma once

#include "Object.h"
#include <QDebug>
#include <engine/SceneMediator/SceneMediator.h>

class SceneTree : public Object
{
    friend class DepthFirstObjectIterator;

public:
    using VecObj = std::vector<std::shared_ptr<Object>>;
    SceneTree(const std::string &_name,
              const Transformation &_transformation)
        : Object(_name, _transformation), children(std::make_shared<VecObj>()){};

    bool isSceneTree() const override { return true; };
    void appendChild(std::shared_ptr<Object> &object) override { children->push_back(object); };
    std::shared_ptr<ObjectIterator> getDFIterator() override { return std::make_shared<DepthFirstObjectIterator>(*this); };

protected:
    std::shared_ptr<std::vector<std::shared_ptr<Object>>> children;
};
