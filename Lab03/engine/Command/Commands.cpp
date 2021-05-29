#include "Commands.h"

void RenderCommand::execute()
{
    engine->getScreenManager()->render(engine->getObjectMediator()->getSceneTree());
}