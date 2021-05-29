#pragma once

#include <engine/Engine/Engine.h>

class Command
{

public:
    Command() = delete;
    Command(std::shared_ptr<Engine> &_engine) : engine(_engine){};

    virtual void execute() = 0;

    virtual ~Command() = default;

protected:
    std::shared_ptr<Engine> engine;
};