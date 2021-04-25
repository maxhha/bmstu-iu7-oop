#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

#include "iterator_base.h"

template <typename T>
class ConstVectorIterator : public VectorIteratorBase<T>
{

public:
    /**************************************************************************/
    /*                   ConstVectorIterator Constructors                     */
    /**************************************************************************/

    ConstVectorIterator(const ConstVectorIterator<T> &iterator) noexcept : VectorIteratorBase(iterator){};
    ConstVectorIterator(const Vector<T> &vector) noexcept : VectorIteratorBase(vector){};

    /**************************************************************************/
    /*                ConstVectorIterator Reference operators                 */
    /**************************************************************************/

    const T &operator*() const;
    const T *operator->() const;

    const T &operator[](const size_t index) const;

    /**************************************************************************/
    /*                     VectorIterator Math operators                      */
    /**************************************************************************/

    ConstVectorIterator<T> &operator+=(size_t n);
    ConstVectorIterator<T> operator+(size_t n) const;
    ConstVectorIterator<T> &operator++();
    ConstVectorIterator<T> operator++(int);

    ConstVectorIterator<T> &operator-=(size_t n);
    ConstVectorIterator<T> operator-(size_t n) const;
    ConstVectorIterator<T> &operator--();
    ConstVectorIterator<T> operator--(int);

    /**************************************************************************/
    /*                     ConstVectorIterator Logic operators                     */
    /**************************************************************************/

    bool operator<(const ConstVectorIterator<T> &other) const;
    bool operator<=(const ConstVectorIterator<T> &other) const;
    bool operator==(const ConstVectorIterator<T> &other) const;
    bool operator!=(const ConstVectorIterator<T> &other) const;
    bool operator>=(const ConstVectorIterator<T> &other) const;
    bool operator>(const ConstVectorIterator<T> &other) const;

private:
    /**************************************************************************/
    /*                      VectorIterator Private data                       */
    /**************************************************************************/

    std::weak_ptr<T[]> data;
    size_t idx = 0;
    size_t size = 0;

    /**************************************************************************/
    /*                     VectorIterator Private methods                     */
    /**************************************************************************/

    void validateDataPointer(int line) const;
    void validateIndex(int line) const;
    const T *getRawPointer() const;
};

#include "const_iterator.hpp"

#endif // __CONST_ITERATOR_H__