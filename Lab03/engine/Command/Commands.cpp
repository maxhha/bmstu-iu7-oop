#include "Commands.h"
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include <engine/Object/Camera.h>

void RenderCommand::execute()
{
    engine->getScreenManager()->render(*engine->getObjectManager()->getSceneTree());
}

void LoadSceneTreeCommand::execute()
{
    auto obj = engine->getObjectLoaderSolution()->create("FileSceneTree")->load(filename);
    engine->getObjectManager()->appendChild(target, obj);
}

void AddCameraCommand::execute()
{
    auto obj = std::make_shared<Camera>(name, Transformation());

    engine->getObjectManager()->appendChild(target, obj);
}

void LoadModelCommand::execute()
{
    auto obj = engine->getObjectLoaderSolution()->create("FileModel")->load(filename);
    engine->getObjectManager()->appendChild(target, obj);
}

void TranslateObjectCommand::execute()
{
    Transformation m;
    m.translate(x, y, z);

    engine->getObjectManager()->transform(target, m);
}

void ScaleObjectCommand::execute()
{
    Transformation m;
    m.scale(x, y, z);

    engine->getObjectManager()->transform(target, m);
}

void RotateObjectCommand::execute()
{
    Transformation m;
    m.rotate(x, y, z, a);

    engine->getObjectManager()->transform(target, m);
}

void RenameObjectCommand::execute()
{
    engine->getObjectManager()->rename(target, newName);
}

void RemoveObjectCommand::execute()
{
    engine->getObjectManager()->remove(target);
}

void SetScreenCameraCommand::execute()
{
    auto obj = engine->getObjectManager()->get(camera);
    auto cam = std::dynamic_pointer_cast<Camera>(obj);

    if (!cam)
        throw ObjectIsNotMatchTypeException(
            __FILE__,
            __LINE__,
            fmt::format("Object '{}' must be a camera", camera));

    engine->getScreenManager()->setCamera(id, cam);
}

void AddScreenCommand::execute()
{
    engine->getScreenManager()->addScreen(x1, y1, x2, y2);
}

void RemoveScreenCommand::execute()
{
    engine->getScreenManager()->removeScreen(id);
}
