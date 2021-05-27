#include "SceneMediator.h"
#include <QDebug>
#include <stack>

void SceneMediator::appendChild(const std::string &target, std::shared_ptr<Object> object)
{
    std::shared_ptr<Object> parent;

    if (tree->getName() == target)
    {
        parent = tree;
    }
    else
    {
        for (auto it = tree->getDFIterator(); it->hasNext();)
        {
            auto obj = it->getNext();

            if (obj->getName() == target)
            {
                parent = obj;
                break;
            }
        }
    }

    if (parent != nullptr)
    {
        parent->appendChild(object);
    }
}