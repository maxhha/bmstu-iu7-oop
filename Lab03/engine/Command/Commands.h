#pragma once

#include "Command.h"

class RenderCommand : public Command
{
public:
    RenderCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~RenderCommand() override = default;
};

class NodeCommand : public Command
{
public:
    NodeCommand(
        std::shared_ptr<Engine> &_engine,
        const std::string &_nodename)
        : Command(_engine), nodename(_nodename){};

protected:
    std::string nodename;
    const std::shared_ptr<Object> &getNode();
};
