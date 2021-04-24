#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstddef>
#include "container.h"
#include "iterator.h"

template <typename T>
class Vector : public Container
{
    friend class VectorIterator<T>;

public:
    /* ********************************************************************** */
    /* *                         Vector Constructors                        * */
    /* ********************************************************************** */
    Vector();

    explicit Vector(size_t size);
    // explicit Vector(const std::initializer_list<Type> &elements);

    // explicit Vector(const Vector<Type> &vector);
    // Vector(Vector<Type> &&vector) noexcept;

    /* ********************************************************************** */
    /* *                         Vector Deconstructor                       * */
    /* ********************************************************************** */
    virtual ~Vector() = default;

    /* ********************************************************************** */
    /* *                           Vector Iterators                         * */
    /* ********************************************************************** */
    VectorIterator<T> begin() noexcept;
    VectorIterator<T> end() noexcept;

protected:
private:
    std::shared_ptr<T[]> data;

    void resetData(size_t _size);
};

#include "vector.hpp"

#endif // __VECTOR_H__
