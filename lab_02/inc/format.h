#ifndef __FORMAT_H__
#define __FORMAT_H__

template <typename... Args>
std::string format(const std::string &format, Args... args);

#include "format.hpp"

#endif // __FORMAT_H__