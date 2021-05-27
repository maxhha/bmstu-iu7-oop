#include <engine/Object/SceneTree/SceneTree.h>
#include "Visitor.h"

std::shared_ptr<std::vector<std::shared_ptr<Object>>> Visitor::getChildren(SceneTree &tree)
{
    return tree.children;
}