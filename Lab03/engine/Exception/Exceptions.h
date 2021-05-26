#pragma once

#include "Exception.h"

class AlreadyConfiguredEngineException : public EngineException
{
public:
    AlreadyConfiguredEngineException(std::string file, int line, std::string msg = "")
        : EngineException("AlreadyConfiguredEngineException", file, line, msg){};
};
