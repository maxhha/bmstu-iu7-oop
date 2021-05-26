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

class ParseConfigException : public EngineException
{
public:
    ParseConfigException(std::string file, int line, std::string msg = "")
        : EngineException("ParseConfigException", file, line, msg){};
};