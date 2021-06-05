#pragma once

#include <memory>
#include "engine/Object/SceneTree/SceneTree.h"
#include "engine/Transformation/Transformation.h"

class ObjectManager
{
public:
    explicit ObjectManager(std::shared_ptr<SceneTree> _tree) : tree(_tree){};

    std::shared_ptr<SceneTree> getSceneTree() { return tree; }
    virtual std::shared_ptr<Object> get(const std::string &name) = 0;
    virtual void rename(const std::string &target, const std::string &newName) = 0;
    virtual void remove(const std::string &target) = 0;
    virtual void transform(const std::string &target, const Transformation &transform) = 0;
    virtual void appendChild(const std::string &target, const std::shared_ptr<Object> object) = 0;

    virtual ~ObjectManager() = default;

protected:
    const std::string &getName(Object &obj) { return obj.getName(); };
    void setName(Object &obj, const std::string &name) { obj.setName(name); };
    template <class T, typename D>
    D &getData(T &obj) { return obj.data; };

    std::shared_ptr<SceneTree> tree;
};
