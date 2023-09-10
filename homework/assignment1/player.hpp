// Name: Spencer Owens
// Class: 23F CS-311 Data Structures and Algorithms
// Date: 2023-Sep-09
// Program Name: player.hpp
// Program Function: Header file for player.cpp

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <ostream>
#include <cassert>
#include <string>

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
		void createPlayer (std::string realname, std::string username, int games);

		// getRealName: to return realname of Player
		// Function defined in source file
		std::string getRealName () const;

		// getUsername: to return username of Player
		// Function defined in source file
		std::string getUsername () const;

		// getGames: to return game count of Player
		// Function defined in source file
		int getGames () const;

		// setRealName: to set realname of Player
		// Function defined in source file
		void setRealName (std::string realname);

		// setUsername: to set username of Player
		// Function defined in source file
		void setUsername (std::string username);

		// setGames: to set game count of Player
		// Function defined in source file
		void setGames (int games);

		// toString: To return a string value identical to cout << player
		// Function defined in source file
		std::string toString () const;

		// inactive: To return boolian whether player has 0 games
		// Function defined in source file
		bool inactive () const;

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
	std::ostream & operator<<(std::ostream & str, const Player & obj);

#endif //#ifndef FILE_PLAYER_HPP_INCLUDED