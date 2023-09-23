/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Sep-23
	 Updated: 2023-Sep-23

	 Program Name: da3.hpp
	 Program Function: 
		Excercise A: 	
			Write a function template "lookup" that is given a;
				nullptr terminated linked list 
				and an int index where the first item is 0, second is 1, to (size-1)
				An empty size zero list will be gien to lookup by passing a null pointer as the head
				if index is OOR (->) or (>size): throw exception using std::out_of_range
				lookup should throw only if index is OOR
				If an exception is thrown, use the "what" member to return a string describing the error.
		Excercise B:
*/

#include "llnode.hpp"

#include <cstddef>

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index);

#endif // #ifndef FILE_DA3_HPP_INCLUDED