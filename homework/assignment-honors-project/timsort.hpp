/* 
Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: TimSort (Honors Project)
Created: 2023-Dec-06
Updated: 2023-Dec-06
File Name: timsort.hpp
Current Version: 1
File Function: Header file to hold functionality of Tim Sort, used in timsort.cpp and timsort_test.cpp

Version History:
- v1:
- v0:
*/

#ifndef FILE_TIMSORT_HPP_INCLUDED
#define FILE_TIMSORT_HPP_INCLUDED

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

// Function to perform Insertion Sort on each 'run' from Tim Sort
void insertionSort(vector<int>& array, int left, int right) {
    // Loop through the run and sort it using insertion sort
    for (int i = left + 1; i <= right; ++i) {
        int key = array[i];
        int j = i - 1;
        
        // Move elements greater than key to the right
        while (j >= left && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }

        // Insert the key into the correct position
        array[j + 1] = key;
    }
}

// Function to perform Tim Sort
void timSort(std::vector<int>& vector) {
    // Set array and run size
    int vec_size = vector.size();
    int run_size = 2; // Unnecessarily set initial run size to 2 to show that it's working

    // Check if the array size is odd, and if so, set the first run's size to 3
    if (vec_size % 2 != 0) {
        run_size = 3;
    }

    // Divide the array into runs and sort each
    while (run_size < vec_size) {
        // Print each iteration to show that Tim Sort is actually working as expected.
            // for (int i = 0; i < vec_size; i += run_size) {
            //     cout << "[";
            //     for (int j = 0; j < run_size; j++) {
            //         if (j < run_size - 1) cout << vector[i + j] << ", ";
            //         else cout << vector[i + j];
            //     }
            //     cout << "] ";
            // }
            // cout << "\n\n";

        for (int i = 0; i < vec_size; i += run_size * 2) {
            // Calculate the right boundary of the current run
            int right = std::min(i + run_size * 2 - 1, vec_size - 1);

            // Call Insertion sort with array by reference, left index, and right index
            insertionSort(vector, i, right);
        }

        // Double the run size, we do this until it's greater than vec_size
        run_size *= 2;
    }
    
    // If there's a remainder of elements, sort them separately
    if (run_size > vec_size) {
        insertionSort(vector, 0, vec_size - 1);
    }
}

#endif //#ifndef FILE_TIMSORT_HPP_INCLUDED