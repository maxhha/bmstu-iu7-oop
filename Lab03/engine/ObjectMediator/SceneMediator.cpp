#include "SceneMediator.h"
#include <stack>

void SceneMediator::appendChild(const std::string &target, const std::shared_ptr<Object> &object)
{
    auto parent = getNode(target);

    if (parent != nullptr)
    {
        parent->appendChild(object);
    }
}

const std::shared_ptr<Object> SceneMediator::getNode(const std::string &name)
{
    std::shared_ptr<Object> parent;

    if (getName(*tree) == name)
    {
        parent = tree;
    }
    else
    {
        for (auto it = tree->getDFIterator(); it->hasNext();)
        {
            auto obj = it->getNext();

            if (getName(*obj) == name)
            {
                parent = obj;
                break;
            }
        }
    }

    return parent;
}
