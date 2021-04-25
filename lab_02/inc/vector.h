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
    template <typename S>
    Vector<S> normalized() const;
    // double angle() const;
    // double angle(const Vector<T> &vector) const;

    /**************************************************************************/
    /*                           Vector Logic methods                         */
    /**************************************************************************/

    bool isZero() const;
    bool isEqual(const Vector<T> &other) const;
    bool isNotEqual(const Vector<T> &other) const;

    /**************************************************************************/
    /*                          Vector Logic operators                        */
    /**************************************************************************/

    bool operator==(const Vector<T> &other) const;
    bool operator!=(const Vector<T> &other) const;

    // //! Two vectors methods
    // bool collinear(const Vector<Type> &vector) const;
    // bool orthgonal(const Vector<Type> &vector) const; //! Переименовано
    // //< End

    // Type &at(size_t index);
    // const Type &at(size_t index) const;

    // //! Operators overloads

    // Vector<Type> &operator+=(const Vector<Type> &vector);
    // Vector<Type> &operator+=(const Type &element);
    // void sumEq(const Vector<Type> &vector);
    // void sumEq(const Type &element);
    // Vector<Type> operator+(const Vector<Type> &vector) const; //! перенести к +=
    // Vector<Type> operator+(const Type &element) const;
    // Vector<Type> vecSum(const Vector<Type> &vector) const;
    // Vector<Type> sumEl(const Type &element) const;

    // Vector<Type> &operator-=(const Vector<Type> &vector);
    // Vector<Type> &operator-=(const Type &element);
    // void difEq(const Vector<Type> &vector);
    // void difEq(const Type &element);
    // Vector<Type> operator-(const Vector<Type> &vector) const;
    // Vector<Type> operator-(const Type &element) const;
    // Vector<Type> vecDif(const Vector<Type> &vector) const;
    // Vector<Type> difEl(const Type &element) const;

    // Vector<Type> &operator*=(const Vector<Type> &vector);
    // Vector<Type> &operator*=(const Type &element);
    // void mulEq(const Vector<Type> &vector);
    // void mulEq(const Type &element);
    // Vector<Type> operator*(const Vector<Type> &vector) const; //! В новую функцию
    // Vector<Type> operator*(const Type &element) const;
    // Vector<Type> vecMultip(const Vector<Type> &vector) const;
    // Vector<Type> mulEl(const Type &element) const;

    // Type operator&(const Vector<Type> &vector) const; //! Вынесено!
    // Type scalarMult(const Vector<Type> &vector) const;

    // Vector<Type> operator^(const Vector<Type> &vector) const; //! Добавлено векторное произведение
    // Vector<Type> &operator^=(const Vector<Type> &vector);
    // Vector<Type> VectorMult(const Vector<Type> &vector) const;
    // void VectorEq(const Vector<Type> &vector);

    // Vector<Type> &operator/=(const Vector<Type> &vector);
    // Vector<Type> &operator/=(const Type &element);
    // void divEq(const Vector<Type> &vector);
    // void divEq(const Type &element);
    // Vector<Type> operator/(const Vector<Type> &vector) const;
    // Vector<Type> operator/(const Type &element) const;
    // Vector<Type> vecDivid(const Vector<Type> &vector) const;
    // Vector<Type> divEl(const Type &element) const;

    // Vector<Type> operator-();
    // Vector<Type> negative();

private:
    /**************************************************************************/
    /*                           Vector Private data                          */
    /**************************************************************************/

    std::shared_ptr<T[]> data;

    /**************************************************************************/
    /*                          Vector Private methods                        */
    /**************************************************************************/

    void resetData();
    void validateSize() const;
};

#include "vector.hpp"

#endif // __VECTOR_H__
