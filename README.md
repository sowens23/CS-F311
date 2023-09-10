# CS-F311 Data Structures and Algorithms
## Class Notes and Homework Repository :dizzy: :earth_americas:
 
```
#include <iostream>
int main() {
	std::cout << "Hello traveller, here's a towel for protection. Take care of yourself out there." << std::endl;
  return 0;
}
```

## Class Repositories and References
  - [sowens23-GitHub](https://github.com/sowens23)
  - [GitHubPortal](https://github.com/sowens23/Newbie-Gains/blob/main/README.md)
  - [Class Homepage](https://www.cs.uaf.edu/~chappell/class/2023_fall/cs311/)
  - [Class Git Repository](https://github.com/ggchappell/cs311-2023-03)
  - [CPP Reference Page](https://en.cppreference.com/w/)

## Notes, Assignments, and Labs
  - | Weekly Notes | Assignments | Other Notes |
    | --- | --- | --- |
    | [Week-1](#Week-1) | [HW00](https://github.com/sowens23/CS-F301/blob/main/week1/hw00.cpp) | |
    | [Week-2](#Week-2) | [HW01](https://github.com/sowens23/CS-F301/blob/main/week2/hw01.asm) | |
    | [Week-3](#Week-3) | | |

# Big Notes
  - Compiling: g++ -std=c++17 -o program program.cpp

# Week-2
[Top](#TOP)
### 2023-09-08
  (Todays Material is not in HW01)
  ###### Invisible Functions I
  - You can also pass && R_values to R_values.
  - R_Values prefer to be passed by reference
    - voice g(Foo && p); Mutable.
    - void g(const Foo & p); Non-mutable variable

  | | By Value | By Reference | By Reference-to-Const | By Rvalue Reference |
  | Makes a copy | Yes :( | No :) | No :) | NO :) |
  | Allows for polymorphism | No :( | Yes :) | Yes :) | Yes :) |
  | Allows implicit type conversions | Yes :) | No :( | Yes :) | Yes :) |
  | Allows passing of: | Any copyable value :) | Non-const Lvalues :(? | Any value* :) | Non-const Rvalues* |
  * Rvalues prefer to be passed by Rvalue reference.

  - Every class has the Big five member functions
    - Default constructor (Not counting)
      - Written for you when you declare no constructor
    - Below (The big 5)
      - If you do anything with one of these, do all of them. This is the "Rule of Five"

      - Deconstructr
      - Copy constructor
      - Copy assignment operator
      - Move constructor
      - Move assignment operator
  
  - When you compile a class you have four options (You can write these 6 functions yourself, delete them, or set them to default)
    1) Define it explicitly
    2) =delete it: Foo(const Foo & other) = delete;
    3) =default it: Foo(const Foo & other) = default;
    4) Do nothing.

  ###### Managing Resources
  ```
  int n;
  int * p = &n // p is a pointer. '&' is the "address-of" operator
  p = nullptr; // A null pointer does not point at anything. 
                // You can also check for it: if (p == nullptr)
  p = new int; // Dynamc Allocation
  delete p; // Deallocation
  ```
  - For each ''new'' there must be a ''delete''
  - When destructors are executed:
    - Automatic objects are deconstructed when they go out of scope
    - Static objects are deconstructed when the program ends
    - non-static member objects are deconstructed when the object it is a member of is destroyed
  
    - This means that 'dynamic' objects are the only objects that need to be manually  managed.
  - Resource Acquisition Is Initialization (RAII)
    - This is a programmng idiom
    - It means we always deallocate in the destructor - if the memory in question has not been deallocated by that point.

  -

  - Terminology
    - Pass by Rvalue reference: For low level code

### 2023-09-06
  - The general difference between your .h, and .hpp files are that the .hpp signifies that the H for header file is for c Plus Plus .hpp.
  - Every function gets it's asserts
  - Avoid duplication of code
    - Post increments usually call the preincrents, this is how you can avoid duplication of code
  - DRY Principle
    - Every piece of knowledge must have a single, unambiguous authoritative represenation within a system
  - There are three ways to deal with the possibilities of invalid parameter values
    - Before the function
      - Insist that given parameters are valid.
    - During the function
      - Allow invalid parameter values, but fix them in the function
    - After the function
      - If invalid parameter values are passe, then signal the client code that there is a problem.
    - #1 is usually the easiest.

    - We must work in a specific order
      - Write dummy version of all required components
        - Make sure the code compiles.
      -
  

  ```
  class Skink {
  private:
    int _feet;
  public :
    Skink()
    {
      // We like special naming conventions
      _feet = g
    }
  }
  ```

  - Terminology
    - Member Initializers are generally preferred to assignment of data memebers.
  - Unit Testing - tests

# Week-1
[Top](#TOP)
### 2023-09-01
  - Start classes with a capital letter ie. TimeOfDay
  - Start function with lowercase, then capital ie. calculateTime
  - Const is a qualifier (Like virtual and mutable*)
  - Name Data Members (Usually in the private area of classe) in a particular way ie. _secs

  - Steps to creating a program
    1) Create header and source
    2) Label everything
    3) Make dummy versions of everything

  - Creating a class
    1) Name of Class
    2) Give it reasonable Constructors
      Default Constructor
      Specific constructors
    3) Give it reasonable operators
      Pre & Post operators
    4) Give it reaosnalbe member functions
    5) For each function, write assertions

  - *this
    *this // Is a pointer to the current object
    this - pointer current object
    x.foo()
    x+y // This equal x.operator+(y)

  - Terminology  
    - Project: Is a place to put the files for a particular executable
    - Assertion: is a statement made in code that something must be true - or else the code is not working properly
    - Boolean expression: Something True or False

### 2023-08-30
  - Terminology
    - Abstraction: Considering how a software component in terms of how and why it's used
    - Component: is just a general term for a thing: function, class, package, etc
    - Client: is a term used for code that makes use of a component
    - User: is a person
    - Functional Abstraction: 

### 2023-08-28
  - Expressions are things with values
    - Every expression has a type
    - Every expression is either an Lvalue or an Rvalue
      - Lvalue "ELL value" has a value that persists beyond the immediate expression
        int bb = 1;
      - Rvalue "ARR value" only exists in the immediate expression
        cout << "bb + 1";

  - Evaluating an expression means determining it's value
