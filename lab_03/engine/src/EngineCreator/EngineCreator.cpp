#include "EngineCreator.h"
#include "Exception/Exceptions.h"

std::shared_ptr<Engine> createEngine(std::string name)
{
    if (name == "webgl")
    {
        return std::make_shared<WebGLEngine>();
    }

    throw UnknownEngineException();
}