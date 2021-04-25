#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstddef>
#include "container.h"
#include "iterator.h"

template <typename T>
class Vector : public Container
{
    friend class VectorIterator<T>;

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

    /**************************************************************************/
    /*                          Vector Assign operators                       */
    /**************************************************************************/

    Vector<T> &operator=(const Vector<T> &vector);
    Vector<T> &operator=(const std::initializer_list<T> &items);
    Vector<T> &operator=(Vector<T> &&vector) noexcept;

    // Vector(size_t size, const Type *arrayFrom);
    // Vector(size_t size, Type element);

    // //< End

    // //! Vector bool funcs
    // bool isZeroV() const noexcept;
    // bool isSingleV() const noexcept; //! Переименовано
    // //< End

    // //! One vector methods
    // template <typename TypeOut>
    // TypeOut length() const; //! Сделана специализация для int
    // //! Убрал push, pop
    // template <typename TypeOut>
    // Vector<TypeOut> getUnitV() const; //! Специализация
    // //< End

    // //! Two vectors methods
    // double angle(const Vector<Type> &vector) const;
    // bool collinear(const Vector<Type> &vector) const;
    // bool orthgonal(const Vector<Type> &vector) const; //! Переименовано
    // //< End

    // Type &at(size_t index);
    // const Type &at(size_t index) const;
    // Type &operator[](size_t index);
    // const Type &operator[](size_t index) const;

    // //! Iterator
    // ConstIterator<Type> begin() const noexcept;
    // ConstIterator<Type> end() const noexcept;
    // ConstIterator<Type> cBegin() const noexcept;
    // ConstIterator<Type> cEnd() const noexcept;
    // //< End

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

    // bool operator==(const Vector<Type> &vector) const; //! + методы
    // bool isEqual(const Vector<Type> &vector) const;
    // bool operator!=(const Vector<Type> &vector) const; //! + методы
    // bool isNotEqual(const Vector<Type> &vector) const;

private:
    /**************************************************************************/
    /*                           Vector Private data                          */
    /**************************************************************************/

    std::shared_ptr<T[]> data;

    /**************************************************************************/
    /*                          Vector Private methods                        */
    /**************************************************************************/

    void resetData(void);
};

#include "vector.hpp"

#endif // __VECTOR_H__
