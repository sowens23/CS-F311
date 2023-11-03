/* 
    Name: Spencer Owens
    Class: 23F CS-311 Data Structures and Algorithms
    Assignment: TheMarvouslySmartArray (Assignment 5)
    Created: 2023-Nov-01
    Updated: 2023-Nov-02

    File Name: tsmarray.hpp
    File Function: 
*/

// msarray.hpp  HAND-OFF
// VERSION 6
// Glenn G. Chappell
// Started: 2023-10-17
// Updated: 2023-10-25
//
// For CS 311 Fall 2023
// Header for class MSArray
// Marvelously smart array of int
// Preliminary to Assignment 5

// History:
// - v1:
//   - Bare-bones only, does not compile. Header & source files,
//     #ifndef, #include, empty class definition.
// - v2:
//   - Add member types value_type, size_type, iterator, const_iterator.
//   - Add dummy versions (at least) of all member functions, including
//     dummy return statements for non-void functions. Package compiles.
//   - Add data members.
//   - Add class invariants.
//   - Write (untested versions of) the following member functions:
//     default ctor, ctor from size (these two are single func), dctor,
//     op[], size, empty, begin, end, push_back, pop_back.
// - v3:
//   - Document exception-safety guarantees for most functions.
//   - Write copy ctor.
// - v4:
//   - Revise class invariants to allow for _data being nullptr if _size
//     is zero.
//   - Revise ctor from size, copy ctor accordingly.
//   - Write move ctor.
//   - Mark various functions as noexcept.
// - v5:
//   - Move func defs to source file: copy & move ops, resize, insert,
//     erase, swap.
// - v6:
//   - Add _capacity data member.
//   - Revise class invariants & ctors accordingly.
//   - Add constant DEFAULT_CAP and use it in setting the capacity in
//     default ctor/ctor from size.

#ifndef FILE_TMSArray_HPP_INCLUDED
#define FILE_TMSArray_HPP_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max
#include <cassert>


// *********************************************************************
// class TMSArray - Class definition
// *********************************************************************


// class TMSArray
// Marvelously Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
template <typename T>
class TMSArray {

// ***** TMSArray: types *****
public:

    // value_type: type of data items
    using value_type = T;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** TMSArray: internal-use constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 42 };

// ***** TMSArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit TMSArray(size_type thesize=0)
        :_capacity(std::max(thesize, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
         _size(thesize),
         _data(_capacity == 0 ? nullptr
                              : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee
    TMSArray(const TMSArray & other)
        :_capacity(other._capacity),
        _size(other.size()),
        _data(other._capacity == 0 ? nullptr
                                    : new value_type[other._capacity])
    {
        try {
            std::copy(other.begin(), other.end(), begin());
        } catch (...) {
            delete[] _data;
            throw;
        }
        
    }

    // Move ctor
    // No-Throw Guarantee
    TMSArray(TMSArray && other) noexcept
        :_capacity(other._capacity),
        _size(other._size),
        _data(other._data)
    {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    // Copy assignment operator
    // Strong Guarantee
    TMSArray & operator=(const TMSArray & other)
    {
        TMSArray temp(other);
        swap(temp);
        return *this;
    }

    // Move assignment operator
    // No-Throw Guarantee
    TMSArray & operator=(TMSArray && other) noexcept
    {
        swap(other);
        return *this;
    }

    // Dctor
    // No-Throw Guarantee
    ~TMSArray()
    {
        delete [] _data;
    }

// ***** TMSArray: general public operators *****
public:

    // operator[] - non-const & const
    // Pre:
    //     Assuming index is [0, size()-1]
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }

// ***** TMSArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // Strong Guarantee
    // Pre:
    //  newsize == _size, do nothing
    //  newsize > _size, create new space with default values
    //  newsize < _size, reduce size
    void resize(size_type newsize)
    {
        // newsize == _size
        // newsize < _size
        if (newsize == _capacity) return;

        if (newsize < _capacity) {
            _size = newsize;
            return;
        }

        // newsize < _size
        if (newsize > _capacity) {
            // Calculate new capacity
            size_type newcap = std::max(newsize, size_type(_capacity * 2));
            // Growth Factor Limitation
            
            // Allocate new block of memory
            value_type* new_data = new value_type[newcap];

            // Copy old data to temp array
            try { 
                std::copy(begin(), end(), new_data);
            } catch (...) {
                delete [] new_data;
                throw;
            }
            
            delete[] _data;
            _data = new_data;
            _capacity = newcap;

            // Initialize new elements to default
            std::fill(begin() + _size, begin() + newsize, value_type());

            // Update size
            _size = newsize;
        }

    }

    // insert
    // Pre:
    //      pos must be a valid iterator pointing to a position within the array, or one past the end of the array
    //      _data cannot be nullptr
    // Basic Guarantee
    iterator insert(iterator pos, TMSArray::value_type item)
    {
        size_type index = pos - begin();
        try {
            // Resize if capacity is full
            if (_size == _capacity) {
                resize(_size + 1);
                pos = begin() + index;
            } else {
                // Shift elements to make space for the new item
                std::move_backward(pos, end(), end() + 1);
                
                //_data[index] = std::move(item);
                *(begin() + index) = std::move(item);

                // Increment size
                ++_size;

                // Return iterator to newly inserted item
                return begin() + index;
            } 
        } catch (...) {
            return end();
        }
    }

    // erase
    // Pre:
    //     pos is within bounds of array
    // Strong Guarantee
    iterator erase(iterator pos)
    {
        assert(pos >= begin() && pos < end());
        std::move(pos + 1, end(), pos);
        --_size;
        return pos;
    }

    // push_back
    // Basic Guarantee
    void push_back(value_type item)
    {
        insert(end(), std::move(item));
    }

    // pop_back
    // Pre: _size is > 0
    // Strong Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(TMSArray & other) noexcept
    {
        std::swap(_size, other._size);
        std::swap(_data, other._data);
        std::swap(_capacity, other._capacity);
    }

// ***** TMSArray: data members *****
public:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class TMSArray


#endif  //#ifndef FILE_TMSArray_HPP_INCLUDED

