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
    resetData();
};

template <typename T>
Vector<T>::Vector(size_t _size)
{
    size = _size;
    resetData();

    for (auto it = begin(); it < end(); ++it)
    {
        *it = 0;
    }
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
void Vector<T>::resetData(void)
{
    try
    {
        data.reset(new T[size]);
    }
    catch (std::bad_alloc &e)
    {
        throw BadAllocException(__FILE__, __LINE__, "Cant alloc for vector data");
    }
}

#endif // __VECTOR_HPP__
