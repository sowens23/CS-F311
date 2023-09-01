# CS-F311
 Data Structures and Algorithms

Class Homepage: https://www.cs.uaf.edu/~chappell/class/2023_fall/cs311/
CPP Reference Page: https://en.cppreference.com/w/
Class Git Repository: https://github.com/ggchappell/cs311-2023-03

Big Notes
  Compiling: g++ -std=c++17 -o program program.cpp



Week 1 

2023-09-01
  Start classes with a capital letter ie. TimeOfDay
  Start function with lowercase, then capital ie. calculateTime

  Steps to creating a program
    1) Create header and source
    2) Label everything
    3) Make dummy versions of everything

  Creating a class
    1) Name of Class
    2) Give it reasonable Constructors
      Default Constructor
      Specific constructors
    3) Give it reasonable operators
      Pre & Post operators
    4) Give it reaosnalbe member functions
    5) For each function, write assertions

  *this
    *this // Is a pointer to the current object
    this - pointer current object
    x.foo()
    x+y // This equal x.operator+(y)

  Terminology  
    Project: Is a place to put the files for a particular executable
    Assertion: is a statement made in code that something must be true - or else the code is not working properly
    Boolean expression: Something True or False

2023-08-30
  Terminology
    Abstraction: Considering how a software component in terms of how and why it's used
    Component: is just a general term for a thing: function, class, package, etc
    Client: is a term used for code that makes use of a component
    User: is a person
    Functional Abstraction: 

2023-08-28
  Expressions are things with values
    Every expression has a type
    Every expression is either an Lvalue or an Rvalue
      Lvalue "ELL value" has a value that persists beyond the immediate expression
        int bb = 1;
      Rvalue "ARR value" only exists in the immediate expression
        cout << "bb + 1";

  Evaluating an expression means determining it's value

  Generally when 
