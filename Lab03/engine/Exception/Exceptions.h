#pragma once

#include "Exception.h"
class NoConfigException : public EngineException
{
public:
    NoConfigException(std::string file, int line, std::string msg = "")
        : EngineException("NoConfigException", file, line, msg){};
};

class ReadConfigException : public EngineException
{
public:
    ReadConfigException(std::string file, int line, std::string msg = "")
        : EngineException("ReadConfigException", file, line, msg){};
};

class ParseConfigException : public EngineException
{
public:
    ParseConfigException(std::string file, int line, std::string msg = "")
        : EngineException("ParseConfigException", file, line, msg){};
};

class SolutionNotFoundException : public EngineException
{
public:
    SolutionNotFoundException(std::string file, int line, std::string msg = "")
        : EngineException("SolutionNotFoundException", file, line, msg){};
};

class LoadModelException : public EngineException
{
public:
    LoadModelException(std::string file, int line, std::string msg = "")
        : EngineException("LoadModelException", file, line, msg){};
};

class LoadSceneTreeException : public EngineException
{
public:
    LoadSceneTreeException(std::string file, int line, std::string msg = "")
        : EngineException("LoadSceneTreeException", file, line, msg){};
};

class SaveSceneTreeException : public EngineException
{
public:
    SaveSceneTreeException(std::string file, int line, std::string msg = "")
        : EngineException("SaveSceneTreeException", file, line, msg){};
};

class ObjectNotFoundException : public EngineException
{
public:
    ObjectNotFoundException(std::string file, int line, std::string msg = "")
        : EngineException("ObjectNotFoundException", file, line, msg){};
};