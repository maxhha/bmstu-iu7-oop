#include "container.h"
// FIXED
size_t Container::getSize() const noexcept
{
    return size;
}

bool Container::isEmpty() const noexcept
{
    return size == 0;
}

Container::~Container() {}