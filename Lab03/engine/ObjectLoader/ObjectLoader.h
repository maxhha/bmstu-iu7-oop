#pragma once

#include <string>
#include <memory>
#include <engine/Object/Object.h>

class ObjectLoader
{
public:
    virtual std::shared_ptr<Object> load(const std::string &source) = 0;
    virtual ~ObjectLoader() = default;
};
