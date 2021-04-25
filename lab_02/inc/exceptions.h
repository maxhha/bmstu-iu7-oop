#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include "exception.h"

class ExpiredPointerException : public VectorException
{
public:
    ExpiredPointerException(std::string file, int line, std::string msg = "")
        : VectorException("ExpiredPointerException", file, line, msg){};
};

class BadAllocException : public VectorException
{
public:
    BadAllocException(std::string file, int line, std::string msg = "")
        : VectorException("BadAllocException", file, line, msg){};
};

class OutOfRangeException : public VectorException
{
public:
    OutOfRangeException(std::string file, int line, std::string msg = "")
        : VectorException("OutOfRangeException", file, line, msg){};
};

class EmptyVectorException : public VectorException
{
public:
    EmptyVectorException(std::string file, int line, std::string msg = "")
        : VectorException("EmptyVectorException", file, line, msg){};
};

class InvalidSizeException : public VectorException
{
public:
    InvalidSizeException(std::string file, int line, std::string msg = "")
        : VectorException("InvalidSizeException", file, line, msg){};
};

class MismatchSizeException : public VectorException
{
public:
    MismatchSizeException(std::string file, int line, std::string msg = "")
        : VectorException("MismatchSizeException", file, line, msg){};
};

class ZeroDivisionException : public VectorException
{
public:
    ZeroDivisionException(std::string file, int line, std::string msg = "")
        : VectorException("ZeroDivisionException", file, line, msg){};
};

#endif // __EXCEPTIONS_H__