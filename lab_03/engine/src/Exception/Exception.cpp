#include "Exception.h"

EngineException::EngineException(std::string name, std::string file,
                                 int line,
                                 std::string msg = "Unknown error")
{
    message = std::string("") +
              "\n" + name + " at " + file + ":" + std::to_string(line) +
              "\n" + msg;
}

const char *EngineException::what() const noexcept
{
    return message.c_str();
}
