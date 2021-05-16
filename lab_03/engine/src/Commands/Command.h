#pragma once

#include <memory>
#include "Engine/Engine.h"

class Command
{
public:
    explicit Command(std::shared_ptr<Engine> _engine) : engine(_engine){};
    virtual void execute() = 0;

protected:
    std::shared_ptr<Engine> engine;
};