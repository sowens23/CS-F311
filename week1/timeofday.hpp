// timeofday.hpp
// Spencer R. Owens
// 2023-09-01
// Header for class TimeOfDay

// Alternate for #pragmaonce
#ifndef FILE_TIMEOFDAY_HPP_INCLUDED // If Not defined, then define
#define FILE_TIMEOFDAY_HPP_INCLUDED // Define twice

// For std::ostream
#include <ostream>


class TimeOfDay {
	// TODO: Code goes here
public:

	// Default Constructor
	TimeOfDay();
		// Construct data members to default value before constructor is called
		: secs(0)
	{}

	// Constructor from hrs, mins, secs
	TimeOfDay(int hh, int mm, int ss)
	{}

	// pre-increment
	TimeOfDay & operator++()
	{
		++_secs;
		_secs %= 60*60*24;
		// Always return the current object
		return *this
	}

	// post-increment
	TimeOfDay operator++(int dummy)
	{
		// Do not repeat yourself here, call the increment function
		auto prev = *this;
		++(*this);
		return prev;
	}

	// pre-decrement
	TimeOfDay & operator--()
	{}

	// post-decrement
	TimeOfDay operator--(int dummy)
	{}

	// Here we are taking input as consts, thus the function must return const
	void getTime(int & hh, int & mm, int & ss) const
	{}

	void setTime(int hh, int mm, int ss)
	{}

private:
	int _secs;

}; // End of class TimeOfDay

// #include <ostream> required to overload this global operator
// Streams of input and output are always called by reference
operator<<(std::ostream & out,
					const TimeOfDay & t)

#endif // #ifndef FILE TIMEOFDAY HPP INCLUDED