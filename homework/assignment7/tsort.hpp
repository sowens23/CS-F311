/* 
Name: Spencer Owens
Class: 23F CS-311 Data Structures and Algorithms
Assignment: Treesort (Assignment 7)
Created: 2023-Nov-18
Updated: 2023-Nov-26
File Name: tsort.hpp
Current Version: 1
File Function: 

Version History:
- v1:
- v0.0: Barebones file written by Glenn G. Chappell
*/

#ifndef FILE_TSORT_HPP_INCLUDED
#define FILE_TSORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <memory>
// For std::unique_ptr

// Forward declaration of BSTNode
template<typename Value>
struct BSTNode {
  Value value;
  std::unique_ptr<BSTNode> left;
  std::unique_ptr<BSTNode> right;

  BSTNode(const Value& val) : value(val), left(nullptr), right(nullptr) {}
};

// Insert function for BST
template<typename Value>
void insertInBST(std::unique_ptr<BSTNode<Value>>& node, const Value& val) {
  if (!node) {
    node = std::make_unique<BSTNode<Value>>(val);
    return;
  }
  if (val < node->value) {
    insertInBST(node->left, val);
  } else {
    insertInBST(node->right, val);
  }
}

// In-order traversal function for BST
template<typename Value, typename FDIter>
void inOrderTraversal(const std::unique_ptr<BSTNode<Value>>& node, FDIter& iter) {
  if (!node) return;
  inOrderTraversal(node->left, iter);
  *iter++ = node->value;
  inOrderTraversal(node->right, iter);
}

// treesort
// Sort a given range using Treesort.
// Pre:
//     A valid range must be given.
//     Dereferencable iterators must be given.
//     The range is mutable.
// Exception safety guarantee: Basic Guarantee
//     I think a Basic Guarantee because I don't think the tree can revert back if the sort is interupted.
// treesort function
template <typename FDIter>
void treesort(FDIter first, FDIter last) {
  using Value = typename std::iterator_traits<FDIter>::value_type;

  // Build BST
  std::unique_ptr<BSTNode<Value>> root;
  for (FDIter it = first; it != last; ++it) {
    insertInBST(root, *it);
  }

  // In-order traversal to overwrite the original range
  inOrderTraversal(root, first);
}

#endif //#ifndef FILE_TSORT_HPP_INCLUDED

