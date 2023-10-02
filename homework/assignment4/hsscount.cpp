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
#include <vector>
using std::vector;
#include <utility> 
using std::pair;
#include "hsscount.hpp"

int hssCount(int dim_x, int dim_y,
							int hole_x, int hole_y,
							int start_x, int start_y,
							int finish_x, int finish_y) 
{
	// Check dimensions
		if (dim_x < 0 || dim_y < 0) return 0;
		else if ((start_x > dim_x || start_y > dim_y) || (start_x < 0 || start_y < 0)) return 0;
		else if ((hole_x > dim_x || hole_y > dim_y) || (hole_x < 0 || hole_y < 0)) return 0;
		else if ((finish_x > dim_x || finish_y > dim_y) || (finish_x < 0 || finish_y < 0)) return 0;
		else if (start_x == hole_x && start_y == hole_y) return 0;
		else if (hole_x == finish_x && hole_y == finish_y) return 0;
		else if (finish_x == start_x && finish_y == start_y) return 0;

	// Create Board vector and place markers
	vector<vector<int>> board (dim_x, vector<int>(dim_y,0)); // 2x8 Board should return 64
	board[hole_x][hole_y] = 1;

	// Begin Recursive Workhorse to count scuttles
	return hssCount_recurse(board, start_x, start_y, finish_x, finish_y, (dim_x*dim_y)-2);
}

/* int main() {
	// Board x,y. Hole x,y. Start x,y. Finish x,y.
	cout << hssCount(3,2, 2,0, 1,0, 2,1) <<endl; // Should return 2
	cout << hssCount(4,1, 1,0, 0,0, 3,0) <<endl; // Should return 0
	cout << hssCount(5,4, 4,3, 4,2, 0,0) <<endl; // Should return 40`887
	return 0;
} */