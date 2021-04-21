#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstddef>
#include "container.h"

template<class T>
class Vector: public Container
{
public:
    Vector();

    explicit Vector(size_t size);
    // Vector(const std::initializer_list<Type> &elements);

    // explicit Vector(const Vector<Type> &vector);
    // Vector(Vector<Type> &&vector) noexcept;

    virtual ~Vector() = default;

protected:

private:
    // std::unique_ptr<T[]> data;
};

#endif // __VECTOR_H__
