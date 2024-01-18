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

bool isOrdered(vector<int>& vector_t) {
    int j=-9999999;
    for (int i : vector_t) {
        if (i < j) return false;
        j = i;
    }
    return true;
}

// Function to randomize a number of ints
vector<int> generateRandArray(int size) {
    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    vector<int> vector_t(size);
    for (int i = 0; i < size; ++i) {
        // Fill array with random numbers between 0 and 99
        vector_t[i] = rand() % 1000;
    }
    return vector_t;
}

// Function to perform Insertion Sort on each 'run' from Tim Sort
void insertionSort(vector<int>& vector_t, int left, int right) {
    // Loop through the run and sort it using insertion sort
    for (int i = left + 1; i <= right; ++i) {
        int key = vector_t[i];
        int j = i - 1;
        
        // Move elements greater than key to the right
        while (j >= left && vector_t[j] > key) {
            vector_t[j+1] = vector_t[j];
            j--;
        }

        // Insert the key into the correct position
        vector_t[j + 1] = key;
    }
}

// Function to perform Tim Sort
void timSort(std::vector<int>& vector_t) {
    // Set array and run size
    int vec_size = vector_t.size();
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
            //         if (j < run_size - 1) cout << vector_t[i + j] << ", ";
            //         else cout << vector_t[i + j];
            //     }
            //     cout << "] ";
            // }
            // cout << "\n\n";

        for (int i = 0; i < vec_size; i += run_size * 2) {
            // Calculate the right boundary of the current run
            int right = std::min(i + run_size * 2 - 1, vec_size - 1);

            // Call Insertion sort with array by reference, left index, and right index
            insertionSort(vector_t, i, right);
        }

        // Double the run size, we do this until it's greater than vec_size
        run_size *= 2;
    }
    
    // If there's a remainder of elements, sort them separately
    if (run_size > vec_size) {
        insertionSort(vector_t, 0, vec_size - 1);
    }
}

#endif //#ifndef FILE_TIMSORT_HPP_INCLUDED