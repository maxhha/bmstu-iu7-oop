#include "Commands.h"

void RenderCommand::execute()
{
    engine->getScreenManager()->render(engine->getObjectMediator()->getSceneTree());
}

const std::shared_ptr<Object> &NodeCommand::getNode()
{
    return engine->getObjectMediator()->get(nodename);
}
