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
    /*                     VectorIterator Math operators                      */
    /**************************************************************************/

    VectorIterator<T> &operator+=(size_t n);
    VectorIterator<T> operator+(size_t n) const;

    /**************************************************************************/
    /*                     VectorIterator Logic operators                     */
    /**************************************************************************/

    bool operator==(const VectorIterator<T> &other) const;

    // T &operator*();
    // const T &operator*() const;
    // T *operator->();
    // const T *operator->() const;
    // operator bool() const;

    // VectorIterator<T> &operator=(const VectorIterator<T> &iterator) noexcept;

    // VectorIterator<T> &operator-=(size_t number);
    // VectorIterator<T> operator-(size_t number) const;
    // VectorIterator<T> &operator--();
    // VectorIterator<T> operator--(int);

    // VectorIterator<T> &operator+=(size_t number); // done
    // VectorIterator<T> operator+(size_t number) const; // done
    // VectorIterator<T> &operator++();
    // VectorIterator<T> operator++(int);

    // bool operator<=(const VectorIterator<T> &compareTo) const;
    // bool operator<(const VectorIterator<T> &compareTo) const;
    // bool operator>=(const VectorIterator<T> &compareTo) const;
    // bool operator>(const VectorIterator<T> &compareTo) const;
    // bool operator==(const VectorIterator<T> &compareTo) const; // done
    // bool operator!=(const VectorIterator<T> &compareTo) const;

    // T &operator[](const size_t index);
    // const T &operator[](const size_t index) const;
protected:
private:
    std::weak_ptr<T[]> data;
    size_t idx = 0;
    size_t size = 0;

    void validateDataPointer(int line) const;
};

#include "iterator.hpp"

#endif // __ITERATOR_H__