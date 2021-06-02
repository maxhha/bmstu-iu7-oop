#include "Commands.h"

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
}

void RemoveObjectCommand::execute()
{
}

void SetScreenCameraCommand::execute()
{
}

void AddScreenCommand::execute()
{
}

void RemoveScreenCommand::execute()
{
}
