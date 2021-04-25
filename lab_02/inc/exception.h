#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>

class VectorException : public std::exception
{
public:
    VectorException(std::string name, std::string file, int line, std::string msg);
    virtual const char *what() const noexcept override;

    virtual ~VectorException(){};

protected:
    std::string message;
};

#include "exception.hpp"

#endif // __EXCEPTION_H__