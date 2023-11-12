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
  std::unique_ptr<LLNode2<ValType>> next;

  while (curr){
    next = std::move(curr->next); // 
    curr->next_ = std::move(prev);
    prev = std::move(curr);
    curr = std::move(next);
  }

  head = std::move(prev);
}

// Excercise B
template<typename KeyType, typename DataType>
class SlowMap {
public:
  //Define the key-value pair structure
  struct KVPair {
    KeyType key;
    DataType data;
    KVPair(KeyType k, DataType d) : key(std::move(k)), data(std::move(d)) {}
  };

  // Default Constructor
  SlowMap() : _head(nullptr) {}

  // Size Function
  size_t size() {
    // TODO: Implement this
  }

  // Empty function
  bool empty() {
    // TODO: Implement this
  }

  // Present function
  bool present(const KeyType & key) const {
    // TODO: Implement this
  }

  // Get function
  DataType & get(const KeyType & key) {
    // TODO: Implement this
  }
  const DataType & get(const KeyType & key) const {
    // TODO: Implement this
  }

  void set(const KeyType & key, const DataType & data) {
    // TODO: Implement this
  }

  void erase(const KeyType & key) {
    // TODO: Implement this
  }

  template<typename Func>
  void traverse(Func f) {
    // TODO
  }

private:
  // One and only one data member which is of type unique_ptr<LLNode2<KVTYPE>>, where KVTYPE is a type that can hold a single key-value pair (e.g., an appropriate std::pair or struct)
  struct LLNode {
    KVPair kv;
    std::unique_ptr<LLNode> next;
    LLNode(KeyType k, DataType d, std::unique_ptr<LLNode> n = nullptr)
      : kv(std::move(k), std::move(d)), next(std::move(n)) {}
  };

  std::unique_ptr<LLNode> _head; // Pointer to the head
};