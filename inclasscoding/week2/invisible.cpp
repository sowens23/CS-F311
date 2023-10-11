// invisible.cpp
// Glenn G. Chappell
// 2023-09-08
//
// For CS 311 Fall 2023
// Demo of invisible functions

// *****************************************************
// * NOTE: THIS IS DELIBERATELY CONFUSING (BAD!) CODE. *
// * DO NOT IMITATE IT!                                *
// *****************************************************

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// class Cat
// Default ctor & dctor print messages.
class Cat {

// ***** Cat: ctor, dctor *****
public:

    // Default ctor
    // Prints a message to cout.
    Cat()
    {
        cout << "Meow." << endl;
    }

    // Dctor
    // Prints a message to cout.
    ~Cat()
    {
        cout << "Hiss!!!" << endl;
    }

};  // End class Cat


// class Dog
// What member functions does this have?
class Dog {

// ***** Dog: Data members *****
private:
    int _a;
    Cat _b;

};  // End class Dog


// Global variables
// This runs before main, because global variables are constructed in order with main sequentially
vector<Dog> puppies(7); // Constructs 7 Dogs in a vector called puppies


// Main program
// Do-almost-nothing program - prints a message.
int main()
{
    cout << "Hello there, everyone!" << "\n";
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

