#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstddef>
#include "container.h"
#include "iterator.h"
#include "const_iterator.h"

template <typename T>
class Vector : public Container
{
    friend class VectorIterator<T>;
    friend class ConstVectorIterator<T>;

public:
    /**************************************************************************/
    /*                           Vector Constructors                          */
    /**************************************************************************/

    Vector();
    explicit Vector(size_t size);
    explicit Vector(std::initializer_list<T> items); // FIXED
    explicit Vector(const Vector<T> &vector);
    Vector(size_t size, const T *items);
    Vector(Vector<T> &&vector) noexcept;

    /**************************************************************************/
    /*                           Vector Deconstructor                         */
    /**************************************************************************/

    virtual ~Vector() = default;

    /**************************************************************************/
    /*                             Vector Iterators                           */
    /**************************************************************************/

    VectorIterator<T> begin() noexcept;
    VectorIterator<T> end() noexcept;
    ConstVectorIterator<T> begin() const noexcept;
    ConstVectorIterator<T> end() const noexcept;
    ConstVectorIterator<T> cbegin() const noexcept;
    ConstVectorIterator<T> cend() const noexcept;

    /**************************************************************************/
    /*                        Vector Reference operators                      */
    /**************************************************************************/

    T &operator[](size_t index);
    T &at(size_t index); // FIXED
    const T &operator[](size_t index) const;
    const T &at(size_t index) const; // FIXED

    /**************************************************************************/
    /*                          Vector Assign operators                       */
    /**************************************************************************/

    Vector<T> &operator=(const Vector<T> &vector);
    Vector<T> &operator=(std::initializer_list<T> items); // FIXED
    Vector<T> &operator=(Vector<T> &&vector) noexcept;

    /**************************************************************************/
    /*                           Vector Public methods                        */
    /**************************************************************************/

    template <typename S>
    S length() const;
    T lengthSquared() const;

    template <typename S>
    Vector<S> normalized() const;

    double angleBetween(const Vector<T> &vector) const;

    /**************************************************************************/
    /*                           Vector Logic methods                         */
    /**************************************************************************/

    bool isZero() const;
    bool isEqual(const Vector<T> &vector) const;
    bool operator==(const Vector<T> &vector) const; // = isEqual
    bool isNotEqual(const Vector<T> &vector) const;
    bool operator!=(const Vector<T> &vector) const; // = isNotEqual

    bool isCollinear(const Vector<T> &vector) const;
    bool isPerpendicular(const Vector<T> &vector) const;

    bool hasZero() const noexcept;

    /**************************************************************************/
    /*                            Vector Math methods                         */
    /**************************************************************************/

    Vector<T> neg() const;
    Vector<T> operator-(); // = neg
    Vector<T> &negUpdate();

    template <typename B>
    decltype(auto) add(const Vector<B> &vector) const;
    template <typename B>
    decltype(auto) operator+(const Vector<B> &vector) const; // = add
    template <typename B>
    Vector<T> &addUpdate(const Vector<B> &vector);
    template <typename B>
    Vector<T> &operator+=(const Vector<B> &vector); // = addUpdate
    template <typename B>
    decltype(auto) addScalar(const B &scalar) const;
    template <typename B>
    decltype(auto) operator+(const B &scalar) const; // = addScalar
    template <typename B>
    Vector<T> &addScalarUpdate(const B &scalar);
    template <typename B>
    Vector<T> &operator+=(const B &scalar); // = addScalarUpdate

    template <typename B>
    decltype(auto) sub(const Vector<B> &vector) const;
    template <typename B>
    decltype(auto) operator-(const Vector<B> &vector) const; // = sub
    template <typename B>
    Vector<T> &subUpdate(const Vector<B> &vector);
    template <typename B>
    Vector<T> &operator-=(const Vector<B> &vector); // = subUpdate
    template <typename B>
    decltype(auto) subScalar(const B &scalar) const;
    template <typename B>
    decltype(auto) operator-(const B &scalar) const; // = subScalar
    template <typename B>
    Vector<T> &subScalarUpdate(const B &scalar);
    template <typename B>
    Vector<T> &operator-=(const B &scalar); // = subScalarUpdate

    template <typename B>
    decltype(auto) mul(const Vector<B> &vector) const;
    template <typename B>
    decltype(auto) operator*(const Vector<B> &vector) const; // = mul
    template <typename B>
    Vector<T> &mulUpdate(const Vector<B> &vector);
    template <typename B>
    Vector<T> &operator*=(const Vector<B> &vector); // = mulUpdate
    template <typename B>
    decltype(auto) mulScalar(const B &scalar) const;
    template <typename B>
    decltype(auto) operator*(const B &scalar) const; // = mulScalar
    template <typename B>
    Vector<T> &mulScalarUpdate(const B &scalar);
    template <typename B>
    Vector<T> &operator*=(const B &scalar); // = mulScalarUpdate

    template <typename B>
    decltype(auto) div(const Vector<B> &vector) const;
    template <typename B>
    decltype(auto) operator/(const Vector<B> &vector) const; // = div
    template <typename B>
    Vector<T> &divUpdate(const Vector<B> &vector);
    template <typename B>
    Vector<T> &operator/=(const Vector<B> &vector); // = divUpdate
    template <typename B>
    decltype(auto) divScalar(const B &scalar) const;
    template <typename B>
    decltype(auto) operator/(const B &scalar) const; // = divScalar
    template <typename B>
    Vector<T> &divScalarUpdate(const B &scalar);
    template <typename B>
    Vector<T> &operator/=(const B &scalar); // = divScalarUpdate

    T dot(const Vector<T> &vector) const;
    T operator&(const Vector<T> &vector) const; // = dot

    template <typename B>
    decltype(auto) cross(const Vector<B> &vector) const;
    template <typename B>
    decltype(auto) operator^(const Vector<B> &vector) const; // = cross
    template <typename B>
    Vector<T> &crossUpdate(const Vector<B> &vector);
    template <typename B>
    Vector<T> &operator^=(const Vector<B> &vector); // = crossUpdate

private:
    /**************************************************************************/
    /*                           Vector Private data                          */
    /**************************************************************************/

    std::shared_ptr<T[]> data;

    /**************************************************************************/
    /*                          Vector Private methods                        */
    /**************************************************************************/

    void resetData(int line);
    void validateSize(int line) const;
    void validateSameSize(int line, const Vector<T> &vector) const;
};

#include "vector.hpp"

#endif // __VECTOR_H__
