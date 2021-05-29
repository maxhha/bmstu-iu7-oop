#include "ObjectSaverSolution.h"
#include <fmt/format.h>
#include <engine/Exception/Exceptions.h>

void ObjectSaverSolution::registration(const std::string &name, const CreateFn createFn)
{
    creators[name] = createFn;
}

std::shared_ptr<ObjectSaver> ObjectSaverSolution::create(const std::string &name)
{
    if (creators.count(name) == 0)
    {
        throw SolutionNotFoundException(
            __FILE__,
            __LINE__,
            fmt::format("Save solution '{}' not registered", name));
    }

    return creators[name]();
}