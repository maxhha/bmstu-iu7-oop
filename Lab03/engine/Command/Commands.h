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
    ScaleObjectCommand(std::shared_ptr<Engine> &_engine, const std::string &_target, double _x, double _y, double _z)
        : Command(_engine), target(_target), x(_x), y(_y), z(_z){};
    void execute() override;

    ~ScaleObjectCommand() override = default;

private:
    std::string target;
    double x;
    double y;
    double z;
};
class RotateObjectCommand : public Command
{
public:
    RotateObjectCommand(std::shared_ptr<Engine> &_engine, const std::string &_target, double _x, double _y, double _z, double _a)
        : Command(_engine), target(_target), x(_x), y(_y), z(_z), a(_a){};
    void execute() override;

    ~RotateObjectCommand() override = default;

private:
    std::string target;
    double x;
    double y;
    double z;
    double a;
};
class RenameObjectCommand : public Command
{
public:
    RenameObjectCommand(std::shared_ptr<Engine> &_engine, const std::string &_target, const std::string &_newName)
        : Command(_engine), target(_target), newName(_newName){};
    void execute() override;

    ~RenameObjectCommand() override = default;

private:
    std::string target;
    std::string newName;
};
class RemoveObjectCommand : public Command
{
public:
    RemoveObjectCommand(std::shared_ptr<Engine> &_engine, const std::string &_target)
        : Command(_engine), target(_target){};
    void execute() override;

    ~RemoveObjectCommand() override = default;

private:
    std::string target;
};
class SetScreenCameraCommand : public Command
{
public:
    SetScreenCameraCommand(std::shared_ptr<Engine> &_engine, int _id, std::string _camera)
        : Command(_engine), id(_id), camera(_camera){};
    void execute() override;

    ~SetScreenCameraCommand() override = default;

private:
    int id;
    std::string camera;
};
class AddScreenCommand : public Command
{
public:
    AddScreenCommand(std::shared_ptr<Engine> &_engine, int _x1, int _y1, int _x2, int _y2)
        : Command(_engine), x1(_x1), x2(_x2), y1(_y1), y2(_y2){};
    void execute() override;

    ~AddScreenCommand() override = default;

private:
    int x1;
    int x2;
    int y1;
    int y2;
};
class RemoveScreenCommand : public Command
{
public:
    RemoveScreenCommand(std::shared_ptr<Engine> &_engine, int _id)
        : Command(_engine), id(_id){};
    void execute() override;

    ~RemoveScreenCommand() override = default;

private:
    int id;
};