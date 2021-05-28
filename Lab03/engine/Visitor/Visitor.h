#pragma once

#include <memory>
#include <string>

class Object;
class SceneTree;
class Model;
class Camera;

class Visitor
{
public:
    virtual void visitSceneTree(SceneTree &tree) = 0;
    virtual void visitModel(Model &model) = 0;
    virtual void visitCamera(Camera &model) = 0;
    virtual ~Visitor() = default;

protected:
    std::shared_ptr<std::vector<std::shared_ptr<Object>>> getChildren(SceneTree &tree);
    template <class T>
    const std::string &getName(const T &obj) { return obj.getName(); };
    template <class T, typename D>
    D &getData(T &obj) { return obj.data; };
};
