#pragma once

#include "Exception.h"

class UnknownEngineException : public EngineException
{
public:
    UnknownEngineException(std::string file, int line, std::string msg = "")
        : EngineException("UnknownEngineException", file, line, msg){};
};

class BadAllocException : public EngineException
{
public:
    BadAllocException(std::string file, int line, std::string msg = "")
        : EngineException("BadAllocException", file, line, msg){};
};

class OutOfRangeException : public EngineException
{
public:
    OutOfRangeException(std::string file, int line, std::string msg = "")
        : EngineException("OutOfRangeException", file, line, msg){};
};

class EngineException : public EngineException
{
public:
    EngineException(std::string file, int line, std::string msg = "")
        : EngineException("EngineException", file, line, msg){};
};

class InvalidSizeException : public EngineException
{
public:
    InvalidSizeException(std::string file, int line, std::string msg = "")
        : EngineException("InvalidSizeException", file, line, msg){};
};

class MismatchSizeException : public EngineException
{
public:
    MismatchSizeException(std::string file, int line, std::string msg = "")
        : EngineException("MismatchSizeException", file, line, msg){};
};

class ZeroDivisionException : public EngineException
{
public:
    ZeroDivisionException(std::string file, int line, std::string msg = "")
        : EngineException("ZeroDivisionException", file, line, msg){};
};
