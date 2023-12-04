/* 
Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: Squarer Test (Assignment 8, part b)
Created: 2023-Dec-02
Updated: 2023-Dec-02
File Name: squarer_test.cpp
Current Version: 1
File Function: Based on squarer_test.cpp SKELETON by Glenn G. Chappell

Version History:
- v1:
*/

// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.hpp

// Includes for code to be tested
#include "squarer.hpp"       // For class Squarer

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
                             // doctest writes main for us
#include "doctest.h"         // For doctest framework

// *********************************************************************
// Test Cases
// *********************************************************************

TEST_CASE("Squaring Whole Numbers")
{
    Squarer sq;
    SUBCASE("Testing positive numbers") {
        {
        INFO("Sqaring 3");
        int arg = 3;
        int result = 9;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 5");
        int arg = 5;
        int result = 25;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 7");
        int arg = 7;
        int result = 49;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 10");
        int arg = 10;
        int result = 100;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 25");
        int arg = 25;
        int result = 625;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 79");
        int arg = 79;
        int result = 6241;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 549");
        int arg = 549;
        int result = 301401;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 1927");
        int arg = 1927;
        int result = 3713329;
        REQUIRE(sq(arg) == result);
        }
    }
    SUBCASE("Testing negative numbers") {
        {
        INFO("Sqaring -3");
        int arg = -3;
        int result = 9;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -5");
        int arg = -5;
        int result = 25;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -7");
        int arg = -7;
        int result = 49;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -10");
        int arg = -10;
        int result = 100;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -25");
        int arg = -25;
        int result = 625;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -79");
        int arg = -79;
        int result = 6241;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -549");
        int arg = -549;
        int result = 301401;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -1927");
        int arg = -1927;
        int result = 3713329;
        REQUIRE(sq(arg) == result);
        }
    }
}

TEST_CASE("Squaring Whole Const Numbers")
{
    const Squarer sq;
    SUBCASE("Testing positive whole numbers") {
        {
        INFO("Sqaring 3");
        int arg = 3;
        int result = 9;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 5");
        int arg = 5;
        int result = 25;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 7");
        int arg = 7;
        int result = 49;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring 10");
        int arg = 10;
        int result = 100;
        REQUIRE(sq(arg) == result);
        }
    }
    SUBCASE("Testing negative whole numbers") {
        {
        INFO("Sqaring -3");
        int arg = -3;
        int result = 9;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -5");
        int arg = -5;
        int result = 25;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -7");
        int arg = -7;
        int result = 49;
        REQUIRE(sq(arg) == result);
        }
        {
        INFO("Sqaring -10");
        int arg = -10;
        int result = 100;
        REQUIRE(sq(arg) == result);
        }
    }
}

TEST_CASE("Squaring Floats")
{
    const Squarer sq;
    SUBCASE("Testing positive float numbers") {
        {
        INFO("Sqaring 3.5");
        float arg = 3.5;
        float result = 12.25;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
        {
        INFO("Sqaring 5.75");
        float arg = 5.75;
        float result = 33.0625;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
        {
        INFO("Sqaring 7.13");
        float arg = 7.13;
        float result = 50.8369;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
        {
        INFO("Sqaring 137.189");
        float arg = 137.189;
        float result = 18820.821721;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
    }
    SUBCASE("Testing positive float numbers") {
        {
        INFO("Sqaring -3.5");
        float arg = -3.5;
        float result = 12.25;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
        {
        INFO("Sqaring -5.75");
        float arg = -5.75;
        float result = 33.0625;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
        {
        INFO("Sqaring -7.13");
        float arg = -7.13;
        float result = 50.8369;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
        {
        INFO("Sqaring -137.189");
        float arg = -137.189;
        float result = 18820.821721;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
    }
}

TEST_CASE("Squaring Special Cases") {
    Squarer sq;
    SUBCASE("Squaring -1") {
        {
        INFO("Sqaring -1");
        float arg = -1;
        float result = 1;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
    }
    SUBCASE("Squaring 1") {
        {
        INFO("Sqaring 1");
        float arg = 1;
        float result = 1;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
    }
    SUBCASE("Squaring 0") {
        {
        INFO("Sqaring 0");
        float arg = 0;
        float result = 0;
        REQUIRE(sq(arg) == doctest::Approx(result));
        }
    }
}