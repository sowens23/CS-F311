// allocate2.cpp  UNFINISHED
// Glenn G. Chappell
// 2022-09-14
//
// For CS 311 Fall 2023
// Out-of-memory handling using exceptions

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <new>
using std::bad_alloc;


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// class Named
// Given name in ctor. construction. On both construction and
// destruction, prints this name along with a message.
// Invariants:
//     _name is the parameter passed to the ctor.
class Named {

// ***** Named: ctors, dctor, op= *****
public:

    // Ctor from string
    // Store given string as name. Print name with a message to cout.
    // May throw std::bad_alloc.
    Named(const string & name)
        :_name(name)
    {
        // UNCOMMENT ONE OR MORE LINES BELOW TO SEE WHAT WOULD HAPPEN IF
        // ALLOCATION FAILED AND "new" THREW AN EXCEPTION.

        if (false
            // || _name == "Object A"
            // || _name == "Object B"
            )
        {
            cout << _name << " CREATION FAILED; THROWING\n";
            throw bad_alloc();
        }

        // ******************************************************
        // * In practice, we NEVER do a throw like that above;  *
        // * "new" does it. We are signalling a fake error, to  *
        // * see what would happen if "new" did actually throw. *
        // ******************************************************

        cout << _name << " created\n";
    }

    // Dctor
    // Print name with a message to cout.
    ~Named()
    {
        cout << _name << " destroyed\n";
    }

    // No other Big Five functions
    Named(const Named & other) = delete;
    Named(Named && other) = delete;
    Named & operator=(const Named & rhs) = delete;
    Named & operator=(Named && rhs) = delete;

// ***** Named: data members *****
private:

    string _name;  // Object's name; print on destruction

};


// allocate2
// Attempt to allocate two Named objects, with names "Object A" and
// "Object B". Return pointers to these in nptra, nptrb. Throws
// exception thrown by "new" (derived class of std::bad_alloc) if either
// allocation is unsuccessful.
// Pre: None.
// Post:
//     nptra points to object with name "Object A", allocated with new,
//      ownership transfered to caller.
//     nptrb points to object with name "Object B", allocated with new,
//      ownership transfered to caller.
// May throw std::bad_alloc or derived class.
void allocate2(Named * & nptra,
               Named * & nptrb)
{
    // THIS MIGHT BE WRONG. TODO: WRITE THIS FUNCTION CORRECTLY!!!
    /* nptra = new Named("Object A"); // BAD CODE
    nptrb = new Named("Object B"); */
    nptra = new Named("Object A");
    try {
        nptrb = new Named("Object B");
    }
    catch (...) {
        delete nptra;
        throw;
    }
}


// Main program
// Demonstrates calling allocate2 with proper catching.
int main()
{
    // Call allocate2
    bool allocate2Successful;  // true if allocations are successful
    Named * npa;
    Named * npb;
    try
    {
        allocate2(npa, npb);
        allocate2Successful = true;
        cout << "Call to \"allocate2\" successful\n";
    }
    catch (bad_alloc & e)
    {
        allocate2Successful = false;
        cout << "Call to \"allocate2\" NOT successful\n";
        cout << "  exception caught [what = '" << e.what() << "']\n";
    }

    if (allocate2Successful)
    {
        cout << "\n";
        cout << "Deallocating objects from \"allocate2\":"
             << " Object A, Object B\n";
        delete npa;
        delete npb;
    }
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

