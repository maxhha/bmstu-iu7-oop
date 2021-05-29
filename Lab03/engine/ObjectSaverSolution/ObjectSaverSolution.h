#pragma once

#include <string>
#include <map>
#include <engine/ObjectSaver/ObjectSaver.h>

class ObjectSaverSolution
{
public:
    using CreateFn = std::shared_ptr<ObjectSaver> (*)();

    void registration(const std::string &name, const CreateFn createFn);
    std::shared_ptr<ObjectSaver> create(const std::string &name);

    ~ObjectSaverSolution() = default;

private:
    std::map<std::string, CreateFn> creators;
};