#include "SceneMediator.h"
#include <QDebug>
#include <stack>

void SceneMediator::appendChild(const std::string &target, const std::shared_ptr<Object> &object)
{
    std::shared_ptr<Object> parent;

    if (getName(*tree) == target)
    {
        parent = tree;
    }
    else
    {
        for (auto it = tree->getDFIterator(); it->hasNext();)
        {
            auto obj = it->getNext();

            if (getName(*tree) == target)
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