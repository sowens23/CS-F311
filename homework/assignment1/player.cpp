/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Sep-09
	 Updated: 2023-Sep-09

	 Program Name: player.cpp
	 Program Function: 
				1)x Class "player" should be implemented in player.cpp and player.hpp
				2)x An object of player should have;
					-x string irl name
					-x string user name
					-x non-negative integer giving the number of games the player has played
				3) Include the following functions
					-x copy and move constructor, copy and move assignment, destructor (5) (Do not write these yourself)
					-x Default constructor to set the player names to "UNKNOWN", and the games played to zero
					-x 3 parameter constructor to set object values
					-x "Get" member function for each object member values (2 strings, 1 int) ie getRealName, getUsername, getGamesplayed
					- "Set" member functions for each of the 3 objects
					- member function "inactive" which returns bool depending on if games = 0
					- member function "toString" no parameters, returns a string representation of 3 objects ie "Selena Gomez (Mabel Mora): 15"
					- Equality and inequality operators for comparing two player objects to determine if all 3 objects are the same
					-x Pre and post (++)/(--) operators to alter games played. Exception for (--) 0's
					-x String insertion "<<" operator to output same string as "toString"
				4)x All strings are strings, and all numbers are ints
*/

#include "player.hpp"
#include <iostream>
#include <string>
	using std::string;
#include <ostream>
	using std::ostream;
#include <cctype> 
	using std::isalpha; // Using to test if RealName contains anything but alphabet characters

// Run this next line to DISABLE ASSERT DEBUG MODE
#define NDEBUG
#include <cassert>

// ***** ***** ***** ***** ***** ***** //
// Class Player - Definition of Member Functions		 //
// ***** ***** ***** ***** ***** ***** //

	// createPlayer: Set realname, username, games
	void Player::createPlayer (std::string realname, std::string username, int games) {
		setRealName(realname);
		setUsername(username);
		setGames(games);
	}

	// getRealName: to return realname of Player
	std::string Player::getRealName () const {
		std::string realname;
		realname = _realname;
		return realname;
	}

	// getUsername: to return username of Player
	std::string Player::getUsername () const {
		std::string username;
		username = _username;
		return username;
	}

	// getGames: to return game count of Player
	int Player::getGames () const {
		int games;
		games = _games;
		return games;
	}

	// isAlpha: To test strings for non alphabet characters
	bool isAlpha(const std::string & realname_test) {
		for (char c: realname_test) {
			if (!isalpha(c)) return false;
		}
		return true;
	}

	// setRealName: to set realname of Player
	void Player::setRealName (std::string realname) {
		assert(isAlpha(realname)); // Tests for non alphabet characters
		_realname = realname;
	}

	// setUsername: to set username of Player
	void Player::setUsername (std::string username) {
		_username = username; // No assert here, not sure what string values would break this
	}

	// setGames: to set game count of Player
	void Player::setGames (int games) {
		std::cout << games << std::endl;
		assert(games > 0); // Tests for negative game count, which should be impossible.
		_games = games;
		std::cout << games << std::endl;
		std::cout << _games << std::endl;
		
	}

	// toString: To return a string value identical to cout << player
	std::string Player::toString () const {
		std::string playert;
		playert = _realname + " (" + _username + "): " + std::to_string(_games);
		return playert;
	}

	// Operator <<(ostream,Player) *Using obj.toString()*
	ostream & operator<<(ostream & str, const Player & obj) {
		std::string playert = obj.toString();
		str << playert;
		return str;
	}

	// inactive: To return boolian whether player has 0 games
	bool Player::inactive () const {
		int gamet = _games;
		if (gamet == 0) return true;
		else return false;
	}


/* int main () {

	// const Player player1;
	Player player2("Spencer", "Straleos", -5);
	std::cout << player2 << std::endl;

	return 0;
} */