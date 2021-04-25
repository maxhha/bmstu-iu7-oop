#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include "exception.h"

VectorException::VectorException(std::string name, std::string file,
                                 int line,
                                 std::string msg = "Unknown error")
{
    message = std::string("") +
              "\n" + name + " at " + file + ":" + std::to_string(line) +
              "\n" + msg;
}

const char *VectorException::what() const noexcept
{
    return message.c_str();
}

#endif //  __EXCEPTION_HPP__