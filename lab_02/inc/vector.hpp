#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include "vector.h"

/**************************************************************************/
/*                           Vector Constructors                          */
/**************************************************************************/

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

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &items)
{
    size = items.size();
    resetData();

    auto it = this->begin();

    for (auto &item : items)
    {
        *it = item;
        ++it;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vector)
{
    *this = vector;
}

template <typename T>
Vector<T>::Vector(Vector<T> &&vector) noexcept
{
    size = vector.size;
    data = vector.data;

    vector.size = 0;
    vector.data = nullptr;
}

/**************************************************************************/
/*                             Vector Iterators                           */
/**************************************************************************/

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

/**************************************************************************/
/*                          Vector Assign operators                       */
/**************************************************************************/

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vector)
{
    size = vector.size;
    resetData();

    VectorIterator<T> it(*this);
    VectorIterator<T> itOther(vector);

    for (; it; ++it, ++itFrom)
    {
        *it = *itFrom;
    }

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const std::initializer_list<T> &items)
{
    size = vector.size;
    resetData();

    auto it = begin();
    for (auto &item : items)
    {
        *it = item;
        ++it;
    }

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&vector) noexcept
{
    size = vector.size;
    data = vector.data;

    vector.size = 0;
    vector.data = nullptr;

    return *this;
}

/**************************************************************************/
/*                          Vector Private methods                        */
/**************************************************************************/

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
