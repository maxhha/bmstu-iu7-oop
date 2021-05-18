#pragma once

#include <memory>
#include "ScreenCreator/ScreenCreator.h"
#include "ScreenIterator.h"

#include <algorithm>
#include <type_traits>
#include <stdlib.h>
#include <cmath>
#include <malloc.h>

template <class T>
class Vector
{
    std::size_t capacity_, size_;
    T *data_ = nullptr;

    void ensureCapacity(std::size_t desiredCapacity)
    {
        if (desiredCapacity <= capacity_)
            return;
        capacity_ = std::max(capacity_ * 2, desiredCapacity);
        T *newData = static_cast<T *>(realloc(data_, capacity_ * sizeof(T)));
        data_ = newData ?: throw std::bad_alloc();
    }

public:
    Vector(const Vector<T> &other) = delete;
    Vector<T> operator=(const Vector<T> &other) = delete;
    Vector(Vector<T> &&other)
    {
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    Vector(std::size_t n = 0)
        : capacity_{std::max(size_t(1), n)} // default capacity is 1
          ,
          size_{n}, data_{static_cast<T *>(malloc(sizeof(T) * capacity_)) ?: throw std::bad_alloc()}
    {
    }

    T *begin() const
    {
        return data_;
    }

    T *end() const
    {
        return data_ + size_;
    }

    void pushBack(T elem)
    {
        ensureCapacity(size_ + 1);
        data_[size_++] = elem;
    }

    T popBack()
    {
        return data_[--size_];
    }

    T &operator[](size_t ind) const
    {
        return data_[ind];
    }

    T &at(size_t ind) const
    {
        return (ind < size_) ? data_[ind] : throw std::out_of_range("Vector::at");
    }

    size_t capacity() const
    {
        return capacity_;
    }

    ~Vector() noexcept
    {
        free(data_);
    }
};

class ScreenManager
{
public:
    explicit ScreenManager(std::shared_ptr<ScreenCreator> &_creator);

    std::shared_ptr<Screen> addScreen(int x, int y, int width, int height);
    std::shared_ptr<Screen> getScreen(int i);
    ScreenIterator getIterator();
    void render();

private:
    std::shared_ptr<ScreenCreator> creator;
    std::shared_ptr<Vector<std::shared_ptr<Screen>>> screens;
};
