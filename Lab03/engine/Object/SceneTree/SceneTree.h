#pragma once

#include "../Object.h"

class SceneTree : public Object
{
public:
    friend class ObjectIterator;
    friend class Visitor;

    using VecObj = std::vector<std::shared_ptr<Object>>;

    explicit SceneTree(const std::string &_name)
        : Object(_name), children(std::make_shared<VecObj>()){};

    bool isSceneTree() const override { return true; };
    void appendChild(const std::shared_ptr<Object> &object) override;
    void removeChild(const std::shared_ptr<Object> &object) override;
    std::shared_ptr<ObjectIterator> getDFIterator() override;
    std::shared_ptr<ObjectIterator> getPathIterator() override;

    void accept(Visitor &visitor) override;

    ~SceneTree() override = default;

protected:
    std::shared_ptr<std::vector<std::shared_ptr<Object>>> children;
};
