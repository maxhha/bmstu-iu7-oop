#pragma once

#include "../Object.h"

class SceneTree : public Object
{
public:
    friend class DepthFirstObjectIterator;
    friend class Visitor;

    using VecObj = std::vector<std::shared_ptr<Object>>;
    SceneTree(const std::string &_name,
              const Transformation &_transformation)
        : Object(_name, _transformation), children(std::make_shared<VecObj>()){};

    bool isSceneTree() const override { return true; };
    void appendChild(const std::shared_ptr<Object> &object) override { children->push_back(object); };
    std::shared_ptr<ObjectIterator> getDFIterator() override { return std::make_shared<DepthFirstObjectIterator>(*this); };
    void accept(Visitor &visitor) override;

protected:
    std::shared_ptr<std::vector<std::shared_ptr<Object>>> children;
};
