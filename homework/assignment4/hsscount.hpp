/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Oct-1
	 Updated: 2023-Oct-1

	 Program Name: hsscount.hpp
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

#ifndef FILE_HSSCOUNT_HPP_INCLUDED
#define FILE_HSSCOUNT_HPP_INCLUDED

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <utility> 
using std::pair;

// Forward declaration of hssCount_recurse
int hssCount_recurse(vector<vector<int>> board, 
									int curr_x, int curr_y, 
									int finish_x, int finish_y, 
									int squaresLeft);

// Recursive wrapper
int hssCount(int dim_x, int dim_y,
							int hole_x, int hole_y,
							int start_x, int start_y,
							int finish_x, int finish_y) {
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
};

// Recursive Workhorse
int hssCount_recurse(vector<vector<int>> board, 
									int curr_x, int curr_y, 
									int finish_x, int finish_y, 
									int squaresLeft) {

	// Base Case: Check if next move is invalid and if there are any moves left
	if (curr_x >= board.size() || curr_x < 0 ||
		curr_y >= board[0].size() || curr_y < 0) {
		return 0;
	}
	if (board[curr_x][curr_y] == 1) return 0;

	// Base Case: FULL SOLUTION
	if (squaresLeft == 0 && curr_x == finish_x && curr_y == finish_y) return 1;

	// Mark current position
	board[curr_x][curr_y] = 1;
	int total = 0;

	// Consider all legal moves
	vector<pair<int, int>> moves = {{0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}};
	for (auto move : moves) {
		int new_x = curr_x + move.first;
		int new_y = curr_y + move.second;
		total += hssCount_recurse(board, new_x, new_y, finish_x, finish_y, squaresLeft-1);
	}

	// Unmark current position (backtrack)
	board[curr_x][curr_y] = 0;

	return total;
};

#endif //#ifndef FILE_HSSCOUNT_HPP_INCLUDED