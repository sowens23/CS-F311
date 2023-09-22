# CS-F311 Data Structures and Algorithms
## Class Notes and Homework Repository :dizzy: :earth_americas:
  ```
  #include <iostream>
  int main() {
    std::cout << "Hello traveller, here's a towel for protection. Take care of yourself out there." << std::endl;
    return 0;
  }
  ```

### Class Repositories and References
  - [sowens23-GitHub](https://github.com/sowens23)
  - [GitHubPortal](https://github.com/sowens23/Newbie-Gains/blob/main/README.md)
  - [CS-F311 Class Homepage](https://www.cs.uaf.edu/~chappell/class/2023_fall/cs311/)
  - [CS-F311 Class Git Repository](https://github.com/ggchappell/cs311-2023-03)
  - [Weekly In-Class Coding](https://github.com/sowens23/CS-F311/tree/main/inclasscoding)
  - [CPP Reference Page](https://en.cppreference.com/w/)

### Big Notes
  - Compiling: g++ -std=c++17 -o program program.cpp

# Class Notes and Assignments
  | Weekly Notes | Assignments | Other Notes |
  | --- | --- | --- |
  | [Week-1](#Week-1) | [HW01](https://github.com/sowens23/CS-F311/tree/main/homework/assignment1) | |
  | [Week-2](#Week-2) | [HW02](https://github.com/sowens23/CS-F311/tree/main/homework/assignment2) | |
  | [Week-3](#Week-3) | | |
  | [Week-4](#Week-4) | | |
  | [Week-5](#Week-5) | | |

# Week-4
[Top](#TOP)
## 2023-09-22
  - TODO: [fibo_fast.py](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230920)
  - TODO: [fibo_formula.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230920)
  - TODO: [fibo_fast.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230920)
  ### Review: Search Algorithms I
    - Binary Search finds a given key in a sorted list
    - Pivot is the item in the middle of a list, you compare the key to
    - Equality vs. Equivalence may not be the same thing when obkects being compared are not numbers
      - Equality: a == b
      - Equivalence: !(a < b) && !(b < a)
    - When using iterators
      | Using Operators | Using STL Function Templates |
      | --- | --- |
      | Random-access iterators only | Works with all forward iterators |
      |  | Still fast with random-access |
      | iter += n | std::advance(iter, n) |
      | iter + n | std::next(iter, n) |
      | iter2 - iter1 | std::distance(iter1, iter2) |

  ### Recursion vs. Iteration
  - Definitions
    - **Iteration**: Using one or more loops (Iterative)
    - **Recursion**: When a function calls itself (Recursive)
  - Fibo Again
    - Let's take what we have in fibo_first.cpp, then write it iteratively, then recursively.
      - tuple can contain an arbitrary amount of numbers, it's in #include <tuple>
      - pair can contain two numbers, it's in #include <utility>
      ```
      // fibo_first (Really slow)

      ```
      ```
      // fibo_iterative (Very fast)

      ```
      ```
      // fibo_recursive (??) Unfinished
      using bignum = uint_fast64_t;
      pair <bignum, bignum> fibo_recursive(int n) {
        // BASE CASE
          if (n == 0) {
            //return make_pair<bignum, bignum>(1,0);
            // Returning prev, and current
            return (1,0)
          }
        // RECURSIVE CASE
          // Older syntax
          // pair<bignum, bignum> = 
          auto [prev, curr] = fibo_recursive(n-1);
          return { curr, prev + curr };
      }

      bignum fibo(int n) {
        auto [prev, curr] = fibo_recursive(n);
        return curr;
      }
      ```
    - A tree can be used to represent function calls some algorithms make, this can be utilized to ealuate the speed of functions
    - The 2017 C++ Standard introduced **structured bindings**
      - Go from ``` pair<bignum, bignum> fibo_recurse(int n);```
      - To ``` auto [a, b] = fibo_recurse(k);```
        - a and b are variables of type bignum, a is fibo(k-1) and b is fibo(k)
  - Function-Call Intervals
    - A running program makes use of the **call stack**
      - From the stack, we only deal with the top, utilizing push, and pop controls
    - Items on the stack are stack frames
    - When analysing time using we care about calls,
    - When concerned about space we care about recursion depth, ie. the data piled onto the stack.
  - Drawbacks of Recursion
    - Recursive code can be more inefficient than iterative in two ways
      - function call overhead because recursion will create many articles of the same function, this essentially creates a lot of calls and pushes
      - The above reason will also utilize much more many
  - Fibo Yet Again
    - Dynamic Programming can greatly speed up some recursive algorithms

## 2023-09-20
  ### Review: Arrays & Linked Lists
  - Array stores a sequence of items, one after the other.
  - (Singly) Linked List stores the same kind of data but is made of nodes with pointers
  - Doubly Linked List stored the same kind of data, but with two points
  - Recursive algorithms make use of (call) themselves.
    - Base cases are the smallest problem which we solve directly.
    - Recursive cases are other problems
  - Reminder that the fibo.cpp program we worked on yesterday gets really slow, pretty quickly

### Search Algorithms I
- TODO: [Binary Search](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230920)
- Binary Search
  - Finds a given **key** in a sorted **list**
  - Procedure is to;  
    - Pick an item in the middle of the list: the **pivot**
    - Compare the given key with the pivot
    - Narrow search to top of bottom half of list. Then recurse till you find the **key**
  - When we are doing a binary search we want to do a few things
    - Pass two iterators that help reference the range, and the key we are looking for
    - Think about what we would like to return
      - Bool saying if it was found
      - Address of key
      - key value
  - C++ Binary Search
    ```
    template <typename RAIter, typename ValueType>
    bool binSearch(RAIter first,      
                  RAIter last,
                  const ValueType & findme)
                  // [first, last) is range to search
                  // value to find
    {
      // BASE CASE (If range is 0)
        if (last == first) return false;
        if (last == first+1) return *first == findme;

      // RECURSIVE CASE 
        auto pivotiter = first + (last-first)/2;
        if (findme < *pivotiter) {
            // Recursively search for first half of range
            return binSearch(first, pivotiter, findme);
        }
        else {
            // Recursively search for second half of range
            return binSearch(pivotiter, last, findme);
        }
    }
    ```
- Better Binary Search
  - How can we improve the above code?
  - In the above, we are using operater "<" to search, but we are using "==" to check for a match. We call this equality check
    - Equality: a == b;
    - Equivalence: !(a < b) && !(b < a)
  - However, we can check for equivalence, using the "<" for a quicker processing time
  - We're computing the size frequently by checking the range for 0, and 1
  - We are also computing two checks to see if the key is in the base case
  - Random-access iterators can do pointer-style artithmetic 
      - iter1 = iter2 + 3;
      - iter1 += 3;
    - std::advance(iter, n); // Is like iter +=n
    - std::distance(iter1, iter2); // Is like iter2 - iter1
      - These two functions are fast for random-access iteratorsl they may be slower for other iterators.
  - Improvement:
    - [Better Binary Search](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230920)
    - Check equivalence in the base case. Never use "==" on the value type.
    - Computer the size of the range once. Save this for later use
    - Only check for the base case once 
    - Replace pointer arithmetic with std::advance & std::distance. Allow the parameters to be forward iterators
  
## 2023-09-18
  ### Review: Using Exceptions
  - Error Conditions (often error) occured during runtime
    - Use 'try' and 'catch' to throw exceptions
  - We can 'catch all' by putting the exception logic in the try, if it's caught, then the entire code block in a catch condition, then using the catch to clean up code before we throw an exception
    - Confusing.
  - Destructors should not throw, generally they are marked noexcept  
  - Writing good, robust code that works is **hard work**. Error handling is an absolute part of programming.

  ### Arrays & Linked List
  - The simplist container data structure is the array.
  - A Linked List, is similar to an array. It's composed of nodes, each has a single data item, and a pointer. There is a null ptr at the end, and the head is a single data item which points to the first node.
  | Memory Address | Value | Node Ptr | Note |
  | -- | -- | -- | -- |
  | 0x1238123 | NULL | 0x1 | Head with array Length |
  | 0x1 | 612 | 0x2 | First Node |
  | 0x2 | 12 | 0x3 | Second Node |
  | 0x3 | 51223 | NULLPTR | Last Node |
  - We can't adjust the head to temporarily point farther down the list, because you would lose the addresses to the nodes in front of it.
  - We can quickly insert if we know the pointer address of one Node
    - Say, this node now points to new node, new node points to next node.
  - TODO: [Linked List Example](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230918)
  - A Doubly Linked List provides two points and a value. This is so it can be bi-directional
  - A Singly Linked List is your standard Linked List

  ### Introduction to Recursion
  - A recursive algorithm is one that makes use of itself.
    - Specifically it 'calls' itself.
  - return a == 1 ? b : 0;
    - Confusing '?' syntax. (Need to study)
  - When writing recursive algorithms, consider the four questions
    - How can we solve th problem using solutions to one or more smaller problems of the same kind
    - How much does each recursive call reduce the size of the problem
    - What instances of the problms can serve as base cases
    - As the problem size shrinks, will a base case always be reached
  - Fibonacci Numbers presents a good case of how recursion works
    - 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, ...
    - (Fn, for n = 0, 1, 2, ...) 
      - F0 = 0
      - F1 = 1
      - For n >= 2, Fn = Fn-2 + Fn-1
  - TODO: [Fibonacci](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4/230918)

# Week-3
[Top](#TOP)
## 2023-09-15
  ### Review: Managing Resources
  - Containers, Iterators, General Containers.
  - You can specify ranges using two iterators
  - Invariants exist as pre/post conditions and in class structures
  - Excercise, write pre- ad post- conditions for the one-parameter constructor for class
    ```
    //  0 <= _n && _n < 100
    class Abc {
      public:
        Abc(int nn)
          :_n(nn)
          // Answer -> Precondition: If nn is >= 0, and nn < 100
        {}
        [Other stuff here]
      private:
        int _n;
    }; // End class Abc
    // Answer -> Postcondition: If nn == _n, and 0 <= _n < 100
    ```
  - Invisible constructors (6 in total) 1 Constructor & the big 5

  ### Thoughts on Assignment 2
  - FSArray should use RAII
    - What type to use for the size of FSArray
  - FSArray is a generic container so it's member functions 'begin' and 'end' return iterators
  - Document preconditions for each function, and class invariants for each class
  - You will need to define all of the Big Five
  - FSArray and all global functions will be templates that go entirely in the header. Do not write a source file
    ```
    // template <typename ABC, typename XYZ>
    // Invariants: ...
    template <>
    class FSArray {...}
      // Pre: ...
      template
    ```
  - Const and non-const versions of operators and functions are permissable to duplicate code.

  ### Error Handling
  - Error Conditions
    - Error condition (often error) is not the same as a bug
    - Not always a result of bad code, sometimes process failed, or user related
      - We can prevent error conditions by writing preconditions
      - We can contain error conditions by handling it in the function
      - If not, we must then signal the client code after the function
  - Preview...
    - Three goals must always at the least be acheived when dealing with error conditions (Basic Guarantee)
    - 3-levels of Safety Guarantees:
      - Basic Guarantee: Error condition must not wreck the program, Objects must be usable, and resources must not leak
      - Strong Guarantee: We can successfully complete all operations and/or the error had no effect.
      - No-Throw Guarantee (No-Fail Guarantee): There is never a need to inform the client of an error.
  - Signaling Client Code
    - This is when we are unable to resolve errors. We must signal the client code.
    - Two common strategies are: Return codes and error-checking functions 
      - But they have downsides
      - The can be difficult to use in some places where values cannot be returned
      - Can lead to complicated code
    - We can throw an exception

  ### Using Exceptions
  - Exceptions & Catching
    - An exception is an object thrown to signal an error condition
      - 'new' throws 'std::bad_alloc' or a derived class if an allocation fails
      - To handle an exception, we 'catch' it using 'try... catch'
        ```
        #include <new> // for std::bad_alloc
        Foo * p;
        bool success - true; 
        try {
          p = new Foo;
        }
        // e is the exception, catch exceptions by reference
        catch (std::bad_alloc & e) {
          success = false;
          // Standard exception types have a member fucntion 'what' that returns a string
          cerr << "Allocation failed: " << e.what() << endl;
        }
        ```
    - We are only able to 'catch' an excpetion if we execute the code INSIDE of a 'try/catch' block. Which means if you run p1 = new FOO outside of a try block, it will never return an exception that can be 'caught'
    - An exception is actually able to always be caught in it's integrated block of catch.
      - If you run globalP1 = new Foo, inside of a function called by main.cpp
        - Main can catch this, but this functionality might not be best to lean on
    - What throws?
      - Built in operators, other than 'new', including operator[]
      - Deallocation done by delete
      - C++ Standard I/O Libraries
      - Functions written by others may throw, if you right 'throw' it will throw.
  - Throwing
    - We can throw our own exceptions using 'throw'
      ```
      class CC {
        public:
          int & operator[](std::size_t ix)
            // May throw std::out_of_range
          {
              if (ix >= _arrsize)
                throw std::out_of_range("CC::op[]: bad ix");
                return _arr[ix];
          }
      }
      ```
    - Always use or derive from one of the standard exception types
    - Standard exceptions have string members accessible using the what() function.
  - Catch all & Rethrow
    - You can use catch(...) to catch all exceptions
  - Exceptions, Deconstructors, noexcept
    - Fact 1: An objects dctor is called when it goes out of scope, even if an exception is thrown
    - Fact 2: If an exception is thrown, and a dctor is called before it calls, the program terminates
    - Thus: Destructors should not throw
    - Because dctors should not throw, they are generally marked as noexcept implicitly
      - We can make a dctor that is not noexcept using "noexcept (false)" Never do this.
  - CODE
    - To-Do [Iterators.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3/230915)
      - Write a function allocate2 that: (See allocate2.cpp)
        - Attempts to allocate two dynamic objects
        - Returns pointers to these objects, using referene parameters.
        - If either allocation fails, throw std::bad_alloc
        - Had no memory leaks
      - Look at example code showing how RAII can simplify these situations (See allocate2_raii.cpp)

## 2023-09-13
  ### Managing Resources in a Class & Containers and Iterators Review
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

  ### Containers and Iterators Cont.
  - Generic Algorithms
    - STL contains many, many algorithms at your disposal. Think excel functions
      [STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
      - #include <algorithm>
      - Be familiar with std::copy, std::equal, std::sort, std::fill
    - To-Do [Iterators.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3/230913)

  ### Software Engineering Concepts: Invariants
  - Basics
    - An Invariant is a condition that is always true at a particular point in a computation
      - Typically, it says something about the values of variables
      - Invariants can follow an 'if' statement 
        ```
        if (x < 0) return false
        // Invariant: x will always be greater than 0 at this point
        ```
  - Pre & Post
    - Precondition is an invariant at the beginning of the function
      - This states what must be true for the function to execute properly
    - Post condition describes the function's effet using statements about values
    - A functin offers an operation contract to it's caller
      " Caller, if you fulfill the preconditions, then I will fulfill the postconditions."
  - Class Invariants
    - A class invariant is an invariant that holds for an object of the class, whenever execution is not inside a member function
      - Class invariants are preconditions for every public member function, except constructors
      - They are postconditions for every public member function, except the destructor.
      - Invariants in practice are simply statements about data members that indicate whether an object can be valid and usable.
  - Documentation
    - Preconditions and class invariants are often identifiable through two kinds of assertions
      - Assertions about the parameters of a function
      - Assertions about the data members of an object
    - Preconditions and class invariants should be documented in comments, however do not restate class invariants before the function(?)
    - To-Do 
      - [timeofday.cpp & timeofday.hpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3/230913)
  
  ### Invisible Functions II
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
 
## 2023-09-11
  ### Containers and Iterators
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

  ### Review
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

  ### Continued
  - If a resource is never released, then we have a resource leak
  - the Owner of a resource is responsible for releasing it
  - Terminology
    - Acquire a resource: get access and control
    - Release a resource: clean it up and relingquish control

# Week-2
[Top](#TOP)
## 2023-09-08
  ### Invisible Functions I
  - You can also pass && R_values to R_values.
  - R_Values prefer to be passed by reference
    - voice g(Foo && p); Mutable.
    - void g(const Foo & p); Non-mutable variable

    | | By Value | By Reference | By Reference-to-Const | By Rvalue Reference |
    | --- | --- | --- | --- | --- |
    | Makes a copy | Yes :( | No :) | No :) | NO :) |
    | Allows for polymorphism | No :( | Yes :) | Yes :) | Yes :) |
    | Allows implicit type conversions | Yes :) | No :( | Yes :) | Yes :) |
    | Allows passing of: | Any copyable value :) | Non-const Lvalues :(? | Any value* :) |  Non-const Rvalues* |

  - *Rvalues prefer to be passed by Rvalue reference.
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
    1. Define it explicitly
    2. =delete it: Foo(const Foo & other) = delete;
    3. =default it: Foo(const Foo & other) = default;
    4. Do nothing.

  ### Managing Resources
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
    1. Create header and source
    2. Label everything
    3. Make dummy versions of everything
  - Creating a class
    1. Name of Class
    2. Give it reasonable Constructors
        - Default Constructor
        - Specific constructors
    3. Give it reasonable operators
        - Pre & Post operators
    4. Give it reaosnalbe member functions
    5. For each function, write assertions
  - *this
      ```
      *this // Is a pointer to the current object
      this - pointer current object
      x.foo()
      x+y // This equal x.operator+(y)
      ```
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
