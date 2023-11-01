# CS-F311 Data Structures and Algorithms
## Class Notes and Homework Repository :dizzy: :earth_americas:
  ```
  #include <iostream>
  int main() {
    std::cout << "Hello traveller, here's a towel for protection. Take care of yourself out there." << std::endl;
    return 0;
  }
  ```
  ![Hitchhikers Guide to the Galaxy](https://github.com/sowens23/CS-F311/blob/main/inclasscoding/week1/tenor.gif)

### Class Repositories and References
  - [sowens23-GitHub](https://github.com/sowens23)
  - [GitHubPortal](https://github.com/sowens23/Newbie-Gains/blob/main/README.md)
  - [CS-F311 Class Homepage](https://www.cs.uaf.edu/~chappell/class/2023_fall/cs311/)
  - [CS-F311 Class Git Repository](https://github.com/ggchappell/cs311-2023-03)
  - [Weekly In-Class Coding](https://github.com/sowens23/CS-F311/tree/main/inclasscoding)
  - [CPP Reference Page](https://en.cppreference.com/w/)

### Big Notes
  - Compiling: 
    - g++ -std=c++17 -o program program.cpp
    - python3 program.py
  - VSCode: ctrl-k ctrl-s opens hotkey

  **The Cauchy-Schwarz Inequality**
    $$\left( \sum_{k=1}^n a_k b_k \right)^2 \leq \left( \sum_{k=1}^n a_k^2 \right) \left( \sum_{k=1}^n b_k^2 \right)$$

  **The Quadratic Formula**
  When $a \ne 0$, there are two solutions to $(ax^2 + bx + c = 0)$ and they are 
$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a} $$

# Class Notes and Assignments
  | Weekly Notes | Assignments | Other Notes |
  | --- | --- | --- |
  | [Week-1](#Week-1) | | |
  | [Week-2](#Week-2) | [HW01](https://github.com/sowens23/CS-F311/tree/main/homework/assignment1) | |
  | [Week-3](#Week-3) | [HW02](https://github.com/sowens23/CS-F311/tree/main/homework/assignment2) | |
  | [Week-4](#Week-4) | [HW03](https://github.com/sowens23/CS-F311/tree/main/homework/assignment3)| |
  | [Week-5](#Week-5) | | |
  | [Week-6](#Week-6) | | |
  | [Week-7](#Week-7) | [HW04](https://github.com/sowens23/CS-F311/tree/main/homework/assignment4) | Midterm I |
  | [Week-8](#Week-8) | | |
  | [Week-9](#Week-9) | [HW04](https://github.com/sowens23/CS-F311/tree/main/homework/assignment4) | |
  | [Week-10](#Week-10) | | |

# Week-10
[Top](#TOP)
## 2023-11-01
  ### To Do:
  - *fibo_bf_elim.cpp*: Comuting Fibonacci numbers, recursion eliminated, brute-force method
  - *rpneval_main.cpp* & *rpneval.hpp*: Reverse Polish Notation evaluation
  ### Review
  - Generic Container problems
    1. Access items [single item: retreive/find, all items: traverse]
    2. Add new item [insert]
    3. Eliminate existing item [delete]
  - 6 Generic Containers in the STL
    - std::deque is basically an array with extra space already allocated in the *beginning* and *end* of the variable to reduce time taken to insert or remove at beginning or end.
  ### Sequences in the C++ STL (Cont)
  - See 2023-11-01 slide 10 for list of efficiency table for vector, basic_string, deque, and list. 
  ### Stacks
  - A **stack** container is an ADT, this works very similar to the *system call stack*.
    - We only ever deal with the top of the stack. You pop, and push to the top of the stack.
    - A stack allows **last-in-first-out (LIFO)** access to data. 
    - This is a *restricted* version of a sequence.
  - **Operations**
    - getTop: Returns value of top item
    - push/pop: Add or remove an item from the top
    - isEmpty: Use this to make sure you are not manipulating something that doesn't exist!
    - size: returns size 
    - create/destroy/copy.
  - std::stack(stack) : std::stack<T, container t>
    - T is the value type
    - container T can be any standard-conforming container with member functions: back, push_bacl, pop_back, empty, and size with comparison operators(==, <=, etc.)
  - **Reverse Polish Notation (RPN)** is a way of writing expressions so that an operator comes after its operands.
    - Normal (**infix**): "1 + 2"
    - RPN (**postfix**): "1 2 +"
    - Translate
      1. (5-2) * 7 = 5 2 - 7 *
      2. 5 - (2*7) = 5 2 7 * -
      3. (5-2) * (7+5) = 5 2 - 7 5 + *
    - To Do "rpneval.hpp"

## 2023-10-30
  ### To Do: 
  - *use_list2.cpp* (based on use_list.cpp, uses llnode2.hpp)
  - *llnode2.hpp* (Header for LLNode2, based on llnode.hpp, no cpp file)
  ### More on Linked Lists
  - When you use a standard linked list, if it's arbitrarily long, it will use *linear recursion depth* to destroy the rest of the list.
    - We can use a smart pointer to eliminate the recursive destructor.
  ### Sequences in the C++ STL
  - There are 6 generic sequence containers
    1. std::vector
      - Smart resizable array
    2. std::basic_string
      - Much like a vector, but for character string operations
      - *string* is *basic_string<char>*; other string-ish types are defined
    3. std::array
      - A-little-bit-smart array. Not resizable, Size is part of the type.
      - Not the same as a c++ built-in array
      - Data items are stored in the object
      - Slightly faster than *vector*
    4. std::forward_list
      - Singly Linked List
    5. std::list
      - Doubly Linked List
    6. std::deque
      - Stands for Double-Ended QUEue; say "deck"
      - Like *vector*, a little slower. Fast insert/remove at both ends

# Week-9
[Top](#TOP)
## 2023-10-27
  ### Node-Based Structures
  - A **node** is usually a small blok of memory that is referenced via a pointer.
  - In 2011 **smart pointer** class templates were added to the C++STL Library, using RAII to handle ownership of dynamic objects automatically
    - **std::unique_ptr<T>(<memory>)**
      - One-owner-at-a-time ownership of dynamic object type **T**
      - The destructor of owner owning *unique_ptr* destroys the object pointed to.
      - Moveable but not copyable. Moving transfers ownership.
    **std::shared_ptr<T>(<memory>)**
      - Allows for shared ownership of a dynmaic object of type **T**
      - Uses a **reference count**. Destroys object when the count hits 0
      - Moveable but not copyable. Moving transfers ownership.
  - When using Smart Pointers, **do not** do the *delete* or the *new*
  - Moral for our class Story: There are two design decisions that affect the efficiency of code:
    1. Deciding how to *process* data (Algorithms)
    2. Deciding how to *store* data (Data Structures)
    - The latter has the greater impact
    - Use arrays when you want a fast look-up
    - Use Linked Lists when we want fast insert & delete (by iterator)
  - 
  ### More on Linked Lists
## 2023-10-25
  ### Review
  - Placing a **noexcept specification** on a function after it's parameter list declares that the function will never throw an exception
    - A destructor is implicitly marked noexcept, unless something evil is going on with your cod
    - The noexcept status of a function call can be tested using **noexcept operator**
      ``` 
      if (noexcept( foo() ) ) {}
      ```
  - A **commit function** is a non-throwing function used to finalize the result of computations, this helps split a throwing operation from a non-throwing operation. 
    - Attempt to construct the altered version of the data.
    - If this fails, then exit, destroying the attempt (generally automatic)
    - If the attempt succeeds, then use a commit function to commit to the new version of the data.
  ### Allocation & Efficiency
  - We're considering how an array reallocate-and-copy might work when it's necessary to resize an array.
    - We would do this when push_back operation has no room to add an addiitonal item to the end of an array.
  - We need to insert-at-end, but we'll need to reallocate-and-copy to increase the size of the array;
    - We could add one additional space for an item, but this would require frequent allocation-and-copy operations
    - We could also just, say, double the size of the array.
    - What time would this take?
      - It would take *amortized constant-time* by observing that the basic operations for this will only ever take 3 times the number of inserts being done (based on size of array) 
  - **amortized constant-time** means that over *k* operations that on average require *O(k)* time. 
  - In the heiarchy of **Using Big-O*, amortized constant-time fits in as follows
    1. (Fastest) O(1) : Constant Time : Look-up by index
    2. O(log n) : Logarithmic Time : Binary Search
    3. O(n) : Linear Time : Lot's of possibilities
    4. O(n log n) : Log-Linear Time : Merge Sort, Introsort, and Heap Sort
    5. **Amortized Constant-Time** : Insert-at-end for a well writen resizable array
    6. O(n^2) : Quadratic Time : Lots.
    7. O(c^n) : Exponential Time
  - For MSArray, this now means that;
    - We need 3 member variables: size, data, and capacity
    - Invariants will now be 
      - 0 <= _size <= capacity
      - data points to an array _capacity of data_type, or a null pointer if capacity is 0
    - Resizing to a smaller array, just changes size, not capacity
    - Resizing to a bigger array, we'll just double the capacity
  ### Generic Containers
  - When we call client-provided functions, the client code generally needs to handle any exceptions.
  - **exception-neutral** code allos exceptions thrown by client-provided code, to propagate unchanged to the caller.
    - When an exception neutral function runs client code that throws, it must do one of two things;
      1. Call the function outside a try block, so that an exceptions terminate our code immediately.
      2. or call the function inside a try block, catch all exceptions, do necessary clean-up, and re-throw
  ### Thoughts on Assignment 5
  ##### The Coding Standards
    - Document everything properly
  ##### Exception Safety
    - All member functions must make at least the Basic Guarantee
    - Constructors make Strong Guarantee
    - Dctor's, move, and swap must make No-Throw
    - Complex modification functins might not offer the Strong Guarantee
    - Check *every* operation that might throw!
    -   For class template, this includes std::copy, std::rotate
  ##### Allocation & Efficiency
    - Are resize, insert, and push_back written to handle operations efficiently
  ##### Generic Containers
    - Are all functions exception-neutral
  - Information relevant to writing swap, copy, move; See slides: Invisible Functions II, Exception Safety: Commit,Functions, Generic Containers: Exception Neutrality, and Allocation & efficiency; generic containers
  - 

## 2023-10-23
  ### Review
  - Three things you can do with exceptions
    1. Catch
    2. Throw
    3. Catch all & re-throw
    * We only write one of these.
  - The following issues are collectively called "safety" in the context of exceptions "exception safety"
    - Does a function signal client code with errors, if it does;
      1. Are resource leaks avoided
      2. Are data left in usable states
      3. Do we know anything about those states
  - 3 types of function guarantees
    1. Basic Guarantee: Minimum standard for all code.
      - Data remain in usable state and resources are not leaked.
    2. Strong Guarantee: Our preferred standard
      - Exceptions make no client-visible changes
    3. No-Throw Guarantee: Required, and also improbable in some cases
      - Function will never throw an exception.
    * Each progressive guarantee, includes previous standard levels.
  - **Single Responsibility Principle (SRP)**: Every software component should have exactly one well defined responsibility
  - To make a Strong Guarantee, we need to make sure that 

  ### Exception Safety
  - When placing a *noexcept* tag after a parameter list, declares a function as with a **noexcept specification**
  - We want **move** functions to be *noexcept*, because if an exception is thrown, mid operation, this can result in actual issues.
  - A **Commit Function** can be used to finalize a throwable computation result to client data using a non-throwing function after the computation has completed.
    - It can be tricky to offer a Strong Guarantee when a single function modifies multple parts of an object.
    - Sometimes we can create an entirely new object with the new value(s), if there is an error, destroy the new object. This way, there are no changes to client visible data. If we are successful, then we commit changes using a non-throwing function.
  - 


# Week-8
[Top](#TOP)
## 2023-10-20
  ### Review
  - For assignment 5, we will need;
    1. Ctors & Dctor: Default ctor, Ctor given size, Copy ctor, Move ctor, Dctor
    2. Member Operations: Copy assignment, Move assignment, Bracket operators
    3. Global Operators: None
    4. Named Global Functions: None
    5. Named Public Member Functions: size, empty, begin, end, resize, insert, erase, push_back, pop_back, swap
  - The value_type will need to be generic, so the user may define the container type
  - We cannot use automatically generated versions of any of the big 5, we are managing owned resources

  ### Exception Safety
  - *new* and built in types, do not throw
  - You need to make sure that you catch your function throws, or your program, will throw.
  - The following issues are called **safety**
    - Does a function signal client code of errors, if it does; 
      - Are resource leaks avoided?
      - Are data left in usable states
      - Do we know anything about the states
  - A functions **guarantee**states the safety assurances it makes
  - In the context of exceptions we use the term **exception safety**
  - **Three Standard Guarantees**
    1. **Basic Guarantee**: Data remains usable, no leaks even with exceptions.
      - If a member function throws, the state of data may be unknown, but it must be a *valid* state, with invariants maintained.
    2. **Strong Guarantee**: If an exception is thrown, it makes no changes visible to client
      - If the function throws an exception then it must be invisible to client. Must maintain a **commit-or-roll bac semantics**. We also would like to log incidents.
      - Sometimes this guarantee is not reasonable due to efficiency issues.
    3. **No-Throw Guarantee**: The function will never throw an exception
      - Also known as the **No-Fail Guarantee**. Highest level of safetly, but not always the best choice.
    - *Notes*: Each guarantee includes the previous guarantees. Basic is minimum standard for all code. Strong is the one we generally prefer. No-Throw is required in some special situations.
  - The **Single Responsibility Principle (SRP)** says every software component should have exactly one well defined responsibility can be helpful here.
  - A *non-const* member function, **should not** return an object by value.
    
## 2023-10-18
  ### Review
  - Our problem for the rest of the semester;
    1. How to *store* items
    2. What *operations* to make with these items
    3. How to make the required *time and space* desirably efficient
    - The general solution to this issue is a **Container**, specifically a **generic container** whose type is client code specified
  - **Abstract data tyoe (ADT)** is a collection of data with a set of operations. Usually independent of implementation and language
  - Remember your many many member functions for a smart array
  ### Basic Array Implementation
  - Let's create a smart array, whose functions are defined in yesterdays notes.
  - We will define public member types to help  
  - Design Decisions
    - Array Type: User defined
    - Array Size: std::size_t
    - Store data: int type values
    - Implement Iterators: with int * and const int *
    - Member Types defined as:
    - Data Members: 
      1. Size of array: size_type _size; 
      2. Pointer to array: value_type * _data;
    - Class Invariants:
      1. _size is non negative
      2. _data points to an int array, allocated with new [], owned by *this, holding _size ints
    - What will [] operator return: const and non-const value_types &
    - What should begin and end return: const, and non const iteratives
    - Can we use automatically generated Big Five: ???

## 2023-10-16
  ### Where are we?
  - Upon completion of this course you will;
    - Have experience writing and documenting high-quality code
    - Understand proper err U
    - Understand proper error handling, enabling software components to support robust, reliable applications.
    - Be able to perform basic analyses of algorithmic efficiency, including use of big-O and related notation.
    - Be familiar with various standard algorithms, including those for searching and sorting.
    - Understand what data abstraction is, and how it relates to software design.
    - Be familiar with standard container data structures, including implementations and relevant trade-offs.
  - Solutions to many problems come in the form of how to store, access, manipulate, and delete data. These operations are done in **containers**
  - We are particularly interested in **generic containers**
  ### Data Abstraction
  - **Data Abstraction**: Applying abstraction to the structure of data.
  - This can be the process of assigning keys for organizational purposes.
  - An **Abstract Data Type (ADT)** is a collection of data, along with a set of operations on that data.
    - They are independent of implementation, and even programming languages.
    - Heavily used in software development, but not often mentioned.
  - A **Data Structure** is a construct within a programming language that stores a collection of data
  - A particular ADT is a **ADT Triple**
    - This holds 3 values with a few operations
    - To ceate a *minimal* interface you must have the first 4 of 7 operations
      1. Create with unspecified values
      2. Destroy
      3. Get a value
      4. Change a value
      5. Create with specified values
      6. Copy (create or assign)
      7. Output (if each item can be output)
  - We like ADT interfaces that are
    - Complete: All required operations are *possible*
    - Minimal: Built without redundant functionality
    - Convenient: The interface is simple to understand, and use (often battles with Minimal)
    - Facilitate Efficiency: Allows data to be dealt with efficiently
    - Generic: Avoid restricting implementations and internal data types (often battles with Facilitate Efficiency)
  ### Intro to Sequences
  - A **Sequence** is a colleciton of items that are in order. (We are concerned with **finite** sequences right now)
  ### Interface for a Smart Array
  - When creating your smart array, consider the necessary operations
    - CreateEmpty (Default Ctor)
    - Create Sized (Ctor given size)
    - Destroy (Dctor)
    - Copy (Copy ctor, copy assignment, move ctor, move assignment)
    - LookUpByIndex (Bracket Operator)
    - Size (Member funciton *size*)
    - Empty (Member function *empty*)
    - Sort (Handle externally with iterators, use member functions *begin* and *end*, *std::sort* or *std::stablesort*)
    - Resize (Member function *resize*) 
    - InsertByPos (Member function *insert*) - RemoveByPos (Member function *erase*)
    - InsertBeg (insert with begin)- RemoveBeg (erase with begin) - InsertEnd (push_back) - RemoveEnd (pop_back) 
    - Splice (A->C, B->A, C->B)
    - Traverse (bracket operator, for loop, index(size) or for each) - Swap (member function swap (A->C, B->A, C->B))
  - Insert
    - Takes iterator and item
    - Inserts just before or after the iterator
    - Return value is an iterator referencing the inserted item
  - Erase
    - Takes iterator
    - removes item
    - return value is iterator to item following one removed, or end iterator if removed item was last
  - swap
    - Takes another sequence by reference
    - exchanges the values of sequence and given one
    - no return value

## **General Comparison Sorts**
- **Bubble Sort**: This simple sorting algorithm iteratively compares pairs of adjacent elements and swaps them if they are in the wrong order. Works for linked lists. O-Linear speed when list is nearly sorted, otherwise quadratic, and super slow. 
  - Space Efficiency: O(1)
  - Sort Stability: Stable
  - Best: Ω(n) Average: θ(n^2) Worst: O(n^2)
- **Selection Sort**: This algorithm divides the input into a sorted and an unsorted region. It repeatedly selects the smallest (or largest) element from the unsorted region and moves it to the sorted region. 
  - Space Efficiency: O(1)
  - Sort Stability: Stable
  - Best: Ω(n²) Average: θ(n²) Worst: O(n²)
- **Insertion Sort**: This algorithm builds a sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages: simple implementation, efficient for (quite) small data sets and adaptive. 
  - Space Efficiency: O(1)
  - Sort Stability: Stable
  - Best: Ω(n) Average: θ(n²) Worst: O(n²)      
- **Merge Sort**: Another divide-and-conquer algorithm that works by dividing the unsorted list into n sublists, each containing one element (a list of one element is considered sorted), and then repeatedly merging sublists to produce new sorted sublists until there is only one sublist remaining. 
  - Space Efficiency: O(1)
  - Sort Stability: Stable
  - Best: Ω(N log N) Average: θ(N log N) Worst: O(N log N)  
- **Heap Sort**: This comparison-based sorting algorithm divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. 
  - Space Efficiency: O(1)
  - Sort Stability: Unstable
  - Best: Ω(N log N) Average: θ(N log N) Worst: O(N log N)         
- **Quick Sort**: This is a divide-and-conquer algorithm that works by selecting a ‘pivot’ element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted. 
  - Space Efficiency: O(log N)
  - Sort Stability: Unstable
  - Best: Ω(N log N) Average: θ(N log N) Worst: O(n²)     
- **Radix Sort**: This non-comparative integer sorting algorithm sorts data with integer keys by grouping keys by individual digits which share the same significant position and value. It starts by sorting numbers digit by digit from least significant to most significant. Works well with large data sets where values have the same number of digits. 
  - Space Efficiency: O(N + k)
  - Sort Stability: Stable
  - Best: Ω(N + k) Average: θ(N + k) Worst: O(N + k)     
- **Count Sort**
  - Space Efficiency: O(1)
  - Sort Stability: 
  - Best: Ω(N log N) Average: θ(N log N) Worst: O(n²)         
- **Bucket Sort**       
  - Space Efficiency: O(N)
  - Sort Stability: 
  - Best: Ω(N + k) Average: θ(N + k) Worst: O(n²)         
- **Intro-spective Sort**: This hybrid sorting algorithm provides both fast average performance and optimal worst-case performance. It begins with quicksort, it switches to heapsort when the recursion depth exceeds a level based on the number of elements being sorted and insertion sort when the partition size is below some threshold. This combines the good parts of all three algorithms.  Works well with large data sets and provides good average-case and worst-case complexity. 
  - Space Efficiency: Best: O(N log N) Average: O(N log N) Worst: O(N log N)
  - Sort Stability: Stable
  - Best: Ω(N log N) Average: θ(N log N) Worst (When switched to HeapSort): O(N log N)  
- **Shell Sort**



# Week-7
[Top](#TOP)
## 2023-10-11
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week7/): 
    - comparison.cpp [C++ source]
      - Passing comparisons to STL sorts
      - Also demonstrates use of lambdas
    - radix_sort.cpp [C++ source]
      - Radix Sort for 9-digit numbers
    - pigeonhole_sort.cpp [C++ source]
      - Pigeonhole Sort for 3-digit numbers

  ### Non-Comparison Sorts
  - Pigeonhole Sort has linear time, because it only touched each item once.  
    - It reviews the key, and puts it into an array of that same key called a bucket. All 2's go in bucket "2"
    - Once all items are put in buckets, you merge the buckets in order, for an organized list.
    - While this is fast, it's not great because it requires nice keys.
  - Radix Sort, pigeonhole sorts based on the value of the key, for strange values, like strings.
    - pigeonhole sort the list using last character of string of key.
    - pigeonhole sort the pigeonhole sorted keys using next-to-last character of string of key
    - then continue to do this, until you've sorted by the first character of each string.
      - Unsorted list: 583 226 508 183 90 223 924 4 426 106 624
      - First PH Sort (single's place): [90] [583 183 223] [924 4 624] [226 426 106] [508]
      - Second PH Sort (ten's place): [4 106 508] [223 924 624 226 426] [583 183] [90]
      - Third PH Sort (hundred's place): [4 90] [106 183] [223 226] [426] [508 583] [624] [924]
      - Now as you see, it's been sorted.
    - We like Radix sort, for a lot of situations. It's a bit slower for mostly sorted data.

  ### Sorting in th C++ STL
  - STL includes seven sorting algorithms, all of which are log-linear time
  - All sorts try to replicate one of **only three** good sorts: Intro Sort, Merge Sort, and Heap Sort.
    - Global function std::sort.
      - takes a range of 2 random-access iterators
      - not stable
      - memory O(log) 
      - Intended algorithm: Intro sort
    - Global function std::stable_sort.
      - takes 2 random access iterators
      - memory: O(n)
      - intended algorithm merge sort
    - Member function sort of std::list<T>.
      - takes a doubly-linked "list" and sorts it.
    - Member function sort of std::forward_list<T>.
      - Sorts a container, takes no arguments, stable
    - Global function std::partial_sort.
      - Takes three iterators, first, middle, last
      - Intended algorithm is a variant of Heap Sort
    - Global function std::partial_sort_copy.
      - Same as above, just creates a copy.
    - Combination of two global functions: std::make_heap & std::sort_heap.
      - Variant of heap sort.
  - Every STL sorting algorithm will take an optional comparison specified using lambda functions
  - A **lambda function** is a function with no name.
    - start iwth a pair of brackets, a normal function parameter, with no return type.
    - takes two ints, and returns their sums.
      ```
      [](int a, int b) { return a+b};
      ```
    - You can store a lambda function in a variable
      ```
      auto add = [](int a, int b) { return a+b};
      cout << add(2,3) << endl;
      ```
    - We can give it a definite type by using #include <functional>; using std::function
      ```
      function<int (int,int)> add = [](int a, int b) { return a+b};
      ```
    - Additionally, you can capture existing variables to execute operations with
    - Give a lambda access to outside variables, as they are at the point 
      ```  
      the lambda is defined, by capturing them.
      auto mult_cp = [k](int n) { return k*n; };
      auto mult_ref = [&k](int n) { return k*n; };
      ```
    - Other fancier capture techniques
      ```
      [a,b,&c,&d](int n){ … // Capture a, b by copy,
      // c, d by reference
      [=](int n){ … // Capture any needed by copy
      [&](int n){ … // Capture any needed by reference
      [=,&c,&d](int n){ … // Capture c, d by reference,
      // any other needed by copy
      [&,a,b](int n){ … // Capture a, b by copy,
      // any other needed by reference
      ```
  - TODO: Comparison.cpp

## 2023-10-09
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week7/): quicksort2.cpp, introsort.cpp 
  ### Review: Multifaceted Review
  - Facts about algorithm speeds
    1. An algorithm that reads all of its input must be Omega(n)
    2. A general-purpose comparison sort must be Omega(nlog n)
  - We can refer to the BAD table to reference the Master Theorem/Big-O speeds of sorts
    | Sort Method | b | a | d |
    | -- | -- | -- | -- |
    | Merge Sort | 2 | 2 | 1 |
    | Binary Search | 2 | 1 | 0 |
  
  ### Comparison Sorts III
  - Better Quicksort
    - Quicksort has an issue of dealing with where to start the pivtot
    - Choose the pivot using **median of 3**
      - Look at the 3 items: first, middle, last
      - Let the pivot be the one that is between the other two.
    - Our *ideal* pivot will be the median of the list.
    - So can we find the median of a list in linear time?
      - Yes! Using the **BFPRT** algorithm (**B**lum-**F**loyd-**P**ratt-**R**ivest-**T**arjan Algorithm)  
  - Introspection is when an algorithm can examine it's own performance
    - See [Introspective Sorting and Selection Algorithms](https://onlinelibrary.wiley.com/doi/pdf/10.1002/%28SICI%291097-024X%28199708%2927%3A8%3C983%3A%3AAID-SPE117%3E3.0.CO%3B2-%23?casa_token=m5iw1z5gcykAAAAA:6CQGikUcYgmAD-aeQdnAWVsjG8IXTTaCujFh2FiL2fpwbI2AFe3AZt5UuXRhCWjzwe-wKXYiyjJ_llE): David R. Musser, CS professor at Polytechnic Institute

# Week-6
[Top](#TOP)
## 2023-10-06
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week6/): quicksort1.cpp, quicksort2.cpp, and stirling.py 
  ### Review: Analysis of Algorithms
  - We really want to avoid using anything with a quadratic or higher power.
  - Constant, linear, and log times are ideal.
  - Bubble and merge sort are In-Place. Meaning they require no large addition in space.
  - Remember the Master Theorem
    - b is the number of nearly equal-sized parts
    - a is the number of recursive calls
    - d is essentially the depth of it's recursive loops
      - where c is a constant. Comparing this with the general form, we have:
      - a=1, b=3, and f(n)=c
      - Therefore, the value of d is:
      -  d=log(_3)​1=0
    - f(n) is the amount of other work done in the body of the algorithm
      - Other work means anthing the algorithm does other than making recursive calls
    - Compare a to b^d
      - Case 1. If a < b^d, then T(n) is O(n^d)
      - Case 2. If a = b^d, then T(n) is O(n^d log n)
      - Case 2. If a > b^d, then T(n) is O(n^k), where k = log_(b)a
  - Merge Sort is practical and often used.
    - This is because it is stable, (log n) space efficient, and (n log n) efficiency

  ### The Limits of Sorting
  - Introduction
    - We know that we have slow sorts (quadratic +) and fast sorts (log/ linear/ constant)
    - This does not change **with general purpose comparison sort**
    - (Big Omega Ω) is lower bound, meaning best case scenario 
    - (Big Theta Θ) is the tight bound, meaning average case scenario
    - (Big O O) is the upper bound, meaning worst case scenario
  - Proof
    - We can prove 

      **Stirling's Approximation** FIX ME

  $$ n! = ((n^n)\over (e^n)) sqrt(2)+ f(n) $$

  ### Comparison Sorts III
  - Quicksort
    - Basically we pick a pivot, which starts as the first item
    - Then it put's all numbers smaller than the pivot on the left, higher on the right
    - Then moves to the next item and does the same thing
    - As the pivot moves up the list, we recursively sort the numbers on the left
    - Invented by **C.A.R ("Tony") Hoare, 1961**
    - If we compare Merge Sort and Quicksort
      - We can see that both use Divide and Conquer strategies.
      - Both have an auxiliary operation (Stable Merge, Partition)
      - Merge sort recurses first, Quicksort recurses last
    - **Hoare's Partition Algorithm**
      - Essentially you pick a pivot somewhere in the middle
      - Iterator left to the first item right of pivot
      - Iterator Right to the last item
      - Move left up, and right down, moving low items left of left, and high right of high
      - Once left and right cross, put pivot right of last left value.
  - Better Quicksort
    - 
  - Introsort
    - 

## 2023-10-04
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week6/): iterative_merge_sort.cpp
  ### Review: Analysis of Algorithms
  - Efficiency in time, space, etc.
  - Top is the most fast (usually) and bottom is the lowest (usually)
    | **Using Big-O** | **In Words** |
    | --- | --- |
    | O(1) | Constant time |
    | O(log n) | Logarithmic time |
    | **Above this line** | **Cannot read all input** |
    | O(n) | Linear time |
    | O(n log n) | Log-linear time |
    | **Below this line** | **Probably not scalable** |
    | O(n2) | Quadratic time |
    | O(cn), for some c > 1 | Exponential time |

  - Nested "real" loops becauses Quadratic, which becomes non-scalable really quick.
  - *Bubble Sort* 
    - Efficiency: O(n^2) for average case
    - Works for linked lists, etc.
    - Space efficienc: In place
    - Stable (Never reverses the relative order of equivalent items)
    - O-Linear speed when list is *nearly* sorted, otherwise quadratic, and super slow.
  - *Insertion Sort*
    - Mostly same as Bubble sort, too slow.
  - Using std::move(utlity) will cast an Rvalue
  ### Asymptotic 
  - Asymptotic notionations will define a few details of an algorithm
    - Omega ( ) says that the worst-case number of basic operations is atleast k*f(n)
    - Theta ( ) says that a function always lies between 

    | 1 | n | nlog(n) | n2 | 5n2 | n^(2)log(n) |  n3|  n4 |
    | --- | --- | --- | --- | --- | --- | --- | --- |
    | O(n2) | yes | yes | yes | yes | yes|  no|  no|  no |
    | Ω(n2) | no | no | no | yes | yes |  yes | yes |  yes |
    | Θ(n2) | no | no | no | yes | yes |  no|  no|  no |

  ### Divide and Conquer
  - An algorithmic strategy is a general method for putting together an algorithm
  - Divide and Conquer is used by a number of fast algorthms to split the input into parts and handle them individually
  - Decrease and Concquer works the same but is applied when recursive calls are necessary. You reduce what needs to be called recursively.

      **The Master Theorem**
  *Where a >= 1, b > 1, and f(n) is Θ(n^d) - "n/b" can be a nearby integer*
  $$ T(n) = a*T(n/d) + f(n) $$
  
  ### Comparison Sorts II
  - Merge Sort [John von Neumann, 1945]
  - **Stable Merge** is when we *do not* reverse the order of equivalent items
  - TODO: merge_sort.cpp
  s the characteristics we are most interested in:
  - Merge Sort is stable and runs Θ(n*log(n))

## 2023-10-02
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week6/): insertion_sort.cpp, bubble_sort.cpp
  ### Review: Analysis of Algorithms
  - Efficient: Using few resources
    - We can measure this by calculating sum of basic operations
  - Our *usual* **model of computation**:
    - Legal operations: No data access except thru provided channels
    - Basic operations (the operations we count)
    - We are given a colleciton. It's size is the numbers of items in it
  - Efficiency expressed using big-O tells us much of what we need to know to determine if an algorithm is scalable.
    - In nested loops, if each is executed n times, i times, where i goes up to n, then the order is O(n^t)

  ### Introduction to Sorting
  - Basics
    - To **sort** a collection of data means to rearrange its items in an order
      - We like to sort collections of data, the part we sort is the **key**
      - **Sort** is an algorithm that does sorting
      - **Comparison sort** gets information about the data items using a *comparison function*
      - **General-purpose comparison sorts** means that we place no restrictions on the size of the list to be sorted
  - Overview of Algorithms
    - We analyze a general-purpose comparison sort using five factors.
      - Time/Efficiency
      - Requirements on data
      - Space Efficiency
      - Stability
        - Never reverses the relative order of equivalent items
        - We want to order the keys, but we want them to stay in order of associated data
        - When we move items up the list, down the list in the process of sorting, we keep the data in the order it was found. So we move our first '5' key back, then the next '5' we find, we move it back, but ordered after the first '5' we found. This is a *stabile* sorting algorithm.
      - Performance on Nearly Sorted Data
        1. All items close to proper spots
        2. Few items out of order
    - Speeds of sorts?
      - Quadtratic-Time [O(n^2)] Comparison Sorts
        - Bubble Sort, Insertion Sort, Quicksort
      - Log-Linear-Time [O(n log n )] Comparison Sorts
        - Merge Sort, Heap Sort, Introsort
      - Special Purpose-Not Comparison Sorts
        - Pigeonhole Sort, Radix Sort

  ### Comparison Sorts I
  - Bubble Sort
    - TODO: Very slow when data set is large and things are out of order
    - Virtually never used in practice.
    - Esentially will read one item and it's neighbor, compare, and swap.
  - Insertion Sort
    - We can flip the process of bubble sort, instead of looking through the positions and determinig what item belonds
    - We look at the item and determine the position.
    - We can do a backward sequential search to find the location to move the item
    - TODO: insertion_sort.cpp
  - Insertion is generally one of the move effective way to organize a small list.
  - Optimized Sort and Quick Sort will utilize Insertion Sort.


# Week-5
[Top](#TOP)
## 2023-09-29
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week5/): hsscount_test.cpp, hsscount.cpp, important.py
  ### Review: Backtracking
  - Searching for a solution can require backtracking
  - All attempts are partial solution
  ### Thoughts on assignment 4
  - Writing It
    - vector<vector<int>> board(dim_x, vector<int>(dim_y,0));
    - board[i][j]
    - See notes in slides
  ### 3 Analysis of Algorithms
  - Efficincy
    - We can measure efficiency of a program that does not depend on system chosen or current state of technology.
    - We simply take a sum of the number of algorithms performed 
  - Big-O Notation
    -   Algorithm A is **order** f(n) [written O(f(n))] if there exists constants k and n_0 such that algorithm A performs no more than k*f(n) basic operations when given input of size n ≥ n_0
    - A competent programmer is expected to understand it
    - You can measure the worst-case and average-case. You can caluclate this yourself
    - An algorithm that works well when used with increasingly large problems & large systems is said to be scalable. Or, it **scales well**
    - Efficiency categories
      - O(1) is **constant time**
      - O(log_(b)n) is **logarithmic time**
      - o(n) is **linear time**
      - O(n log_(b)n) [for some b>1] is **log-linear time**
      - O(n^2) is **quadratic time**
      - O(n^3) is **cubic time**
        - You can see how this works now.
      - O(c^n) is **exponential time**

## 2023-09-27
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week5/): nqueen.cpp, nqueencount.cpp
  - Go collect this new, finished program.
  ### Review: Search Algorithms
    - Binary search using a key with a sorted list
    - Sequential search (linear search) is very slow, list does not need to be sorted
    - Binary seach is significantly fast
    - Sometimes it can be beneficial to eliminate recursion
      - Tail call is the last thing a function does
      - Tail recursion is when that last thing, is referencing itself
      - Eliminating tail recursion is easy and practical
  ### Recursive Backtracking
  - Basics
    - When solving problems, sometimes we may need to backtrack
    - This usually happens when we need to search for a solution
    - Recursive solutions work well 
  - Example
    1. We want to figure out how to get a partial solution
    2. Then figure out how to represent a partial solution
    3. Then output a full solution
    - So essentially, create the **nonrecursive wrapper function** that will create an empty partial solution, then call the workhorse function with this partial solution
    - Then call the **Recursive workhouse function** with the given partial solution then print out ful solutions.ss
  - Counting Solutions is nice to see how effective we are *REMOVE THIS*

## 2023-09-25
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week5): seqsearch_compare.cpp, binsearch2.cpp, binsearch3.cpp, binsearch4.cpp
  ### Review: Recursion vs Iteration
    - Use a tree to calculate calls an algorithm makes
    - A choice in algorithm can make a huge difference in performance
    - A running program uses a call stack, which holds stack frames
      - Each stack frame corresponds to an *invocation* of a function. Which holds automatic variables + the functions return address
      - When the function exits, the stack frame is **popped** off the stack
    - **Recursion Depth** is the greatest number of stack frames on the call stack at *any one time* 

  ### Search Algorithms II
  - **Sequential Search**
    - Sequential Search (also called **Linear Search**) is used to find a key in a list.
      - You literally check the first item in the list, if it matches, return, if it doesn't match, check the next item in the list.
  - **Binary Search** required that a list is sorted, but once that is done;
    - Check the *pivot* of the list (key at half length of list) and cut the list in half depending on which side the search key is on.
    - Binary Searched list should be *random-access*

      | List Size | Binary Search | Sequential Search |
      | --- | --- | --- |
      | | Total Potential Lookups: | Total Potential Lookups: |
      | 1 | 1 | 1 |
      | 2 | 2 | 2 |
      | 4 | 3 | 4 |
      | 100 | 8 | 100 |
      | 10,000 | 15 | 10,000 |
      | 1,000,000 | 21 | 1,000,000 |
      | 10,000,000,000 | 35 | 10,000,000,000 |
      | k | Roughly 2^(k) | k |
  - “Iron Law of Computer Science”. As computational power increases, the efficiency of algorithms becomes even more crucial. This is because as machines become more powerful, they are tasked with solving increasingly complex problems. Efficient algorithms can significantly reduce the time and resources required to solve these problems.
  - TODO: Sequential vs Binary

  ### Elmininating Recursion
  - In General
    - Recursion can sometimes have serious drawbacks. This sometimes we may want to **eliminate recursion**
    - **Fact**: Every recursive function can be re-written as a non-recursive function that uses essentially the same algorithm.
      - This is true because we can simulate the call stack ourselves.
    - Strategies for re-writing recursive functions in iterative form
      1. Declare an appropriate stack.
      2. Replace each automatic variable with it's field in the top Stack item.
      3. Put a loop around the *rest* of the function
      4. Replace each recursive call with;
        - Push an object with parameter values and current execution location.
        - Restart the loop (continue).
        - A label marking the current location.
        - Pop the stack. Make use of the return value (if any)
      5. Replace each *return* with:
        - If the return address is the outside world, then actually return
        - Otherse, set the return value, and skip to the proper label (goto ?)
  - Tail Calls
    - **Tail Call**: Is when calling a function is the last thing a function does.
    - Tail call optimization (TCO) is when a tail call reuses the same stack frame as the function that makes the call
  - Tail Recursion
    - If a tail call is a recursive call, this is **tail recursion**, and is *tail-recursive*
    - Elimination steps:
      1. Surround the function body with a big loop.
      2. Replace the tail-recrusive call with Set parameters to their new values
  - TODO: binsearch3, and binsearch4

  ### Search in the C++ STL
  - Binary Search
    - std::binary_search (<algorithms>) searchs and returns a bool for if found
      - std::lower_bound // Lowest iterator that the search value could be inserted
      - std::upper_bound // Highest iterator that the search value could be inserted
      - std::equal_range // Not sure **LOOKUP**
    - Usage: std::binary_search(behi(v1), end(v1), key);
  - Custom Comparison
    - All STL Binary Search algorithms will take an additional parameter to specify a comparison other than '<'
      ```
      #include <algorithm> // For std::binary_search
      #include <functional> // For std::greater
      vector<int> v2 = …; // Dataset, sorted DESCENDING
      int key = …; // Key to find
      bool found = std::binary_search(begin(v2), end(v2), key,
      std::greater<int>());
      ```
  - Sequential Search
    - std::find(<algorithm>) will search for equality, not equivalence
      - auto iter = std::find(begin(v3), end(v3), key);
      - if (iter == end(v3)) cout << "Not found";
  - Algorithms for Specific Data Structures

# Week-4
[Top](#TOP)
## 2023-09-22
  - [TODO](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week4)
    - fibo_fast.py
    - fibo_formula.cpp
    - fibo_fast.cpp
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
    - To-Do [Iterators.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3)
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
    - To-Do [Iterators.cpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3)

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
      - [timeofday.cpp & timeofday.hpp](https://github.com/sowens23/CS-F311/tree/main/inclasscoding/week3)
  
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
