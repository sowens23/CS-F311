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

// *** NAMESPACE SCUTTLESPIDER PROVIDERS HELPER FUNCTIONS TO PUBLIC INTERFACE FUNCTION HSSCOUNT

int hssCount(int dim_x, int dim_y,
							int hole_x, int hole_y,
							int start_x, int start_y,
							int finish_x, int finish_y);

// *** NAMESPACE SCUTTLESPIDER PROVIDERS HELPER FUNCTIONS TO PUBLIC INTERFACE FUNCTION HSSCOUNT

namespace scuttleSpider {

	// 1) Function to check dimensions
	void checkDimensions (int dim_x, int dim_y,
							int hole_x, int hole_y,
							int start_x, int start_y,
							int finish_x, int finish_y) 
	{
		if (dim_x < 0 || dim_y < 0) throw std::out_of_range("Board size cannot be negative");
		if ((start_x > dim_x || start_y > dim_y) || (start_x < 0 || start_y < 0)) throw std::out_of_range("Start must be located on the board");
		if ((hole_x > dim_x || hole_y > dim_y) || (hole_x < 0 || hole_y < 0)) throw std::out_of_range("Hole must be located on the board");
		if ((finish_x > dim_x || finish_y > dim_y) || (finish_x < 0 || finish_y < 0)) throw std::out_of_range("Finish must be located on the board");
		if (start_x == hole_x && start_y == hole_y) throw std::out_of_range("Start is hole");
		if (hole_x == finish_x && hole_y == finish_y) throw std::out_of_range("Hole is finish");
		if (finish_x == start_x && finish_y == start_y) throw std::out_of_range("Finish is start");
	}

	// 3) Function to print out dimensions
	void printDimensions (int dim_x, int dim_y,
							int hole_x, int hole_y,
							int start_x, int start_y,
							int finish_x, int finish_y) 
	{
		string dimensions="";
		dimensions += "\n** Printing Dimensions **\n";
		dimensions += "Board: " + to_string(dim_x) + " by " + to_string(dim_y) + "\n";
		dimensions += "Hole: [" + to_string(hole_x) + "," + to_string(hole_y) + "]\n";
		dimensions += "Start: [" + to_string(start_x) + "," + to_string(start_y) + "]\n";
		dimensions += "End : [" + to_string(finish_x) + "," + to_string(finish_y) + "]\n\n";
		cout << dimensions;
	}

	// 3) Function to print board
	void printBoard (vector<vector<int>> board_temp) 
	{
		cout << "** Printing Board **\n";
		for (int height = 0; height < board_temp[0].size(); height++) {
			for (int width = 0; width < board_temp.size(); width++) {
				cout << board_temp[width][height] << " ";
			}
			cout << endl;
		}
	}

	// 4) Recursive Workhorse
	int hssCount_recurse(vector<vector<int>> board, 
										int curr_x, int curr_y, 
										int finish_x, int finish_y, 
										int squaresLeft) {

		// Base Case: Check if next move is invalid and if there are any moves left
		if (board[curr_x][curr_y] == 1 || 
				curr_x > board.size() || curr_x < 0 ||
				curr_y > board[0].size() || curr_y < 0) {
			cout << board[curr_x][curr_y] << " == 1\n"; 
			cout << curr_x << " >= " << board.size() << " or " << curr_x << " < 0\n";
			cout << curr_y << " >= " << board[0].size() << " or " << curr_y << " < 0\n";
			cout << "invalid or no moves\n";
			return 0;
		}

		// Base Case: FULL SOLUTION
		if (squaresLeft == 0 && curr_x == finish_x && curr_y == finish_y) {
			cout << "full solution\n";
			return 1;
		}

		// Mark current position
		cout << "Legal move made\n";
		board[curr_x][curr_y] = 1;

		// Consider next legal move
			int move_x, move_y = 0;
			// Diagonal UPLEFT, UP and Diagonal UPRIGHT
			if (curr_y-1 >= 0) {
				if (curr_x-1 >= 0 && board[curr_x-1][curr_y-1] == 0) {
					cout << "UP/LEFT move found\n";
				}
				if (board[curr_x][curr_y-1] == 0) {
					cout << "UP move found\n";
				}
				if (curr_x+1 < board.size() && board[curr_x+1][curr_y-1] == 0) {
					cout << "UP/RIGHT move found\n";
				}
			}
			// Left and Right movements
  		if (curr_x-1 >= 0 && board[curr_x-1][curr_y] == 0) {
				cout << "LEFT move found\n";
			}
			if (curr_x+1 < board.size() && board[curr_x+1][curr_y] == 0) {
				cout << "RIGHT move found\n";
			} 
			// Diagonal DOWNLEFT, DOWN and Diagonal DOWNRIGHT
			if (curr_y+1 < board[0].size()) {
				if (curr_x-1 >= 0 && board[curr_x-1][curr_y-1] == 0) {
					cout << "DOWN/LEFT move found\n";
				}
				if (board[curr_x][curr_y+1] == 0) {
					cout << "DOWN move found\n";
				}
				if (curr_x+1 < board.size() && board[curr_x+1][curr_y+1] == 0) {
					cout << "DOWN/RIGHT move found\n";
				}
			}

		// All legal moves are identified by this point.

		int total = 0;
		/* total += hssCount_recurse(board, curr_x + move_x, curr_y + move_y, 
														finish_x, finish_y, squaresLeft-1); */

		// Unmark current position (backtrack)
		board[curr_x][curr_y] = 0;

		return total;
	}

};

#endif //#ifndef FILE_HSSCOUNT_HPP_INCLUDED