#include "Commands.h"
#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include <engine/Object/Camera.h>

void RenderCommand::execute()
{
    engine->getScreenManager()->render(engine->getObjectMediator()->getSceneTree());
}

void LoadSceneTreeCommand::execute()
{
}

void AddCameraCommand::execute()
{
}

void LoadModelCommand::execute()
{
}

void TranslateObjectCommand::execute()
{
    Transformation m;
    m.translate(x, y, z);

    engine->getObjectMediator()->transform(target, m);
}

void ScaleObjectCommand::execute()
{
    Transformation m;
    m.scale(x, y, z);

    engine->getObjectMediator()->transform(target, m);
}

void RotateObjectCommand::execute()
{
    Transformation m;
    m.rotate(x, y, z, a);

    engine->getObjectMediator()->transform(target, m);
}

void RenameObjectCommand::execute()
{
    engine->getObjectMediator()->rename(target, newName);
}

void RemoveObjectCommand::execute()
{
    engine->getObjectMediator()->remove(target);
}

void SetScreenCameraCommand::execute()
{
    auto obj = engine->getObjectMediator()->get(camera);
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
