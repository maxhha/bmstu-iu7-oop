#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cmath>
#include "vector.h"
#include "format.h"

/**************************************************************************/
/*                           Vector Constructors                          */
/**************************************************************************/

template <typename T>
Vector<T>::Vector()
{
    size = 0;
    resetData(__LINE__);
};

template <typename T>
Vector<T>::Vector(size_t _size)
{
    size = _size;
    resetData(__LINE__);

    for (auto it = begin(); it < end(); ++it)
    {
        *it = 0;
    }
};

template <typename T>
Vector<T>::Vector(size_t _size, const T *items)
{
    size = _size;
    resetData(__LINE__);

    for (auto it = begin(); it < end(); ++it)
    {
        *it = *(items++);
    }
};

template <typename T>
Vector<T>::Vector(std::initializer_list<T> items)
{
    size = items.size();
    resetData(__LINE__);

    auto it = this->begin();

    for (auto &item : items)
    {
        *it = item;
        ++it;
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vector)
{
    *this = vector;
}

template <typename T>
Vector<T>::Vector(Vector<T> &&vector) noexcept
{
    size = vector.size;
    data = vector.data;
}

/**************************************************************************/
/*                             Vector Iterators                           */
/**************************************************************************/

template <typename T>
VectorIterator<T> Vector<T>::begin() noexcept
{
    VectorIterator<T> it(*this);
    return it;
}

template <typename T>
VectorIterator<T> Vector<T>::end() noexcept
{
    VectorIterator<T> it(*this);
    return it + size;
}

template <typename T>
ConstVectorIterator<T> Vector<T>::begin() const noexcept
{
    return cbegin();
}

template <typename T>
ConstVectorIterator<T> Vector<T>::end() const noexcept
{
    return cend();
}

template <typename T>
ConstVectorIterator<T> Vector<T>::cbegin() const noexcept
{
    ConstVectorIterator<T> it(*this);
    return it;
}

template <typename T>
ConstVectorIterator<T> Vector<T>::cend() const noexcept
{
    ConstVectorIterator<T> it(*this);
    return it + size;
}

/**************************************************************************/
/*                        Vector Reference operators                      */
/**************************************************************************/

template <typename T>
T &Vector<T>::operator[](size_t index)
{
    return *(begin() + index);
}

template <typename T>
T &Vector<T>::at(size_t index)
{
    return *(begin() + index);
}

template <typename T>
const T &Vector<T>::operator[](size_t index) const
{
    return *(cbegin() + index);
}

template <typename T>
const T &Vector<T>::at(size_t index) const
{
    return *(cbegin() + index);
}

/**************************************************************************/
/*                          Vector Assign operators                       */
/**************************************************************************/

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vector)
{
    size = vector.size;
    resetData(__LINE__);

    auto it = begin();

    for (const auto &x : vector)
    {
        *it = x;
        ++it;
    }

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(std::initializer_list<T> items)
{
    size = items.size;
    resetData(__LINE__);

    auto it = begin();
    for (auto &item : items)
    {
        *it = item;
        ++it;
    }

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&vector) noexcept
{
    size = vector.size;
    data = vector.data;

    return *this;
}

/**************************************************************************/
/*                           Vector Public Methods                        */
/**************************************************************************/

template <typename T>
template <typename S>
S Vector<T>::length() const
{
    return sqrt(lengthSquared());
}

template <typename T>
T Vector<T>::lengthSquared() const
{
    validateSize(__LINE__);

    T sum = 0;
    for (const auto &x : *this)
    {
        sum += x * x;
    }

    return sum;
}

template <typename T>
template <typename S>
Vector<S> Vector<T>::normalized() const
{
    S len = length<S>();

    if (std::fabs(len) < __DBL_EPSILON__)
    {
        throw ZeroDivisionException(
            __FILE__,
            __LINE__,
            "Cant normalize vector with zero length");
    }

    Vector<S> vec(size);

    auto it = vec.begin();
    for (const auto x : *this)
    {
        *it = x / len;
        ++it;
    }

    return vec;
}

template <typename T>
double Vector<T>::angleBetween(const Vector<T> &vector) const
{
    double l1 = length<double>();
    double l2 = vector.length<double>();

    if (l1 < __DBL_EPSILON__ || l2 < __DBL_EPSILON__)
    {
        throw ZeroDivisionException(
            __FILE__,
            __LINE__,
            format("this.length() = %.3lf, other.length() - %.4lf", l1, l2));
    }

    return acos(dot(vector) / l1 / l2);
}

/**************************************************************************/
/*                           Vector Logic methods                         */
/**************************************************************************/

template <typename T>
bool Vector<T>::isZero() const
{
    return this->length<double>() < __DBL_EPSILON__;
}

template <typename T>
bool Vector<T>::isEqual(const Vector<T> &vector) const
{
    if (size != vector.size)
    {
        return false;
    }

    auto it = cbegin();
    for (const auto &x : vector)
    {
        if (std::fabs(x - *it) >= __DBL_EPSILON__)
        {
            return false;
        }

        ++it;
    }

    return true;
}

template <typename T>
bool Vector<T>::isNotEqual(const Vector<T> &vector) const
{
    return !isEqual(vector);
}

template <typename T>
bool Vector<T>::isCollinear(const Vector<T> &vector) const
{
    return std::fabs(angleBetween(vector)) < __DBL_EPSILON__;
}

template <typename T>
bool Vector<T>::isPerpendicular(const Vector<T> &vector) const
{
    auto angle = std::fabs(angleBetween(vector));
    return std::fabs(angle - M_PI_2) < __DBL_EPSILON__;
}

template <typename T>
bool Vector<T>::hasZero() const noexcept
{
    for (const auto &x : *this)
    {
        if (std::fabs(x) < __DBL_EPSILON__)
        {
            return true;
        }
    }

    return false;
}

/**************************************************************************/
/*                          Vector Logic operators                        */
/**************************************************************************/

template <typename T>
bool Vector<T>::operator==(const Vector<T> &vector) const
{
    return isEqual(vector);
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &vector) const
{
    return !isEqual(vector);
}

/**************************************************************************/
/*                            Vector Math methods                         */
/**************************************************************************/

template <typename T>
Vector<T> Vector<T>::neg() const
{
    Vector<T> v(*this);
    v.negUpdate();
    return v;
}

template <typename T>
Vector<T> &Vector<T>::negUpdate()
{
    for (auto &x : *this)
    {
        x = -x;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::add(const Vector<B> &vector) const
{
    Vector<T> v(*this);
    v.addUpdate(vector);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::addUpdate(const Vector<B> &vector)
{
    validateSameSize(__LINE__, vector);

    auto it = begin();
    for (const auto &x : vector)
    {
        *it += x;
        ++it;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::addScalar(const B &scalar) const
{
    Vector<T> v(*this);
    v.addScalarUpdate(scalar);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::addScalarUpdate(const B &scalar)
{
    for (auto &x : *this)
    {
        x += scalar;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::sub(const Vector<B> &vector) const
{
    Vector<T> v(*this);
    v.subUpdate(vector);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::subUpdate(const Vector<B> &vector)
{
    validateSameSize(__LINE__, vector);

    auto it = begin();
    for (const auto &x : vector)
    {
        *it -= x;
        ++it;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::subScalar(const B &scalar) const
{
    Vector<T> v(*this);
    v.subScalarUpdate(scalar);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::subScalarUpdate(const B &scalar)
{
    for (auto &x : *this)
    {
        x -= scalar;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::mul(const Vector<B> &vector) const
{
    Vector<T> v(*this);
    v.mulUpdate(vector);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::mulUpdate(const Vector<B> &vector)
{
    validateSameSize(__LINE__, vector);

    auto it = begin();
    for (const auto &x : vector)
    {
        *it *= x;
        ++it;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::mulScalar(const B &scalar) const
{
    Vector<T> v(*this);
    v.mulScalarUpdate(scalar);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::mulScalarUpdate(const B &scalar)
{
    for (auto &x : *this)
    {
        x *= scalar;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::div(const Vector<B> &vector) const
{
    Vector<T> v(*this);
    v.divUpdate(vector);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::divUpdate(const Vector<B> &vector)
{
    validateSameSize(__LINE__, vector);

    if (vector.hasZero())
    {
        throw ZeroDivisionException(
            __FILE__,
            __LINE__,
            "Divider has zero coord");
    }

    auto it = begin();
    for (const auto &x : vector)
    {
        *it /= x;
        ++it;
    }

    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::divScalar(const B &scalar) const
{
    Vector<T> v(*this);
    v.divScalarUpdate(scalar);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::divScalarUpdate(const B &scalar)
{
    if (std::fabs(scalar) < __DBL_EPSILON__)
    {
        throw ZeroDivisionException(__FILE__, __LINE__, "Divider is zero");
    }

    for (auto &x : *this)
    {
        x /= scalar;
    }

    return *this;
}

template <typename T>
T Vector<T>::dot(const Vector<T> &vector) const
{
    validateSameSize(__LINE__, vector);
    T sum = 0;

    auto it = cbegin();
    for (const auto &x : vector)
    {
        sum += *it * x;
        ++it;
    }

    return sum;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::cross(const Vector<B> &vector) const
{
    Vector<T> v(*this);
    v.crossUpdate(vector);

    return v;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::crossUpdate(const Vector<B> &vector)
{
    validateSameSize(__LINE__, vector);

    if (size != 3)
    {
        throw InvalidSizeException(
            __FILE__,
            __LINE__,
            "Cross product exists only for vectors of size 3");
    }

    T x = (*this)[1] * vector[2] - (*this)[2] * vector[1];
    T y = (*this)[2] * vector[0] - (*this)[0] * vector[2];
    T z = (*this)[0] * vector[1] - (*this)[1] * vector[0];

    (*this)[0] = x;
    (*this)[1] = y;
    (*this)[2] = z;

    return *this;
}

/**************************************************************************/
/*                           Vector Math operators                        */
/**************************************************************************/

template <typename T>
Vector<T> Vector<T>::operator-()
{
    return this->neg();
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator+=(const Vector<B> &vector)
{
    this->addUpdate(vector);
    return *this;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator+=(const B &scalar)
{
    this.addScalarUpdate(scalar);
    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator+(const Vector<B> &vector) const
{
    return this->add(vector);
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator+(const B &scalar) const
{
    return this->addScalar(scalar);
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator-=(const Vector<B> &vector)
{
    this->subUpdate(vector);
    return *this;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator-=(const B &scalar)
{
    this.subScalarUpdate(scalar);
    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator-(const Vector<B> &vector) const
{
    return this->sub(vector);
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator-(const B &scalar) const
{
    return this->subScalar(scalar);
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator*=(const Vector<B> &vector)
{
    this->mulUpdate(vector);
    return *this;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator*=(const B &scalar)
{
    this.mulScalarUpdate(scalar);
    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator*(const Vector<B> &vector) const
{
    return this->mul(vector);
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator*(const B &scalar) const
{
    return this->mulScalar(scalar);
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator/=(const Vector<B> &vector)
{
    this->divUpdate(vector);
    return *this;
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator/=(const B &scalar)
{
    this.divScalarUpdate(scalar);
    return *this;
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator/(const Vector<B> &vector) const
{
    return this->div(vector);
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator/(const B &scalar) const
{
    return this->divScalar(scalar);
}

template <typename T>
T Vector<T>::operator&(const Vector<T> &vector) const
{
    return this.dot(vector);
}

template <typename T>
template <typename B>
decltype(auto) Vector<T>::operator^(const Vector<B> &vector) const
{
    return this->cross(vector);
}

template <typename T>
template <typename B>
Vector<T> &Vector<T>::operator^=(const Vector<B> &vector)
{
    this->crossUpdate(vector);
    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &vector)
{
    os << "Vector(";

    auto it = vector.cbegin();
    for (; it < vector.cend(); ++it)
    {
        os << *it;
        if (it + 1 < vector.cend())
        {
            os << "; ";
        }
    }

    os << ")";

    return os;
}

/**************************************************************************/
/*                          Vector Private methods                        */
/**************************************************************************/

template <typename T>
void Vector<T>::resetData(int line)
{
    try
    {
        data.reset(new T[size]);
    }
    catch (std::bad_alloc &e)
    {
        throw BadAllocException(__FILE__, line, "Cant alloc for vector data");
    }
}

template <typename T>
void Vector<T>::validateSize(int line) const
{
    if (isEmpty())
    {
        throw EmptyVectorException(__FILE__, line, "Cant get length of empty vector");
    }
}

template <typename T>
template <typename B>
void Vector<T>::validateSameSize(int line, const Vector<B> &vector) const
{
    if (size != vector.getSize())
    {
        throw MismatchSizeException(
            __FILE__,
            line,
            format("this.size = %zu, vector.size = %zu", size, vector.getSize()));
    }
}

#endif // __VECTOR_HPP__
