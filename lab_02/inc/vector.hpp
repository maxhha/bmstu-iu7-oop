#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cmath>
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

template <typename T>
ConstVectorIterator<T> Vector<T>::begin() const noexcept
{
    return cbegin();
}

template <typename T>
ConstVectorIterator<T> Vector<T>::end() const noexcept
{
    return cend();
}

template <typename T>
ConstVectorIterator<T> Vector<T>::cbegin() const noexcept
{
    ConstVectorIterator<T> it(*this);
    return it;
}

template <typename T>
ConstVectorIterator<T> Vector<T>::cend() const noexcept
{
    ConstVectorIterator<T> it(*this);
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

    for (; it; ++it, ++itOther)
    {
        *it = *itOther;
    }

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const std::initializer_list<T> &items)
{
    size = items.size;
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
/*                           Vector Public Methods                        */
/**************************************************************************/

template <typename T>
template <typename S>
S Vector<T>::length() const
{
    validateSize();

    T sum = 0;
    for (const auto &x : *this)
    {
        sum += x * x;
    }

    return sqrt(sum);
}

template <typename T>
template <typename S>
Vector<S> Vector<T>::normalized() const
{
    S len = length<S>();
    Vector<S> vec(size);

    auto it = vec.begin();
    for (const auto x : *this)
    {
        *it = x / len;
        ++it;
    }

    return vec;
}

/**************************************************************************/
/*                           Vector Logic methods                         */
/**************************************************************************/

template <typename T>
bool Vector<T>::isZero() const
{
    return this->length<double>() < __DBL_EPSILON__;
}

template <typename T>
bool Vector<T>::isEqual(const Vector<T> &other) const
{
    if (size != other.size)
    {
        return false;
    }

    auto it = cbegin();
    for (const auto &x : other)
    {
        if (std::fabs(x - *it) >= __DBL_EPSILON__)
        {
            return false;
        }

        ++it;
    }

    return true;
}

template <typename T>
bool Vector<T>::isNotEqual(const Vector<T> &other) const
{
    return !isEqual(other);
}

/**************************************************************************/
/*                          Vector Logic operators                        */
/**************************************************************************/

template <typename T>
bool Vector<T>::operator==(const Vector<T> &other) const
{
    return isEqual(other);
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &other) const
{
    return !isEqual(other);
}

/**************************************************************************/
/*                          Vector Private methods                        */
/**************************************************************************/

template <typename T>
void Vector<T>::resetData()
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

template <typename T>
void Vector<T>::validateSize() const
{
    if (isEmpty())
    {
        throw EmptyVectorException(__FILE__, __LINE__, "Cant get length of empty vector");
    }
}

#endif // __VECTOR_HPP__
