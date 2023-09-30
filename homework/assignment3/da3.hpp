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

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <stdexcept>		// For std::out_of_range
#include <functional>  // For std::function


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
		// Check for out of range
		if(!head && index != 0) {
			throw std::out_of_range("Index is out of range for empty list");
		}

		// Iterate through the list up to the given index
		const LLNode<ValueType>* current = head;
		std::size_t currentIndex = 0;
		while (currentIndex < index && current != nullptr) {
			current = current->_next;
			currentIndex++;
		}

		// Check to see if nullptr was hit before index
		if (!current) throw std::out_of_range("Index is out of range for list");

		// Index found
		return current->_data;
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
	// Invariant: What happens when first and last are equal?
	if (first == last) return true;

	FDIter next = first; 
	++next;

	while(next != last) {
		if (*next < *first) {
			return false;
		}
		++first;
		++next;
	}
	// Returning true if all next values are 
	return true;
}

// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_HPP_INCLUDED