/* 
    Name: Spencer Owens
    Class: 23F CS-311 Data Structures and Algorithms
    Created: 2023-Nov-01
    Updated: 2023-Nov-01

    File Name: tsmarray.cpp
    File Function: 
*/

// msarray.cpp  HAND-OFF
// VERSION 6
// Glenn G. Chappell
// Started: 2023-10-17
// Updated: 2023-10-25
//
// For CS 311 Fall 2023
// Source for class MSArray
// Marvelously smart array of int
// Preliminary to Assignment 5


#include "tmsarray.hpp"  // For class TMSArray definition
#include <algorithm>
using std::copy;


// *********************************************************************
// class TMSArray - Member function definitions
// *********************************************************************


// Copy ctor
// See header for info.
TMSArray::TMSArray(const TMSArray & other)
    :_capacity(other._capacity),
     _size(other.size()),
     _data(other._capacity == 0 ? nullptr
                                : new value_type[other._capacity])
{
    copy(other.begin(), other.end(), begin());
    // The above call to std::copy does not throw, since it copies int
    // values. But if value_type is changed, then the call may throw, in
    // which case this copy ctor may need to be rewritten.
}


// Move ctor
// See header for info.
TMSArray::TMSArray(TMSArray && other) noexcept
    :_capacity(other._capacity),
     _size(other._size),
     _data(other._data)
{
    other._capacity = 0;
    other._size = 0;
    other._data = nullptr;
}


// Copy assignment operator
// See header for info.
TMSArray & TMSArray::operator=(const TMSArray & other)
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// Move assignment operator
// See header for info.
TMSArray & TMSArray::operator=(TMSArray && other) noexcept
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// resize
// See header for info.
void TMSArray::resize(TMSArray::size_type newsize)
{
    // TODO: WRITE THIS!!!
}


// insert
// See header for info.
TMSArray::iterator TMSArray::insert(TMSArray::iterator pos,
                                  TMSArray::value_type item)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// erase
// See header for info.
TMSArray::iterator TMSArray::erase(TMSArray::iterator pos)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// swap
// See header for info.
void TMSArray::swap(TMSArray & other) noexcept
{
    // TODO: WRITE THIS!!!
}

