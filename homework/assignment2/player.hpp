// Name: Spencer Owens
// Class: 23F CS-311 Data Structures and Algorithms
// Date: 2023-Sep-09
// Program Name: player.hpp
// Program Function: Header file for player.cpp

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <iostream>
	using std::cout;
	using std::string;
	
#include <ostream>
#include <cassert>
#include <string>
#include <cctype>

// isAlpha: To test strings for non alphabet characters
bool isAlpha(const std::string & realname_test) {
	for (char c: realname_test) {
		if (!isalpha(c)) return false;
	}
	return true;
}

// ***** ***** ***** ***** ***** ***** //
// Class Player - Class Definition		 //
// ***** ***** ***** ***** ***** ***** //

class Player{

	// ***** Player: Friend Declarations *****
	friend
		std::ostream & operator<<(std::ostream & str, const Player & obj);

	// ***** Player: Constructors and Deconstructors *****
	public: 

		// Default Constructor
		Player() {
			createPlayer("UNKNOWN", "UNKNOWN", 0);
		}

		// Constructor using strings realname, username, and games
		Player(std::string realname, std::string username, int games) {
			//setRealName(realname);
			createPlayer(realname, username, games);
		}

	// ***** Player: General Public Operators *****
	public:

		// Operator ++ [Pre] to move games one forward
		Player & operator++() {
			++_games;
			return *this;
		}

		// Operator ++ [Post] to move games one forward
		Player operator++([[maybe_unused]] int dummy) {
			auto save = *this;
			++(*this);
			return save;
		}

		// Operator -- [Pre] to move games one backward (Exception if 0)
		Player & operator--() {
			if (_games != 0) --_games;
			return *this;
		}

		// Operator -- [Post] to move games one backward (Exception if 0)
		Player operator--([[maybe_unused]] int dummy) {
			auto save = *this;
			if (_games != 0) --(*this);
			return save;
		}

		// Operator == to compare Player objects
		bool operator==(const Player& other) const {
		 return _realname == other._realname &&
		 				_username == other._username &&
						_games == other._games;
		}

		bool operator!=(const Player& other) const {
		 return !(*this == other);
		}

	// ***** Player: General Public Functions *****
	public:

		// createPlayer
		// Set realname, username, games
		// Function defined in source file.
		void createPlayer (std::string realname, std::string username, int games) {
			setRealName(realname);
			setUsername(username);
			setGames(games);
		}

		// getRealName: to return realname of Player
		// Function defined in source file
		std::string getRealName () const {
			std::string realname;
			realname = _realname;
			return realname;
		}

		// getUsername: to return username of Player
		// Function defined in source file
		std::string getUsername () const {
			std::string username;
			username = _username;
			return username;
		}

		// getGames: to return game count of Player
		// Function defined in source file
		int getGames () const {
			int games;
			games = _games;
			return games;
		}

		// setRealName: to set realname of Player
		// Function defined in source file
		void setRealName (std::string realname) {
			assert(isAlpha(realname)); // Tests for non alphabet characters
			_realname = realname;
		}

		// setUsername: to set username of Player
		// Function defined in source file
		void setUsername (std::string username) {
			_username = username; // No assert here, not sure what string values would break this
		}

		// setGames: to set game count of Player
		// Function defined in source file
		void setGames (int games) {
			std::cout << games << std::endl;
			assert(games > 0); // Tests for negative game count, which should be impossible.
			_games = games;
		}

		// toString: To return a string value identical to cout << player
		// Function defined in source file
		std::string toString () const {
			std::string playert;
			playert = _realname + " (" + _username + "): " + std::to_string(_games);
			return playert;
		}

		// inactive: To return boolian whether player has 0 games
		// Function defined in source file
		bool inactive () const {
			int gamet = _games;
			if (gamet == 0) return true;
			else return false;
		}

	// ***** Player: Data Members *****
	private:
	
		std::string _realname;
		std::string _username;
		int _games;

}; // End Class Player Definition

// ***** ***** ***** ***** ***** ***** //
// Class Player - Declaration of associated global operators		 //
// ***** ***** ***** ***** ***** ***** //

	// Operator<< (ostream,Player)
	// Prints given Player realname, username, and games "REAL (USER) : PLAYS"
	// Function defined in source file
	std::ostream & operator<<(std::ostream & str, const Player & obj) {
		std::string playert = obj.toString();
		str << playert;
		return str;
	}

#endif //#ifndef FILE_PLAYER_HPP_INCLUDED