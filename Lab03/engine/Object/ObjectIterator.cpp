#include "ObjectIterator.h"
#include "SceneTree/SceneTree.h"

const std::shared_ptr<std::vector<std::shared_ptr<Object>>> ObjectIterator::getChildren(const SceneTree &tree)
{
    return tree.children;
}

DepthFirstObjectIterator::DepthFirstObjectIterator(const SceneTree &tree)
{
    for (const auto &it : *getChildren(tree))
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
        for (const auto &it : *getChildren(dynamic_cast<SceneTree &>(*obj)))
        {
            stack.push(it);
        }
    }

    return obj;
};

// def process(tree):
//     if not tree.isTree() or tree.children.size() = 0:
//         return [[tree]]

//     paths = []
//     for child in tree.children:
//         for path in process(child):
//             paths.append([tree, ...path])

//     return paths

// def process(tree):
//     if not tree.isTree() or tree.children.size() == 0:
//         yield [tree]
//         return

//     for child in tree.children:
//         for path in process(child):
//             yield [tree, ...path]

// def pprocess(tree):
//     for path in process(tree):
//         for elem in path:
//             yeild elem

PathObjectIterator::PathObjectIterator(const SceneTree &tree)
{
    stack.emplace_back();
    stack[0].push(nullptr);
    stack.emplace_back();

    for (auto &it : *getChildren(tree))
    {
        stack.back().push(it);
    }

    pathI = 1;
    process();
}

void PathObjectIterator::process()
{
    while (stack.size() > 1)
    {
        if (stack.back().size() == 0)
        {
            stack.pop_back();
            stack.back().pop();
            continue;
        }

        auto last = stack.back().top();

        if (!last->isSceneTree())
            break;

        auto children = getChildren(dynamic_cast<SceneTree &>(*last));

        if (children->size() == 0)
            break;

        stack.emplace_back();

        for (auto &it : *children)
        {
            stack.back().push(it);
        }
    }
}

std::shared_ptr<Object> PathObjectIterator::getNext()
{
    auto obj = stack[pathI++].top();

    if (pathI == stack.size())
    {
        pathI = 0;
        stack.back().pop();
        process();
    }

    return obj;
}
