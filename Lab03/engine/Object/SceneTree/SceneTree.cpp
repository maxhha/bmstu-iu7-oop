#include "SceneTree.h"

void SceneTree::accept(Visitor &visitor)
{
    visitor.visitSceneTree(*this);
}