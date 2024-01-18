/* 
Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: TimSort (Honors Project)
Created: 2023-Dec-06
Updated: 2023-Dec-06
File Name: timsort.cpp
Current Version: 1
File Function: Temp .cpp file to hold main for unofficial testing.

Version History:
- v1:
- v0:
*/

#include "timsort.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;

int main () {
    // User input to declare vector size
    int vectorsize=0;
    cout << "Please enter array size to be sorted: ";
    cin >> vectorsize;

    // Initialize vector
        cout << "Randomizing vector...\n\n";
        vector<int> vector_1 = generateRandArray(vectorsize);

    // Print unsorted vector
        cout << "Unsorted: ";
        for (int i : vector_1) cout << i << ", "; cout << "\n";
        cout << "\n";

    // Sort vector
        timSort(vector_1);

    // Print sorted vector
        cout << "\nSorted...\n";
        for (int i : vector_1) cout << i << ", "; cout << "\n\n";

    return 0;
}