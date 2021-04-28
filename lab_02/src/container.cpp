#include "container.h"

// FIXED
size_t Container::getSize() const noexcept
{
    return this->size;
}

bool Container::isEmpty() const noexcept
{
    return this->size == 0;
}

Container::~Container() {}