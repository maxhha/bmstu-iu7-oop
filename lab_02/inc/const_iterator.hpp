#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

#include "const_iterator.h"

/**************************************************************************/
/*                   ConstVectorIterator Constructors                     */
/**************************************************************************/

template <typename T>
ConstVectorIterator<T>::ConstVectorIterator(const ConstVectorIterator<T> &it) noexcept
{
    data = it.data;
    size = it.size;
    idx = it.idx;
}

template <typename T>
ConstVectorIterator<T>::ConstVectorIterator(const Vector<T> &vector) noexcept
{
    data = vector.data;
    size = vector.size;
    idx = 0;
}

/**************************************************************************/
/*                ConstVectorIterator Reference operators                 */
/**************************************************************************/

template <typename T>
const T &ConstVectorIterator<T>::operator*() const
{
    validateDataPointer(__LINE__);
    validateIndex(__LINE__);

    return *getRawPointer();
}

template <typename T>
const T *ConstVectorIterator<T>::operator->() const
{
    validateDataPointer(__LINE__);
    validateIndex(__LINE__);

    return getRawPointer();
}

template <typename T>
const T &ConstVectorIterator<T>::operator[](const size_t index) const
{
    validateDataPointer(__LINE__);

    if (idx + index >= size)
    {
        throw OutOfRangeException(__FILE__, __LINE__);
    }

    return *(this + index);
}

/**************************************************************************/
/*                  ConstVectorIterator Math operators                    */
/**************************************************************************/

template <typename T>
ConstVectorIterator<T> &ConstVectorIterator<T>::operator+=(size_t n)
{
    validateDataPointer(__LINE__);
    idx += n;

    return *this;
}

template <typename T>
ConstVectorIterator<T> ConstVectorIterator<T>::operator+(size_t n) const
{
    validateDataPointer(__LINE__);
    ConstVectorIterator<T> it(*this);
    it += n;

    return it;
}

template <typename T>
ConstVectorIterator<T> &ConstVectorIterator<T>::operator++()
{
    validateDataPointer(__LINE__);
    idx++;

    return *this;
}

template <typename T>
ConstVectorIterator<T> ConstVectorIterator<T>::operator++(int)
{
    validateDataPointer(__LINE__);
    ++(*this);

    return *this;
}

template <typename T>
ConstVectorIterator<T> &ConstVectorIterator<T>::operator-=(size_t n)
{
    validateDataPointer(__LINE__);
    idx -= n;

    return *this;
}

template <typename T>
ConstVectorIterator<T> ConstVectorIterator<T>::operator-(size_t n) const
{
    validateDataPointer(__LINE__);
    ConstVectorIterator<T> it(*this);
    it -= n;

    return it;
}

template <typename T>
ConstVectorIterator<T> &ConstVectorIterator<T>::operator--()
{
    validateDataPointer(__LINE__);
    idx--;

    return *this;
}

template <typename T>
ConstVectorIterator<T> ConstVectorIterator<T>::operator--(int)
{
    validateDataPointer(__LINE__);
    --(*this);

    return *this;
}

/**************************************************************************/
/*                  ConstVectorIterator Logic operators                   */
/**************************************************************************/

template <typename T>
bool ConstVectorIterator<T>::operator==(const ConstVectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx == other.idx;
}

template <typename T>
bool ConstVectorIterator<T>::operator!=(const ConstVectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx != other.idx;
}

template <typename T>
bool ConstVectorIterator<T>::operator<=(const ConstVectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx <= other.idx;
}

template <typename T>
bool ConstVectorIterator<T>::operator>=(const ConstVectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx >= other.idx;
}

template <typename T>
bool ConstVectorIterator<T>::operator<(const ConstVectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx < other.idx;
}

template <typename T>
bool ConstVectorIterator<T>::operator>(const ConstVectorIterator<T> &other) const
{
    validateDataPointer(__LINE__);

    return this->idx > other.idx;
}

/**************************************************************************/
/*                  ConstVectorIterator Private methods                   */
/**************************************************************************/

template <typename T>
void ConstVectorIterator<T>::validateDataPointer(int line) const
{
    if (data.expired())
    {
        throw ExpiredPointerException(__FILE__, line);
    }
}

template <typename T>
void ConstVectorIterator<T>::validateIndex(int line) const
{
    if (idx >= size)
    {
        throw OutOfRangeException(__FILE__, line);
    }
}

template <typename T>
const T *ConstVectorIterator<T>::getRawPointer() const
{
    auto p = data.lock();

    return p.get() + idx;
}

#endif // __CONST_ITERATOR_HPP__