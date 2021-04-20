#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

#include <cstddef>

class Container
{
public:
    Container(size_t size = 0) : size(size){};

    virtual size_t
    getSize() const noexcept
    {
        return size;
    };

    virtual ~Container() = default;

protected:
    size_t size = 0;
};

#endif // __CONTAINER_HPP__
