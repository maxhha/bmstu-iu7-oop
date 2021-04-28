#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

#include <stdlib.h>

class Container
{
public:
    Container(size_t _size = 0) : size(_size){};

    virtual size_t
    getSize() const noexcept;

    virtual bool
    isEmpty() const noexcept;

    virtual ~Container() = 0;

protected:
    size_t size = 0;
};

#endif // __CONTAINER_HPP__
