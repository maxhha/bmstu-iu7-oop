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
    explicit Vector(const std::initializer_list<T> &items);
    explicit Vector(const Vector<T> &vector);
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
    const T &operator[](size_t index) const;
    T &x();
    const T &x() const;
    T &y();
    const T &y() const;
    T &z();
    const T &z() const;

    /**************************************************************************/
    /*                          Vector Assign operators                       */
    /**************************************************************************/

    Vector<T> &operator=(const Vector<T> &vector);
    Vector<T> &operator=(const std::initializer_list<T> &items);
    Vector<T> &operator=(Vector<T> &&vector) noexcept;

    /**************************************************************************/
    /*                           Vector Public methods                        */
    /**************************************************************************/

    template <typename S>
    S length() const;
    T lengthSquared() const;
    template <typename S>
    Vector<S> normalized() const;
    // double angle() const;
    // double angle(const Vector<T> &vector) const;

    /**************************************************************************/
    /*                           Vector Logic methods                         */
    /**************************************************************************/

    bool isZero() const;
    bool isEqual(const Vector<T> &vector) const;
    bool isNotEqual(const Vector<T> &vector) const;

    bool hasZero() const;

    /**************************************************************************/
    /*                          Vector Logic operators                        */
    /**************************************************************************/

    bool operator==(const Vector<T> &vector) const; // = isEqual
    bool operator!=(const Vector<T> &vector) const; // = isNotEqual

    /**************************************************************************/
    /*                            Vector Math methods                         */
    /**************************************************************************/

    Vector<T> neg() const;
    Vector<T> &negUpdate();

    Vector<T> add(const Vector<T> &vector) const;
    Vector<T> &addUpdate(const Vector<T> &vector);
    Vector<T> addScalar(const T &scalar) const;
    Vector<T> &addScalarUpdate(const T &scalar);

    Vector<T> sub(const Vector<T> &vector) const;
    Vector<T> &subUpdate(const Vector<T> &vector);
    Vector<T> subScalar(const T &scalar) const;
    Vector<T> &subScalarUpdate(const T &scalar);

    Vector<T> mul(const Vector<T> &vector) const;
    Vector<T> &mulUpdate(const Vector<T> &vector);
    Vector<T> mulScalar(const T &scalar) const;
    Vector<T> &mulScalarUpdate(const T &scalar);

    Vector<T> div(const Vector<T> &vector) const;
    Vector<T> &divScalarUpdate(const Vector<T> &vector);
    Vector<T> divScalar(const T &scalar) const;
    Vector<T> &divScalarUpdate(const T &scalar);

    T dot(const Vector<T> &vector) const;

    Vector<T> cross(const Vector<T> &vector) const;
    Vector<T> &crossUpdate(const Vector<T> &vector);

    /**************************************************************************/
    /*                           Vector Math operators                        */
    /**************************************************************************/

    Vector<T> operator-(); // = neg

    Vector<T> &operator+=(const Vector<T> &vector);     // = addUpdate
    Vector<T> &operator+=(const T &scalar);             // = addScalarUpdate
    Vector<T> operator+(const Vector<T> &vector) const; // = add
    Vector<T> operator+(const T &scalar) const;         // = addScalar

    Vector<T> &operator-=(const Vector<T> &vector);     // = subUpdate
    Vector<T> &operator-=(const T &scalar);             // = subScalarUpdate
    Vector<T> operator-(const Vector<T> &vector) const; // = sub
    Vector<T> operator-(const T &scalar) const;         // = subScalar

    Vector<T> &operator*=(const Vector<T> &vector);     // = mulUpdate
    Vector<T> &operator*=(const T &scalar);             // = mulScalarUpdate
    Vector<T> operator*(const Vector<T> &vector) const; // = mul
    Vector<T> operator*(const T &scalar) const;         // = mulScalar

    Vector<T> &operator/=(const Vector<T> &vector);     // = divUpdate
    Vector<T> &operator/=(const T &scalar);             // = divScalarUpdate
    Vector<T> operator/(const Vector<T> &vector) const; // = div
    Vector<T> operator/(const T &scalar) const;         // = divScalar

    T operator&(const Vector<T> &vector) const; // = dot

    Vector<T> operator^(const Vector<T> &vector) const; // = cross
    Vector<T> &operator^=(const Vector<T> &vector);     // = crossUpdate

    // //! Two vectors methods
    // bool collinear(const Vector<Type> &vector) const;
    // bool orthgonal(const Vector<Type> &vector) const; //! Переименовано
    // //< End

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
