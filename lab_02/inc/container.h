#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

class Container
{
public:
    Container(size_t size = 0) : size(size){};

    virtual size_t
    getSize() const noexcept;

    virtual bool
    isEmpty() const noexcept;

    virtual ~Container() = 0;

protected:
    size_t size = 0;
};

size_t Container::getSize() const noexcept
{
    return size;
}

bool Container::isEmpty() const noexcept
{
    return size == 0;
}

Container::~Container() {}

#endif // __CONTAINER_HPP__
