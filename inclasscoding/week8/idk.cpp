/* 
  Name: Spencer Owens
  Class: 23F CS-311 Data Structures and Algorithms
  Created: 2023-Oct-16
  Updated: 2023-Oct-16

  Program Name: idk.cpp
  Program Function: idk
*/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <list>
using std::list;
#include <algorithm>
using std::sort;
#include <iterator>
using std::begin;
using std::end;
#include <functional>
using std::greater;

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}

// Main program
int main()
{

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
    return 0;
}

