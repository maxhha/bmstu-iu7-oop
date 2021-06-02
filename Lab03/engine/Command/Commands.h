#pragma once

#include "Command.h"
#include <string>
class RenderCommand : public Command
{
public:
    RenderCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~RenderCommand() override = default;
};

class LoadSceneTreeCommand : public Command
{
public:
    LoadSceneTreeCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~LoadSceneTreeCommand() override = default;

private:
};
class AddCameraCommand : public Command
{
public:
    AddCameraCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~AddCameraCommand() override = default;

private:
};
class LoadModelCommand : public Command
{
public:
    LoadModelCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~LoadModelCommand() override = default;

private:
};
class TranslateObjectCommand : public Command
{
public:
    TranslateObjectCommand(std::shared_ptr<Engine> &_engine, const std::string &_target, double _x, double _y, double _z)
        : Command(_engine), target(_target), x(_x), y(_y), z(_z){};
    void execute() override;

    ~TranslateObjectCommand() override = default;

private:
    std::string target;
    double x;
    double y;
    double z;
};
class ScaleObjectCommand : public Command
{
public:
    ScaleObjectCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~ScaleObjectCommand() override = default;

private:
};
class RotateObjectCommand : public Command
{
public:
    RotateObjectCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~RotateObjectCommand() override = default;

private:
};
class RenameObjectCommand : public Command
{
public:
    RenameObjectCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~RenameObjectCommand() override = default;

private:
};
class RemoveObjectCommand : public Command
{
public:
    RemoveObjectCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~RemoveObjectCommand() override = default;

private:
};
class SetScreenCameraCommand : public Command
{
public:
    SetScreenCameraCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~SetScreenCameraCommand() override = default;

private:
};
class AddScreenCommand : public Command
{
public:
    AddScreenCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~AddScreenCommand() override = default;

private:
};
class RemoveScreenCommand : public Command
{
public:
    RemoveScreenCommand(std::shared_ptr<Engine> &_engine) : Command(_engine){};
    void execute() override;

    ~RemoveScreenCommand() override = default;

private:
};