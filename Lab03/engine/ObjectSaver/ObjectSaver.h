#pragma once

#include <engine/Object/Object.h>

class ObjectSaver
{
public:
    virtual void save(
        const std::string &target,
        const Object &obj) = 0;
        
    virtual ~ObjectSaver() = default;
};