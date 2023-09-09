// intarray.hp
// Spencer Owens
// 23-09-08
// Header for class IntArray

#ifndef FILE_INTARRAY_HPP_INCLUDED
#define FILE_INTARRAY_HPP_INCLUDED

#include <cstddef>
// For std::size_t

class IntArray {
	public:

		using size_type = std::size_t;
		using value_type = int;

		// Default Constructor
		IntArray(size_type size) 
			:_arrayptr(new value_type[size])
		{
			//_arrayptr = new int[size];
		}

		// Not exactly sure
		value_type & operator[](size_type index)
		{
			return _arrayptr[index];
		}

		//
		const value_type & operator[](size_type index) const
		{
			return _arrayptr[index];
		}
		// Deconstructor
		~IntArray()
		{
			delete [] _arrayptr;
		}

		IntArray(IntArray && other) =delete;
		IntArray(const IntArray && other) =delete;
		IntArray & operator=(IntArray && other) =delete;
		IntArray & operator=(const IntArray && other) =delete;

	private:
	
		int * _arrayptr; // Pointer to our dynamic array of int

}; // End class IntArray

#endif // #ifndef FILE_INTARRAY_HPP_INCLUDED