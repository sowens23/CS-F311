/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Assignment: Two
	 Created: 2023-Sep-20
	 Updated: 2023-Sep-20

	 Program Name: fsarray.hpp
	 Program Function: 
				1) Name your class template FSArray whose items have type double would be declared as FSArray<double>
					- Everything in in the class will be a template
					- Class template acts as a single array with a given size and value type
				2) In the public interface include;
					- Default ctor that creates an FSArray object with size 8, which all items in the array are default constructed
				3) Create a dctor, copy ctor, move ctor, copy assignment, move assignment
					- Be sure that dctor frees any dynamically allocated memory
					- Each copy operation creates an entirely new copy of the data, as so modifying the copy leaves the original unaltered
					- Write these functions as described in the slides (Invisible Functions II)
				4) 1-parameter ctor, where the size is defined.
				5) 2-parameter ctor, where size is defined then a value for each item to be set to
				6) Bracket operator to return the array value from 0 to (size-1)
				7) Member Function
					- Size: no parameters, returns the size of array
					- Begin: no parameters, returns the address of item 0
					- End: no parameters, returns the address of the item one-past the end of the array
				8) Operators == that bools whether an array has same size, and all items are the same
					- and != that checks the opposite
				9) Operators <, >, <=, >=.
					- Two FSArray objects with different value types cannot be compared.
					- If they can be compared, these operators use lexicographic order, which works like alphabetical order processing all items of each array together 
				10) Define member types value_type, and size_type publicly
				11) const FSArray<T> does not does not allow modification (This has implications for how you implement functions behin and end, as well as the bracket operator)
				12)
*/

//#include <iostream>
//#include <ostream>
//#include <cassert>
//#include <string>
//#include <cctype>
#include <cstddef>
using std::size_t;

// 
// Class Template FSArray
// 

template <typename ValType>
class FSArray {
	public:
		// *** Member Types ***
		using value_type = ValType;
		using size_type = std::size_t;

		// *** Constructors ***
		FSArray() : size_(8), data_(new value_type[size_]) // Default Constructor
		{}
		FSArray(size_type size) : size_(size), data_(new value_type[size])
		{}
		FSArray(size_type size, const value_type& val) : size_(size), data_(new val[size])
		{}

		// *** The Big Five ***
		~FSArray(); // Deconstructor
		FSArray(const FSArray& other); // Copy Constructor
		FSArray & operator=(const FSArray & other); // Copy Assignment
		FSArray(FSArray && other); // Move Constructor
		FSArray & operator=(FSArray && other); // Move Assignment

		// *** Assignment Operators ***
		FSArray& operator=(const FSArray)


	private:
		size_type size_;
		value_type* data_;

};