#include "SceneManager.h"
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include <engine/Object/Model.h>
#include <engine/Object/Camera.h>

void SceneManager::appendChild(const std::string &target, const std::shared_ptr<Object> object)
{
    auto parent = get(target);
    parent->appendChild(object);
}

std::shared_ptr<Object> SceneManager::get(const std::string &name)
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
                parent = obj;
        }
    }

    if (parent == nullptr)
        throw ObjectNotFoundException(
            __FILE__,
            __LINE__,
            fmt::format("Cant find object '{}' in scene", name));

    return parent;
}

void SceneManager::rename(const std::string &target, const std::string &newName)
{
    auto obj = get(target);
    setName(*obj, newName);
}

#include <QDebug>

void SceneManager::remove(const std::string &target)
{
    qDebug() << "remove" << target.c_str();

    std::shared_ptr<Object> parent, obj;
    std::shared_ptr<Object> targetParent, targetObj;

    for (auto it = tree->getPathIterator(); it->hasNext();)
    {
        parent = obj;
        obj = it->getNext();

        if (obj && getName(*obj) == target)
        {
            targetParent = parent;
            targetObj = obj;
        }
    }

    if (targetObj && getName(*targetObj) == target)
    {
        if (!targetParent)
        {
            targetParent = tree;
        }

        targetParent->removeChild(obj);
    }
    else
    {
        throw ObjectNotFoundException(
            __FILE__,
            __LINE__,
            fmt::format("Cant find object '{}' in scene", target));
    }
}

void SceneManager::transform(const std::string &target, const Transformation &transform)
{
    auto obj = get(target);

    auto camera = std::dynamic_pointer_cast<Camera>(obj);
    auto model = std::dynamic_pointer_cast<Model>(obj);

    if (camera)
    {
        getData<Camera, Transformation>(*camera)->compose(transform);
    }
    else if (model)
    {
        getData<Model, ModelData>(*model)->transform(transform);
    }
}
