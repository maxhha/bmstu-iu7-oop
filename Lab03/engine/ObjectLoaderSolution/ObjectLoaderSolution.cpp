#include <engine/Exception/Exceptions.h>
#include <fmt/format.h>
#include "ObjectLoaderSolution.h"

void ObjectLoaderSolution::registration(const std::string &name, const CreateFn createFn)
{
    creators[name] = createFn;
}

std::shared_ptr<ObjectLoader> ObjectLoaderSolution::create(const std::string &name)
{
    if (creators.count(name) == 0)
    {
        throw SolutionNotFoundException(
            __FILE__,
            __LINE__,
            fmt::format("Load solution '{}' not registered", name));
    }

    return creators[name]();
}