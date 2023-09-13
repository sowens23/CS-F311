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
  - [CS-F311 Class Homepage](https://www.cs.uaf.edu/~chappell/class/2023_fall/cs311/)
  - [CS-F311 Class Git Repository](https://github.com/ggchappell/cs311-2023-03)
  - [Weekly In-Class Coding](https://github.com/sowens23/CS-F311/tree/main/inclasscoding)
  - [CPP Reference Page](https://en.cppreference.com/w/)

## Notes, Assignments, and Labs
  | Weekly Notes | Assignments | Other Notes |
  | --- | --- | --- |
  | [Week-1](#Week-1) | [HW01](https://github.com/sowens23/CS-F311/tree/main/homework/assignment1) | |
  | [Week-2](#Week-2) | [HW02](https://github.com/sowens23/CS-F311/tree/main/homework/assignment2) | |
  | [Week-3](#Week-3) | | |

# Big Notes
  - Compiling: g++ -std=c++17 -o program program.cpp

# Week-3
### 2023-09-13
  ###### Managing Resources in a Class & Containers and Iterators Review
    - Some resources need to be cleaned up, we aquire/allocate a resource we release it
      - If we don't, this is a resource/memory leak.
    - RAII, concept of owning your objects
      - Big Five, define one, define all
        - You have 3 options, Define it, delete it, default it
    - A container is a data structure that can old multiple items, usually the same type
      - A generic container is a container that can hold items of a client specified type
        - std::vector is an example of a generic container 'vector<int>'
        - std::map
        - std::list, etc.
    - An Iterator refers to an item in a container.
      - All STL containers have iterator interfaces
      - Iterators points to a location in a container
      - An iterator may be a wrapper, to make data look like a container
    - We can specify a range using two iterators

  ###### Containers and Iterators Cont.
    Generic Algorithms
      - STL contains many, many algorithms at your disposal. Think excel functions
        [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
        - #include <algorithm>
        - Be familiar with std::copy, std::equal, std::sort, std::fill
      - To-Do [Iterators.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3/230913)

  ###### Software Engineering Concepts: Invariants
    Basics
      - An Invariant is a condition that is always true at a particular point in a computation
        - Typically, it says something about the values of variables
        - Invariants can follow an 'if' statement 
        ```
        if (x < 0) return false
        // Invariant: x will always be greater than 0 at this point
        ```
    Pre & Post
      - Precondition is an invariant at the beginning of the function
        - This states what must be true for the function to execute properly
      - Post condition describes the function's effet using statements about values
      - A functin offers an operation contract to it's caller
        " Caller, if you fulfill the preconditions, then I will fulfill the postconditions."
    Class Invariants
      - A class invariant is an invariant that holds for an object of the class, whenever execution is not inside a member function
        - Class invariants are preconditions for every public member function, except constructors
        - They are postconditions for every public member function, except the destructor.
        - Invariants in practice are simply statements about data members that indicate whether an object can be valid and usable.
    Documentation
      - Preconditions and class invariants are often identifiable through two kinds of assertions
        - Assertions about the parameters of a function
        - Assertions about the data members of an object
      - Preconditions and class invariants should be documented in comments, however do not restate class invariants before the function(?)
      - To-Do 
        - [timeofday.cpp & timeofday.hpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3/230913)
      - 
  ###### Invisible Functions II
    - Recall the big five
      - Deconstructor, Copy Constructor, Copy assignment operator, Move constructor, Move assignment operator
      - We simply don't like rewriting code that we don't need to read
      - We do one of four things. Do not write any, or
        - Delete them, Default them, Define them
    - To Copy
      - Create new object, set it's size member, and allocate a memory block of the correct size
      - Copy array objects into new array
      - If the array is large, sometimes a copy can fail and cause error
    - To Move
      - Set each data member of the new object to the corresponding member
      - Set the original to a nothing value to be destroyed
    - To Swap
      - std::swap (or something) can actuallly swap to values
        ```
        private:
          void mswap(Foo & other) noexcept // noexcept will turn off exceptions for an operator
          {
            swap(_a, other._a);
            swap(_b, other._b);
          }
        ```
    - Once you you have a swap operation, it's easy to write copy and assignment operations. See slide 31
      
 
### 2023-09-11
  ###### Containers and Iterators
  - A type is first class if it is dynamically mutable, can be passed and returned and stored
  - std::vector is a first class array
    - This is a class template, not a class
    - We can call std::vector a smart array
  - Operations available on an iterator match the underlying data 
    - Random Access data can be dealt with in any order
    - Sequential Access data
      - bidirectional: accessible in both forward and backward
      - forward-only: accessible in only forward
  - An iterator can be used as a 'wrapper', which can make it look like a container
    ```
    int a[10];
    func(a);
    func(&a[0]) // Same as above
    // func cannot tell the size of the array it receives
    ```
  - Iterators are fundamental to the range-based for-loop, a flow-of-control construct
  - 

  - We can specify a range by using two iterators
    ```
    #include <algorithm>
    using std::sort;
    sort(begin(v)+2, begin(v)+6); // Sort v[2]..v[5]
    sort(begin(v), end(v)); // Sort all of v
    ```

  - Terminology
    - Container: is a data structure that can hold multiple items, usually all of the same type
    - Generic Container: can hold items of a client-specified tyoe
      - C++ built-in array is a generic container
      - There are atleast 14; vector, basic_string, array, list, forward_list, deque, map, set, unordered_map, unordered_set, multimap, multiset, unordered_multimap, unordered_multiset
      - All of the above have an interface that involve iterators
      - 3 Questions for implementations
        - ?
        - ?
        - ?
    - C++ Standard Template Library (STL for short)
    - Iterator: Refers to an item in a container
      ```
      vector<int> v(7);
      vector<int>::iterator iter1 = begin(v); // member function 'begin' will return an iterator to the first item in the container
      v[0] = 3;
      cout << *iter; // Prints "3"
      *iter = 5; // Set v[0] to 5
      ```
    - 


  ###### Managing Resources in a Class
  ###### Review
  - We do not pass by Rvalue reference very often.
  - Except- ions may cause a functon to exit, even if there is no return
  - "To Own Memory/Object" is to be responsible for releasing (deallocating) that memory
  - Prevent memory leaks with RAII
    - Define, =delete, or =default for each of the Big Five


  - Terminology
    - The Rule of Five, if you define one, define the others explicitely 
      - Dctor, Copy ctor, copy assignment operator, move ctor, move assignment operator
    - Dynamically Allocated memory & objects need clean-up when we are done with them
      - If we never deallocate, then there is a memory leak
    -RAII: Resource Acquisition Is Initialization
      - Resource Acquisition
      - Resource Usage
      - Resource Release

  ###### Continued
  - If a resource is never released, then we have a resource leak
  - the Owner of a resource is responsible for releasing it

  - Terminology
    - Acquire a resource: get access and control
    - Release a resource: clean it up and relingquish control

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
