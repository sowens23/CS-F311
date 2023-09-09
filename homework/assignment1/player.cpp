// Name: Spencer Owens
// Class: 23F CS-311 Data Structures and Algorithms
// Date: 2023-Sep-09
// Program Name: player.cpp
/* Program Function: 
				1) Class "player" should be implemented in player.cpp and player.hpp
				2) An object of player should have;
					- string irl name
					- string user name
					- non-negative integer giving the number of games the player has played
				3) Include the following functions
					- copy and move constructor, copy and move assignment, destructor (5) (Do not write these yourself)
					- Default constructor to set the player names to "UNKNOWN", and the games played to zero
					- 3 parameter constructor to set object values
					- "Get" member function for each object member values (2 strings, 1 int) ie getRealname, getUsername, getGamesplayed
					- "Set" member functions for each of the 3 objects
					- member function "inactive" which returns bool depending on if games = 0
					- member function "toString" no parameters, returns a string representation of 3 objects ie "Selena Gomez (Mabel Mora) : 15"
					- Equality and inequality operators for comparing two player objects to determine if all 3 objects are the same
					- Pre and post (++)/(--) operators to alter games played. Exception for (--) 0's
					- String insertion "<<" operator to output same string as "toString"
				4) All strings are strings, and all numbers are ints
*/

