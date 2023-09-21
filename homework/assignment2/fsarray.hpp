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

#include <iostream>
//#include <ostream>
//#include <cassert>
//#include <string>
//#include <cctype>
#include <cstddef>

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
		// Three constructors [Default, 1-P, 2-P]
		FSArray() : size_(8), data_(new value_type[size_]) // Default Constructor
		{}
		FSArray(size_type size) : size_(size), data_(new value_type[size])
		{}
		FSArray(size_type size, const value_type& val) : size_(size), data_(new value_type[size])
		{
			// Auto Fill
			//std::fill(data_, data_ + size_, val);
			// Manual Fill
			for (size_type i = 0; i < size; ++i) {
				data_[i] = val;
			}
		}

		// *** The Big Five ***
		// Deconstructor
		~FSArray() 
		{
			delete[] data_;
		}
		// Copy Constructor
		FSArray(const FSArray& other) 
		{
			// Auto Copy
			//std::copy(other.data_, other.data_ + size_, data_);
			// Manual Copy
			for (size_type i = 0; i < size_; ++i) {
				data_[i] = other.data_[i];
			}
		}
		// Copy Assignment
		FSArray & operator=(const FSArray & other) 
		{
			if (this != &other) {
				delete[] data_;
				size_ = other.size_;
				data_ = new value_type[size_];
				std::copy(other.data_, other.data_ + size_);
			}
			return *this;
		}
		// Move Constructor
		FSArray(FSArray && other) noexcept : size_(other.size_), data_(other.data_) 
		{
			other.size = 0;
			other.data_ = nullptr;
		}
		// Move Assignment
		FSArray & operator=(FSArray && other) noexcept
		{
			if (this != &other) {
				delete[] data_;
				size_ = other.size_;
				other.size_ = 0;
				other.data_ = nullptr;
			}
			return *this;
		}
		// *** Operators ***
		// Bracket Operator
		value_type & operator[](size_type index)
		{
			return data_[index];
		}

		const value_type & operator[](size_type index) const
		{
			return data_[index];
		}

		value_type size()
		{
			
		}

		// Equals operator that checks size, and all values
			// Subsequently the != equals as well
		// '<' '<=' '>' '>=' operators to compare all values of two arrays
			// Quite possibly needs to sort first? Not sure

		// *** Member Functions ***
		// Size returns the size of a given array
		size_type size() const {
			return size_;
		}
		// Returns address of item 0
		value_type* begin() {
			return data_;
		} 
		// void end returns address of one item past last


	private:
		size_type size_;
		value_type* data_;

};

    size_type size() const { return size_; }

    value_type* begin() { return data_; }
    
    const value_type* begin() const { return data_; }

    value_type* end() { return data_ + size_; }
    
    const value_type* end() const { return data_ + size_; }

template <typename T>
bool operator==(const FSArray<T>& lhs, const FSArray<T>& rhs) {
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const FSArray<T>& lhs, const FSArray<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const FSArray<T>& lhs, const FSArray<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator>(const FSArray<T>& lhs, const FSArray<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator<=(const FSArray<T>& lhs, const FSArray<T>& rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>=(const FSArray<T>& lhs, const FSArray<T>& rhs) {
    return !(lhs < rhs);
}