#pragma once

#include "Command.h"

class RenderCommand : public Command
{
public:
    RenderCommand(std::shared_ptr<Engine> _engine) : Command(_engine){};
    void execute() override;
};