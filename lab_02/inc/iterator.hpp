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

/**************************************************************************/
/*                     VectorIterator Logic operators                     */
/**************************************************************************/

template <typename T>
bool VectorIterator<T>::operator==(const VectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx == other.idx;
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

#endif // __ITERATOR_HPP__