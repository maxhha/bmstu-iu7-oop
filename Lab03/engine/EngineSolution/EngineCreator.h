#pragma once

#include <memory>
#include <vector>
#include <string>
#include <engine/Engine/Engine.h>

class EngineCreator
{
public:
    using VecStr = std::vector<std::string>;
    virtual std::shared_ptr<Engine> create(const VecStr &loaders, const VecStr &savers) = 0;
    virtual ~EngineCreator() = default;
};