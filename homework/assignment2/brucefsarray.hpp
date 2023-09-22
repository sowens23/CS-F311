// fsarray.hpp
// Anand Egan
// 2023-9-12
// Header for class FSArray

#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

#include <cstddef>
#include <algorithm>
#include <cassert>

template <typename ValueType, typename SizeType = std::size_t>
class FSArray {
public:
    using value_type = ValueType;
    using size_type = SizeType;

    // Default constructor: Creates an object with size 8 and default-constructed items.
    FSArray() : size_(8), data_(new ValueType[8]) {}

    // 1-parameter constructor: Creates an object with the specified size and default-constructed items.
    explicit FSArray(SizeType size) : size_(size), data_(new ValueType[size]) {}

    // 2-parameter constructor: Creates an object with the specified size and initializes all items with a value.
    FSArray(SizeType size, const ValueType& value) : size_(size), data_(new ValueType[size]) {
        for (SizeType i = 0; i < size_; ++i) {
            data_[i] = value;
        }
    }

    // Destructor: Frees dynamically allocated memory.
    ~FSArray() {
        delete[] data_;
    }

    // Copy constructor
    FSArray(const FSArray& other) : size_(other.size_), data_(new ValueType[other.size_]) {
        for (SizeType i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Move constructor
    FSArray(FSArray&& other) noexcept : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    // Copy assignment operator
    FSArray& operator=(const FSArray& other) {
        if (this != &other) {
            FSArray tmp(other);
            swap(tmp);
        }
        return *this;
    }

    // Move assignment operator
    FSArray& operator=(FSArray&& other) noexcept {
        if (this != &other) {
            swap(other);
        }
        return *this;
    }

    // Bracket operator to access elements
    ValueType& operator[](SizeType index) {
        assert(index < size_);
        return data_[index];
    }

    const ValueType& operator[](SizeType index) const {
        assert(index < size_);
        return data_[index];
    }

    // Member function to get the size
    SizeType size() const {
        return size_;
    }

    // Member function to get the beginning of the array
    ValueType* begin() {
        return data_;
    }

    const ValueType* begin() const {
        return data_;
    }

    // Member function to get the end of the array
    ValueType* end() {
        return data_ + size_;
    }

    const ValueType* end() const {
        return data_ + size_;
    }

    // Equality operator
    bool operator==(const FSArray& other) const {
        if (size_ != other.size_) {
            return false;
        }
        for (SizeType i = 0; i < size_; ++i) {
            if (data_[i] != other.data_[i]) {
                return false;
            }
        }
        return true;
    }

    // Inequality operator
    bool operator!=(const FSArray& other) const {
        return !(*this == other);
    }

    // Comparison operators for lexicographic order
    bool operator<(const FSArray& other) const {
        for (SizeType i = 0; i < size_ && i < other.size_; ++i) {
            if (data_[i] < other.data_[i]) {
                return true;
            } else if (other.data_[i] < data_[i]) {
                return false;
            }
        }
        return size_ < other.size_; // Compare sizes if no difference found
    }

    bool operator<=(const FSArray& other) const {
        return !(other < *this);
    }

    bool operator>(const FSArray& other) const {
        return other < *this;
    }

    bool operator>=(const FSArray& other) const {
        return !(*this < other);
    }

private:
    SizeType size_;
    ValueType* data_;

    // Private swap function for efficient swapping
    void swap(FSArray& other) noexcept {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }
};

#endif // #ifndef FILE_FSARRAY_HPP_INCLUDED
