/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Sep-20
	 Updated: 2023-Sep-20

	 Program Name: fsarray.cpp
	 Program Function: for testing purposes
*/

#include "fsarray.hpp"
#include <iostream>
	using std::cout;
	using std::endl;
int main () {

	FSArray<int> ia(8);           // Array of 8 ints
	FSArray<int> iax;             // Another array of 8 ints
	FSArray<double> da(40, 3.2);  // Array of 40 doubles; each is set to 3.2
	//FSArray x(8);                 // DOES NOT COMPILE; no template parameter

	// Set all items (counter loop)
	for (int c = 0; c < ia.size(); ++c)
	{
		ia[c] = c * c;
	}

	// Range-based for-loop calls FSArray member functions begin, end
	for (auto x : ia)
	{
		cout << "Item :" << x << endl;
	}

	const FSArray<int> ia2 = ia;  // Copy constructor
	if (ia2 == ia)                // Condition is true
		cout << "Equal!" << endl;

	FSArray<double> da2;
	da2 = da;                     // Copy assignment
	//da2 = ia;                     // DOES NOT COMPILE; different value types

	//if (da == ia)                 // DOES NOT COMPILE; different value types
	//	cout << "blah blah" << endl;
	
	return 0;
}