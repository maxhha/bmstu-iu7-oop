#include "SceneTree.h"

void SceneTree::appendChild(const std::shared_ptr<Object> &object)
{
    children->push_back(object);
};

void SceneTree::removeChild(const std::shared_ptr<Object> &object)
{
    auto it = children->begin();

    while (it < children->end() && *it != object)
    {
        it++;
    }

    if (it < children->end())
    {
        children->erase(it);
    }
};

std::shared_ptr<ObjectIterator> SceneTree::getDFIterator()
{
    return std::make_shared<DepthFirstObjectIterator>(*this);
};

std::shared_ptr<ObjectIterator> SceneTree::getPathIterator()
{
    return std::make_shared<PathObjectIterator>(*this);
};

void SceneTree::accept(Visitor &visitor)
{
    visitor.visitSceneTree(*this);
}