#include "ObjectIterator.h"
#include "SceneTree.h"

DepthFirstObjectIterator::DepthFirstObjectIterator(const SceneTree &tree)
{
    for (const auto &it : *tree.children)
    {
        stack.push(it);
    }
}

std::shared_ptr<Object> DepthFirstObjectIterator::getNext()
{
    auto obj = stack.top();
    stack.pop();

    if (obj->isSceneTree())
    {
        for (const auto &it : *dynamic_cast<SceneTree &>(*obj).children)
        {
            stack.push(it);
        }
    }

    return obj;
};
