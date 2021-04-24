#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include "vector.h"

/* ********************************************************************** */
/* *                         Vector Constructors                        * */
/* ********************************************************************** */

template <typename T>
Vector<T>::Vector()
{
    size = 0;
    resetData(0);
};

template <typename T>
Vector<T>::Vector(size_t _size)
{
    size = _size;
    resetData(10);
};

/* ********************************************************************** */
/* *                           Vector Iterators                         * */
/* ********************************************************************** */

template <typename T>
VectorIterator<T> Vector<T>::begin() noexcept
{
    VectorIterator<T> it(*this);
    return it;
}

template <typename T>
VectorIterator<T> Vector<T>::end() noexcept
{
    VectorIterator<T> it(*this);
    return it + size;
}

/* ********************************************************************** */
/* *                        Vector Private methods                      * */
/* ********************************************************************** */

template <typename T>
void Vector<T>::resetData(size_t _size)
{
    try
    {
        data.reset(new T[_size]);
    }
    catch (std::bad_alloc &e)
    {
        throw BadAllocException(__FILE__, __LINE__, "Cant alloc for vector data");
    }
}

#endif // __VECTOR_HPP__
