/* Name: Spencer Owens
	 Class: 23F CS-311 Data Structures and Algorithms
	 Created: 2023-Sep-20
	 Updated: 2023-Sep-20

	 Program Name: fsarray.cpp
	 Program Function: 
				1) Name your class template FSArray whose items have type double would be declared as FSArray<double>
					- Everything in in the class will be a template
					- Class template acts as a single array with a given size and value type
				2) In the public interface include;
					- Default ctor that creates an FSArray object with size 8, which all items in the array are default constructed
				3) Create a dctor, copy ctor, move ctor, copy assignment, move assignment
					- Be sure that dctor frees any dynamically allocated memory
					- Each copy operation creates an entirely new copy of the data, as so modifying the copy leaves the original unaltered
					- Write these functions as described in the slides (Invisible Functions II)
				4) 1-parameter ctor, where the size is defined.
				5) 2-parameter ctor, where size is defined then a value for each item to be set to
				6) Bracket operator to return the array value from 0 to (size-1)
				7) Member Function
					- Size: no parameters, returns the size of array
					- Begin: no parameters, returns the address of item 0
					- End: no parameters, returns the address of the item one-past the end of the array
				8) Operators == that bools whether an array has same size, and all items are the same
					- and != that checks the opposite
				9) Operators <, >, <=, >=.
					- Two FSArray objects with different value types cannot be compared.
					- If they can be compared, these operators use lexicographic order, which works like alphabetical order processing all items of each array together 
				10) Define member types value_type, and size_type publicly
				11) const FSArray<T> does not does not allow modification (This has implications for how you implement functions behin and end, as well as the bracket operator)
				12)
*/

//#include <iostream>
//#include <ostream>
//#include <cassert>
//#include <string>
//#include <cctype>

// ***** ***** ***** ***** ***** ***** //
// Class FSArray - Class Definition		 //
// ***** ***** ***** ***** ***** ***** //

class FSArray{

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