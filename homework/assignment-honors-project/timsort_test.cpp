/* 
Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: Tim Sort Test (Honors Project)
Created: 2023-Dec-06
Updated: 2023-Dec-06
File Name: timsort_test.cpp
File Function:
Version History:
- v1:
*/

// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, timsort.hpp

// Includes for code to be tested
#include "timsort.hpp"

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

// For doctest framework
#include "doctest.h"

// *********************************************************************
// Test Cases
// *********************************************************************

TEST_CASE("Squaring Whole Numbers")
{
    SUBCASE("Testing positive numbers") {
        {
        INFO("Sqaring 3");
        int arg = 3;
        int result = 9;
        REQUIRE(arg == result);
        }
    }
}
