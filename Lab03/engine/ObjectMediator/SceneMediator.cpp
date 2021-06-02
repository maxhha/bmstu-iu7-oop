#include "SceneMediator.h"
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include <engine/Object/Model.h>
#include <engine/Object/Camera.h>

void SceneMediator::appendChild(const std::string &target, const std::shared_ptr<Object> &object)
{
    auto parent = get(target);
    parent->appendChild(object);
}

std::shared_ptr<Object> SceneMediator::get(const std::string &name)
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

    if (parent == nullptr)
        throw ObjectNotFoundException(
            __FILE__,
            __LINE__,
            fmt::format("Cant find object '{}' in scene", name));

    return parent;
}

void SceneMediator::rename(const std::string &target, const std::string &newName)
{
    auto obj = get(target);
    setName(*obj, newName);
}

#include <QDebug>

void SceneMediator::remove(const std::string &target)
{
    qDebug() << "remove" << target.c_str();

    std::shared_ptr<Object> parent, obj;

    for (auto it = tree->getPathIterator(); it->hasNext();)
    {
        parent = obj;
        obj = it->getNext();

        if (obj == nullptr)
        {
            qDebug() << "null";
        }
        else
        {
            qDebug() << getName(*obj).c_str();
        }

        if (obj && getName(*obj) == target)
            break;
    }

    if (obj && getName(*obj) == target)
    {
        if (!parent)
        {
            parent = tree;
        }

        parent->removeChild(obj);
    }
    else
    {
        throw ObjectNotFoundException(
            __FILE__,
            __LINE__,
            fmt::format("Cant find object '{}' in scene", target));
    }
}

void SceneMediator::transform(const std::string &target, const Transformation &transform)
{
    auto obj = get(target);

    auto camera = std::dynamic_pointer_cast<Camera>(obj);
    auto model = std::dynamic_pointer_cast<Model>(obj);

    if (camera)
    {
        getData<Camera, Transformation>(*camera).compose(transform);
    }
    else if (model)
    {
        getData<Model, ModelData>(*model).transform(transform);
    }
}