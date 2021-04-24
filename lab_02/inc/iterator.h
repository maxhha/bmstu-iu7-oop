#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "exceptions.h"

template <typename T>
class Vector;

template <typename T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T>
{

public:
    /**************************************************************************/
    /*                      VectorIterator Constructors                       */
    /**************************************************************************/

    VectorIterator(const VectorIterator<T> &iterator) noexcept;
    VectorIterator(const Vector<T> &vector) noexcept;

    /**************************************************************************/
    /*                   VectorIterator Reference operators                   */
    /**************************************************************************/

    T &operator*();
    const T &operator*() const;
    T *operator->();
    const T *operator->() const;

    T &operator[](const size_t index);
    const T &operator[](const size_t index) const;

    /**************************************************************************/
    /*                     VectorIterator Math operators                      */
    /**************************************************************************/

    VectorIterator<T> &operator+=(size_t n);
    VectorIterator<T> operator+(size_t n) const;
    VectorIterator<T> &operator++();
    VectorIterator<T> operator++(int);

    VectorIterator<T> &operator-=(size_t n);
    VectorIterator<T> operator-(size_t n) const;
    VectorIterator<T> &operator--();
    VectorIterator<T> operator--(int);

    /**************************************************************************/
    /*                     VectorIterator Logic operators                     */
    /**************************************************************************/

    bool operator<(const VectorIterator<T> &other) const;
    bool operator<=(const VectorIterator<T> &other) const;
    bool operator==(const VectorIterator<T> &other) const;
    bool operator!=(const VectorIterator<T> &other) const;
    bool operator>=(const VectorIterator<T> &other) const;
    bool operator>(const VectorIterator<T> &other) const;

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
    T *getRawPointer() const;
};

#include "iterator.hpp"

#endif // __ITERATOR_H__