/* 
Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: Word Count (Assignment 8, part a)
Created: 2023-Dec-02
Updated: 2023-Dec-02
File Name: wordcount.cpp
Current Version: 1
File Function: 

Version History:
- v1:
*/

// Includes for main
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
#include <string>
using std::string;
using std::getline;
#include <fstream>
using std::ifstream;
#include <map>
using std::map;

// Main for wordcount.cpp
//  Open file from filename input from user
//  Error check, then read word by word
//  Input directed into map
int main () {
    // Declare variables
    string filename;
    string line;
    string word;
    map<string, int> wordcount;
    
    // User input for filename
    cout << "Please enter filename to count: ";
    getline(cin, filename);

    // Open file, error check
    ifstream file(filename);
    if (!file) {
        if (filename == "") cerr << "No filename entered" << endl;
        else cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // Read words from file
    while (getline(file, line)) {
        while (file >> word) {
            ++wordcount[word];
        }
    }

    // If file read ends early, error
    if (!file.eof()) {
        cerr << "Error occurred while reading the file." << endl;
        return 1;
    }

    // Print desired output
    cout << "Number of distinct words: " << wordcount.size() << endl << endl;
    for (const auto & pair : wordcount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Return main
    return 0;
}