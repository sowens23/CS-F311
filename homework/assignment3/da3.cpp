/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Sep-23
	 Updated: 2023-Sep-23

	 Program Name: DA3.cpp
	 Program Function: for testing purposes
*/

#include "da3.hpp"     // For Assignment 3 prototypes & templates

#include<iostream>
#include <functional>
using std::function;


void didItThrow(const function<void()> & ff,
                bool & threw)
{
    // TODO: WRITE THIS!!!
}


int gcd(int a,
        int b)
{
    return 42;  // DUMMY
    // TODO: WRITE THIS!!!
}

int main() {
	// TESTING
	std::cout<<"testing\n";
	// Filling Node
	LLNode<int> *node=new
	LLNode<int>(5);
	node->_next = new LLNode<int>(10);
	node->_next->_next = new LLNode<int>(15);
	// Printing Node
	LLNode<int> *current = node;
	while (current != nullptr) {
			std::cout << current->_data << std::endl;
			current = current->_next;
	}
	delete node;
	return 0;
}