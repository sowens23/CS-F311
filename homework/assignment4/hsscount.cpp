/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Oct-1
	 Updated: 2023-Oct-1

	 Program Name: hsscount.cpp
	 Program Function: 
					Excercise A: Write recursive backtracking code that can count the amount of full solutions that the spider can scuttle on the board.
						hsscount.cpp must contain; 
							A public interface 'hssCount' which returns the number of holy spider scuttles on a given board
								It should do the bulk of the work by calling 'hssCount_recurse' which counts the number of holey spider scuttles based on a given partial solution using recursive backtracking
								'hssCount_recurse' is not part of the public interface of the package. 
							'hssCount' should be prototyped as 
								int hssCount(int dim_x, int dim_y,
								int hole_x, int hole_y,
								int start_x, int start_y,
								int finish_x, int finish_y);

								dim(x/y) Size of board, hole(x/y) location of hole, start and finish (x/y) where it starts and ends
								It should only take positive dimentions, and locations within that parameter
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include "hsscount.hpp"


int main() {
	string msg = "Hello, world.";
	hssCount(msg);
	return 0;
}