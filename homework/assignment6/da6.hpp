/* 

Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: Linked Lists (Assignment 6)
Created: 2023-Nov-06
Updated: 2023-Nov-06
File Name: da6.hpp
Current Version: 1
File Function: 
  Write a template
  referencing Linked List nodes via unique_ptr, creating nodes using make_unique, or functions push_front in llnode2.hpp
  No using new or delete, you may use anything from C++ STL

  Excersice A: Write an efficient reversing function for a linked list.
  Excersice B: Write a class template that uses a linked list to hold an associative data set making use of smart-pointers, while signaling errors using exceptions.
    Store data using key-value pairs, this is called associative dataset
    Call the class "slowMap" as such slowMap<string, int> with only 1 data member = unique_ptr<LLNode2<KVTYPE>>
    KVTYPE is a struct or pair


Version History:
- v1:

*/

// Excercise A
template<typename ValType>
void reverseList(unique_ptr<LLNode2<ValType>> & head){
  // Given a unique pointer, an empty unique pointer if the list is empty, and reverses it and points to the new list by reference
  // Performs no value type operations, all in-place, runs linear time
  // DOES NOTHING
  std::unique_ptr<LLNode2<ValType>> prev = nullptr;
  std::unique_ptr<LLNode2<ValType>> curr = head;
  std::unique_ptr<LLNode2<ValType>> curr = head->next;

  while (curr){
    next = std::move(curr->next); // 
    curr->next_ = std::move(prev);
    prev = std::move(curr);
    curr = std::move(next);
  }

  head = std::move(prev);
}

// Excercise B
template<typename ValTypeb>
class SlowMap {
public:
  /*
  Default ctor. Creates an empty dataset.
  Dctor. As usual. */
  // Default ctor & ctor 
  SlowMap()
  /*
  Function size. No parameters. Returns an integer of an appropriate type giving the number of key-value pairs in the dataset.
  Function empty. No parameters. Returns bool. The return value is true if there are no key-value pairs in the stored dataset, and false otherwise.
  Function present. One parameter: a key. Returns bool. The return value is true if a key equal to that given lies in the stored dataset, and false otherwise.
  Function get. One parameter: a key. Returns const DATA_TYPE & for a const SlowMap and DATA_TYPE & for a non-const SlowMap. If an equal key lies in the stored dataset, then the associated value is returned as indicated. Otherwise, an exception of type std::out_of_range is thrown, with the what member set to some appropriate human-readable string.
  Function set. Two parameters: a key and an associated value. Returns nothing. If an equal key does not lie in the dataset, then the key-value pair is inserted. If an equal key does lie in the dataset, then the existing key-value pair is replaced with that given.
  Function erase. One parameter: a key. Returns nothing. If an equal key lies in the dataset, then that key-value pair is removed. If an equal key does not lie in the dataset, then the function does nothing.
  Function traverse. One parameter: a function or function object (its type can simply be a template parameter). Returns nothing. The passed function is expected to take two parameters, key type and data type, and return nothing. The passed function is called on each key-value pair in the dataset.
  Again, SlowMap must not have any other public member functions. In particular, all of the following must be deleted.
  Copy ctor.
  Move ctor.
  Copy assignment operator.
  Move assignment operator.
  */


private:
  // One and only one data member which is of type unique_ptr<LLNode2<KVTYPE>>, where KVTYPE is a type that can hold a single key-value pair (e.g., an appropriate std::pair or struct)


};