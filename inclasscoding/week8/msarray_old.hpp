// msarray.hpp  UNFINISHED
// Glenn G. Chappell
// 2023-10-17
//
// For CS 311 Fall 2023
// Header for class MSArray
// Marvelously smart array of int
// Preliminary to Assignment 5

#ifndef FILE_MSARRAY_HPP_INCLUDED
#define FILE_MSARRAY_HPP_INCLUDED

// For size_t
#include <cstddef>
using std::size_t;

// *********************************************************************
// class MSArray - Class definition
// *********************************************************************


// class MSArray
// Marvelously Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//    _size >= 0
//    _data points to an array of value_type, allocated with new [], owned by *this, holding _size value_type values
//     
class MSArray {

// ***** MSArray: types *****
public:

  // This allows you to define the types further in this class
    // IE if you need to make this an array for long, you can simply update it here, once.
  using size_type = std::size_t;
  using value_type = int;
  using iterator = value_type*;
  using const_iterator = const value_type*;

// ***** MSArray: ctors, op=, dctor *****
public:

  // Default ctor AND ctor with size
    explicit MSArray(size_type thesize=0)
    : _size(thesize), // This is executed in the order in which the values are declared in the private variables area. Make sure you 
      _data(new value_type[thesize])
    {}

  // Move constructors
    MSArray(const MSArray & other)
    {
      // TOOD: WRITE THIS!!
    }
    
    MSArray(MSArray && other) noexcept
    {
      // TOOD: WRITE THIS!!
    }

    // Delete Constructor
    ~MSArray()
    {
      // TOOD: WRITE THIS!!
      delete [] _data;
    }

  // Copy Constructors
    MSArray & operator=(const MSArray & other)
    {
      // TOOD: WRITE THIS!!
      return *this;
    }
    
    MSArray & operator=(MSArray && other) noexcept
    {
      // TOOD: WRITE THIS!!
      return *this;
    }

// ***** MSArray: general public operators *****
public:

  value_type & operator[](size_type index)
  {
    return _data[index];
  }

  const value_type & operator[](size_type index) const 
  {
    return _data[index];
  }

// ***** MSArray: general public functions *****
public:

  // Member function size return size
    size_type size() const
    {
      return _size;
    }

  // Is empty member function
    size_type empty() const
    {
      return size() == 0;
    }

  // Iterator begin and end member functions
    iterator begin()
    {
      // TOOD: WRITE THIS!!
      return _data;
    }

    const_iterator begin() const
    {
      // TOOD: WRITE THIS!!
      return _data;
    }
    iterator end()
    {
      // TOOD: WRITE THIS!!
      return _data + size();
    }

    const_iterator end() const
    {
      // TOOD: WRITE THIS!!
      return _data + size();
    }

  // Erase, Resize, Insert
    void resize(size_type newsize)
    {
      // TOOD: WRITE THIS!!
    }

    iterator insert(iterator pos,
      value_type value)
    {
      // TOOD: WRITE THIS!!
      return pos; // DUMMY
    }

    iterator erase(iterator pos,
      value_type value)
    {
      // TOOD: WRITE THIS!!
      return pos; // DUMMY
    }

  // Pushback and pop back and swap
  // IDK why value_type needs to be reference to const, but it needs to be
    // Because in our version the object type will be larger than an int
    void push_back(value_type value)
    {
      // TOOD: WRITE THIS!!
      // If you have written a function to do something, and, 
        // you want to do that something, then, 
        // call the function
      insert(end(), item);
    }

    void pop_back(value_type value)
    {
      erase(end() -1);
    }

    void swap(MSArray & other) noexcept
    {
      // TOOD: WRITE THIS!!
    }

// ***** MSArray: data members *****
private:

  size_type _size;
  value_type * _data;

};  // End class MSArray


#endif  //#ifndef FILE_MSARRAY_HPP_INCLUDED

