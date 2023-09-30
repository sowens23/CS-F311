/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Sep-23
	 Updated: 2023-Sep-23

	 Program Name: DA3.cpp
	 Program Function: for testing purposes
*/

#include "da3.hpp"     // For Assignment 3 prototypes & templates

#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <stdexcept>		// For std::out_of_range
#include <functional>
using std::function;


void didItThrow(const function<void()> & ff,
                bool & threw)
{
		try {
			ff();
			threw = false; 
		} catch (...) {
			threw = true;
			throw;
		}
}


int gcd(int a,
        int b)
{
	if (a==0) return b; // Return GCD
	return gcd(b % a, a); // Recursively call gcd after modulo operation
}

void myFunc() { 
	throw std::runtime_error("Oh no!"); 
}

/* int main() {
	// TESTING NODE INITIALIZATION
		std::cout<<"Testing initialization\n";
		LLNode<int> *node=new
		LLNode<int>(5);
		node->_next = new LLNode<int>(10);
		node->_next->_next = new LLNode<int>(15);

	// TESTING NODE PRINT
		std::cout<< "Testing iterative print\n";
		LLNode<int> *current = node;
		while (current != nullptr) {
				std::cout << current->_data << std::endl;
				current = current->_next;
		}

	// TESTING INDEX RETURN
		try {
			std::size_t index_to_find = 2;
			int value_at_index = lookup(node, index_to_find);
			std::cout<< "Index value of node at 2: " << value_at_index << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}

	// Testing didItThrow
		bool result;
		try {
				didItThrow(myFunc, result);
		}
		catch (std::exception & e) {
				if (result)
						std::cout << "SUCCESS" << std::endl;
				else
						std::cout << "FAILURE" << std::endl;
		}

	// Testing checkSorted
		vector<int> v {
				4,
				3,
				2,
				1
		};
		result = checkSorted(v.begin(), v.end());
		if (result) std::cout<<"True\n";
		else std::cout<<"False\n";
 		vector<int> b {
				1,
				2,
				3,
				4
		};
		result = checkSorted(b.begin(), b.end());
		if (result) std::cout<<"True\n";
		else std::cout<<"False\n";

	// Testing GCD
		int gcd_test = gcd(910,42);
		std::cout << "GCD(910,42): " << gcd_test << std::endl;

	// Delete and return
		delete node;
		return 0;
} */