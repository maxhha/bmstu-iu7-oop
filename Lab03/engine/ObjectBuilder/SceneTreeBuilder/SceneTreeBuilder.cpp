#include "SceneTreeBuilder.h"
#include <engine/Object/SceneTree/SceneTree.h>

std::shared_ptr<Object> SceneTreeBuilder::build()
{
    auto tree = std::make_shared<SceneTree>(name);

    for (auto &it : children)
    {
        tree->appendChild(it);
    }

    return tree;
}