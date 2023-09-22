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
				10) Define member types ValType, and SizeType publicly
				11) const FSArray<T> does not does not allow modification (This has implications for how you implement functions behin and end, as well as the bracket operator)
				12)
*/

#ifndef FILE_FSARRAY_HPP_INCLUDED
#define FILE_FSARRAY_HPP_INCLUDED

#include <algorithm>
#include <cassert>
#include <cstddef>

// 
// Class Template FSArray
// 

template <typename ValType, typename SizeType = std::size_t>
class FSArray {
	public:
	// *** Member Types ***

		using value_type = ValType;
		using size_type = SizeType;

	// *** Constructors ***

		// Three constructors [Default, 1-P, 2-P]
		// Default Constructor
		FSArray() : size_(8), data_(new ValType[8]) {}

		explicit FSArray(SizeType size) : size_(size), data_(new ValType[size]) {}
		FSArray(SizeType size, const ValType& val) : size_(size), data_(new ValType[size])
		{
			for (SizeType i = 0; i < size_; ++i) {
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
		FSArray(const FSArray& other) : size_(other.size_), data_(new ValType[other.size_])
		{
			for (SizeType i = 0; i < size_; ++i) {
				data_[i] = other.data_[i];
			}
		}

		// Move Constructor
		FSArray(FSArray && other) noexcept : size_(other.size_), data_(other.data_) 
		{
			other.size_ = 0;
			other.data_ = nullptr;
		}

		// Copy Assignment
		FSArray & operator=(const FSArray & other) 
		{
			if (this != &other) 
			{
				FSArray fsarray_temp(other);
				swap(fsarray_temp);
			}
			return *this;
		}

		// Move Assignment
		FSArray & operator=(FSArray && other) noexcept
		{
			if (this != &other) 
			{
				swap(other);
			}
			return *this;
		}

	// *** Operators ***

		// Bracket Operator
		ValType & operator[](SizeType index)
		{
			assert(index < size_);
			return data_[index];
		}

		const ValType & operator[](SizeType index) const
		{
			assert(index < size_);
			return data_[index];
		}

	// *** Member Functions ***

		// Size returns the size of a given array
		SizeType size() const 
		{
			return size_;
		}
		// Begin returns address of item 0
		ValType* begin() 
		{
			return data_;
		} 
		// Begin const returns the address of a const array item 0
		const ValType* begin() const
		{
			return data_;
		}
		// End returns address of one item past last
		ValType* end()
		{
			return data_ + size_;
		}
		// End const returns address of one item past last
		const ValType* end() const
		{
			return data_ + size_;
		}

		// *** Additional operators ***
		// ==, !=, <, <=, >, >=
		bool operator==(const FSArray& other) const 
		{
			if (size_ != other.size_) {
				return false;
			}
			for (SizeType i = 0; i < size_; ++i) 
			{
				if (data_[i] != other.data_[i]) {
					return false;
				}
			} 
			return true;
		}

		bool operator!=(const FSArray& other) const
		{
				return !(other == *this);
		}

		bool operator<(const FSArray& other) const
		{
			for (SizeType i = 0; i < size_ && i < other.size_; ++i) {
					if (data_[i] < other.data_[i]) {
							return true;
					} else if (other.data_[i] < data_[i]) {
							return false;
					}
			}
			return size_ < other.size_; // Compare sizes if no difference found
		}

		bool operator<=(const FSArray& other) const
		{
				return !(other < *this);
		}

		bool operator>(const FSArray& other) const 
		{
				return other < *this;
		}

		bool operator>=(const FSArray& other) const
		{
				return !(*this < other);
		}

	private:
		SizeType size_;
		ValType* data_;

		// Private swap function for efficient swapping
		void swap(FSArray& other) noexcept {
			std::swap(size_, other.size_);
			std::swap(data_, other.data_);
		}

};

#endif // #ifndef FILE_FSARRAY_HPP_INCLUDED