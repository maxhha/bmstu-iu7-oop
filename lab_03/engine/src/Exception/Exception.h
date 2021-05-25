#pragma once

#include <iostream>

class EngineException : public std::exception
{
public:
    EngineException(std::string name, std::string file, int line, std::string msg);
    virtual const char *what() const noexcept override;

    virtual ~EngineException(){};

protected:
    std::string message;
};
