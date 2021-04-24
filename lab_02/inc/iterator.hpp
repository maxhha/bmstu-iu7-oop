#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include "iterator.h"

/**************************************************************************/
/*                      VectorIterator Constructors                       */
/**************************************************************************/

template <typename T>
VectorIterator<T>::VectorIterator(const VectorIterator<T> &it) noexcept
{
    data = it.data;
    size = it.size;
    idx = it.idx;
}

template <typename T>
VectorIterator<T>::VectorIterator(const Vector<T> &vector) noexcept
{
    data = vector.data;
    size = vector.size;
    idx = 0;
}

/**************************************************************************/
/*                   VectorIterator Reference operators                   */
/**************************************************************************/

template <typename T>
T &VectorIterator<T>::operator*()
{
    validateDataPointer(__LINE__);
    validateIndex(__LINE__);

    return *getRawPointer();
}

template <typename T>
const T &VectorIterator<T>::operator*() const
{
    validateDataPointer(__LINE__);
    validateIndex(__LINE__);

    return *getRawPointer();
}

template <typename T>
T *VectorIterator<T>::operator->()
{
    validateDataPointer(__LINE__);
    validateIndex(__LINE__);

    return getRawPointer();
}

template <typename T>
const T *VectorIterator<T>::operator->() const
{
    validateDataPointer(__LINE__);
    validateIndex(__LINE__);

    return getRawPointer();
}

/**************************************************************************/
/*                     VectorIterator Math operators                      */
/**************************************************************************/

template <typename T>
VectorIterator<T> &VectorIterator<T>::operator+=(size_t n)
{
    validateDataPointer(__LINE__);
    idx += n;

    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator+(size_t n) const
{
    validateDataPointer(__LINE__);
    VectorIterator<T> it(*this);
    it += n;

    return it;
}

template <typename T>
VectorIterator<T> &VectorIterator<T>::operator++()
{
    validateDataPointer(__LINE__);
    idx++;

    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{
    validateDataPointer(__LINE__);
    ++(*this);

    return *this;
}

template <typename T>
VectorIterator<T> &VectorIterator<T>::operator-=(size_t n)
{
    validateDataPointer(__LINE__);
    idx -= n;

    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator-(size_t n) const
{
    validateDataPointer(__LINE__);
    VectorIterator<T> it(*this);
    it -= n;

    return it;
}

template <typename T>
VectorIterator<T> &VectorIterator<T>::operator--()
{
    validateDataPointer(__LINE__);
    idx--;

    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator--(int)
{
    validateDataPointer(__LINE__);
    --(*this);

    return *this;
}

/**************************************************************************/
/*                     VectorIterator Logic operators                     */
/**************************************************************************/

template <typename T>
bool VectorIterator<T>::operator==(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx == other.idx;
}

template <typename T>
bool VectorIterator<T>::operator!=(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx != other.idx;
}

template <typename T>
bool VectorIterator<T>::operator<=(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx <= other.idx;
}

template <typename T>
bool VectorIterator<T>::operator>=(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx >= other.idx;
}

template <typename T>
bool VectorIterator<T>::operator<(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx < other.idx;
}

template <typename T>
bool VectorIterator<T>::operator>(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx > other.idx;
}

/**************************************************************************/
/*                     VectorIterator Private methods                     */
/**************************************************************************/

template <typename T>
void VectorIterator<T>::validateDataPointer(int line) const
{
    if (data.expired())
    {
        throw ExpiredPointerException(__FILE__, line);
    }
}

template <typename T>
void VectorIterator<T>::validateIndex(int line) const
{
    if (idx >= size)
    {
        throw OutOfRangeException(__FILE__, line);
    }
}

template <typename T>
T *VectorIterator<T>::getRawPointer() const
{
    auto p = data.lock();

    return p.get() + idx;
}

#endif // __ITERATOR_HPP__