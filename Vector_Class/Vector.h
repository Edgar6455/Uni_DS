#ifndef VECTOR_CLASS_VECTOR_H
#define VECTOR_CLASS_VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
private:
    size_t size_;
    size_t capacity_;
    T* arr = nullptr;

    void relocate()
    {
        capacity_ *= 2;
        T* arr2 = new T[capacity_];

        for(int i = 0; i < size_; ++i)
            arr2[i] = arr[i];

        delete[] arr;
        arr = arr2;
    }


public:

    explicit Vector(size_t size, T elem) : size_(size), capacity_(size_)
    {
        if (size_ == 0 || size_ == 1)
            capacity_ = 2;

        arr = new T[capacity_];

        for (int i = 0; i < size_; ++i) {
            arr[i] = elem;
        }
    }

    explicit Vector(size_t size = 0) : size_(size), capacity_(size_)
    {
        if (size_ == 0 || size_ == 1)
            capacity_ = 2;

        arr = new T[capacity_];
    }


    ~Vector()
    {
        size_ = 0;
        capacity_ = 0;
        delete[] arr;
    }


    Vector(const Vector<T>& other)
    {
        arr = new T[capacity_];
        size_ = other.size_;
        capacity_ = other.capacity_;

        for (int i = 0; i < size_; ++i)
            arr[i] = other.arr[i];

    }

    Vector(Vector<T>&& other)
    {
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr = other.arr;
        other.arr = nullptr;
    }

    Vector<T> &operator=(const Vector<T> &other)
    {
        if (this == &other)
            return *this;

        delete[] arr;
        arr = new T[other.capacity_];
        size_ = other.size_;
        capacity_ = other.capacity_;

        for (int i = 0; i < size_; ++i)
            arr[i] = other.arr[i];

        return *this;
    }

    Vector<T> &operator=(Vector<T> &&other)
    {
        if (this == &other)
            return *this;

        delete[] arr;
        size_ = other.size_;
        capacity_ = other.capacity_;
        arr = other.arr;
        other.arr = nullptr;

        return *this;
    }

    T &operator[](size_t index)
    {
        return arr[index];
    }

    const T &operator[](size_t index) const
    {
        if (index >= size_)
        {
            std::cerr << "Array index out of bound, exiting";
            exit(0);
        }
        return arr[index];
    }

    const T &at(size_t index) const
    {
        if (index >= size_)
        {
            std::cerr << "Array index out of bound, exiting.";
            exit(0);
        }

        return arr[index];
    }

    void push_back(const T& elem)
    {
        if (size_ + 1 > capacity_)
            relocate();
        arr[size_] = elem;
        ++size_;
    }

    void push_back(const T&& elem)
    {
        if (size_ + 1 > capacity_)
            relocate();
        arr[size_] = std::move(elem);
        ++size_;
    }

    void pop_back()
    {
        if (size_ == 0)
        {
            std::cerr << "No value to pop, exiting.";
            exit(0);
        }

        --size_;
    }

    size_t size() const
    {
        return size_;
    }

    size_t capacity() const
    {
        return capacity_;
    }

    bool empty() const
    {
        return size_ == 0;
    }

    void clear()
    {
        delete[] arr;

        capacity_ = 2;
        size_ = 0;

        arr = new T[capacity_];
    }

    void printInfo()
    {
        std::cout << "size: " << size_ << ", capacity: "  << capacity_ <<".\t\t[";

        for (int i = 0; i < size_; ++i)
        {
            std::cout << arr[i];
            if (i != size_ - 1)
                std::cout << ", ";
        }

        std::cout << "]" << std::endl;
    }

};


#endif //VECTOR_CLASS_VECTOR_H
