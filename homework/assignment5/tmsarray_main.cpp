/* 
    Name: Spencer Owens
    Class: 23F CS-311 Data Structures and Algorithms
    Created: 2023-Nov-01
    Updated: 2023-Nov-01

    File Name: tsmarray_main.cpp
    File Function: 
*/

#include "tmsarray.hpp"  // For class TMSArray
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <iterator>
using std::begin;
using std::end;
#include <algorithm>
using std::sort;
using std::copy;
using std::swap;
#include <cassert>
#include <vector>
using std::vector;
// For assert

// Main program
// Do some things with TMSArray. Avoid moving, assigning, resizing,
// swapping of TMSArray values.
int main()
{
    cout << "TMSArray push_back & pop_back\n";
    cout << "Many push_back & pop_back calls\n";

    vector<int> v { 1, 3, 4, 2, 6, 8, 7, 4, 5 }; // v.size() = 9
    TMSArray<int> ti(v.size());

    copy(v.begin(), v.end(), ti.begin());

    const int BIGCOUNT = 100;
    int smallcount = 0;
    // const int BIGCOUNT = 100000;

    cout << ti._capacity << " : " << ti.size() << endl;
    ti.pop_back();
    ti.pop_back();
    ti.pop_back(); // ti.size() = 6
    cout << ti._capacity << " : " << ti.size() << endl;
    for (int i = 0; i < BIGCOUNT+2; ++i)
    {
        smallcount++;
        ti.push_back(11); // Add 102
        cout << ti._capacity << " : " << ti.size() << " : "  << smallcount << endl;
    }
    cout << ti.size() << " : "  << smallcount << endl;
    ti.push_back(-100);
    for (int i = 0; i < BIGCOUNT+1; ++i)
    {
        ti.pop_back();
    }
    for (int i = 0; i < BIGCOUNT+1; ++i)
    {
        ti.push_back(12);
    }
    for (int i = 0; i < BIGCOUNT; ++i)
    {
        ti.pop_back();
    }
    for (int i = 0; i < BIGCOUNT+2; ++i)
    {
        ti.push_back(13);
    }
    for (int i = 0; i < BIGCOUNT; ++i)
    {
        ti.pop_back();
    }

    vector<int> v2 { 1, 3, 4, 2, 6, 8, 11, 11, 12, 13, 13 };

    cout << "does push_back + pop_back = check size\n";
    cout << ti.size() << " == " << v2.size() << endl;

    cout << "push_back + pop_back = check values\n";
    bool check1 = true;
    while(check1) {
        for (size_t i = 0; i < v2.size(); ++i)
            {
                if (ti[i] != v2[i]) {
                    cout << ti[i] << " != " << v2[i] << " at " << i << endl;
                    check1 = false;
                }
            }
        check1 = false;
    }
}

