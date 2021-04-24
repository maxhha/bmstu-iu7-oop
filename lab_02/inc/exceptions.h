#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include "exception.h"

class ExpiredPointerException : public VectorException
{
public:
    ExpiredPointerException(std::string file, int line, std::string msg = "")
        : VectorException(file, line, msg){};
};

class BadAllocException : public VectorException
{
public:
    BadAllocException(std::string file, int line, std::string msg = "")
        : VectorException(file, line, msg){};
};

#endif // __EXCEPTIONS_H__