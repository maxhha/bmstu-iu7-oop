#pragma once

#include <memory>
#include <map>
#include "engine/ObjectLoader/ObjectLoader.h"

class ObjectLoaderSolution
{
public:
    using CreateFn = std::shared_ptr<ObjectLoader> (*)();

    void registration(const std::string &name, const CreateFn createFn);
    std::shared_ptr<ObjectLoader> create(const std::string &name);

    ~ObjectLoaderSolution() = default;

private:
    std::map<std::string, CreateFn> creators;
};