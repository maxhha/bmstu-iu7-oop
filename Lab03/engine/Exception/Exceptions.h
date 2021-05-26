#pragma once

#include "Exception.h"

class AlreadyConfiguredEngineException : public EngineException
{
public:
    AlreadyConfiguredEngineException(std::string file, int line, std::string msg = "")
        : EngineException("AlreadyConfiguredEngineException", file, line, msg){};
};

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