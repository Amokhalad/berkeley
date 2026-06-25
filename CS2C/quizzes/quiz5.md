
# Quiz 5: AVL Trees
## Table of Contents
- [Quiz 5: AVL Trees](#quiz-5-avl-trees)
  - [Table of Contents](#table-of-contents)
  - [1. AVL Tree height](#1-avl-tree-height)
  - [answer](#answer)
- [2. Valid AVL Tree](#2-valid-avl-tree)
    - [answer](#answer-1)
  - [3. AVL Tree Height](#3-avl-tree-height)
    - [answer](#answer-2)
  - [4. O(no)](#4-ono)
    - [answer](#answer-3)
  - [5. Better BST Iterators](#5-better-bst-iterators)
    - [answer](#answer-4)
  - [6. AVL Tree Manual Insert](#6-avl-tree-manual-insert)
    - [answer](#answer-5)

## 1. AVL Tree height
**For each N below, what's the minimum and maximum possible height of an AVL tree with N nodes?**
## answer

| N | min height | max height |
|---|------------|------------|
| 1 | 1 | 1 |
| 7 | 3 | 4 |
|42 | 6 | 7 |		
|123| 7 | 9 |		
|1000| 10 | 14 |		
|987654321|30 | 42 |
||
|n| floor($log_2$(n) + 1) | 

calculator program:
```cpp
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

map<int, int> memo;


long memofib(int n);

long min_num_nodes(int h) {
    if (h < 2) {
        return h;
    }
    return 1 + memofib(h - 1) + memofib(h - 2);
}
long memofib(int n){
    auto search = memo.find(n);
    if (search != memo.end()) {
        return memo[n];
    } else {
        memo[n] = min_num_nodes(n);
        return memo[n];
    }
}

int main() {
//    int num_nodes;
//    cout << "N | max height |" << endl;
//    for (int h = 0; h < 40; ++h) {
//        int n_left = min_num_nodes(h);
//        cout << "[" << n_left << "]" << "\t" << h << endl;
//    }
    cout << "N | min height |" << endl;
    for (int i = 0; i < 987654322; ++i) {
        if (i == 1 || i == 7 || i == 42 || i == 123 || i == 1000 || i == 987654321) {
            cout << i << "\t" << floor(log2(i) + 1) << endl;
        }
    }
    return 0;
}

```
# 2. Valid AVL Tree
Write a function that takes a Node * (see code below) pointing to the root of an AVL Tree as input and returns true if it's a valid AVL Tree and false if it is not.

```cpp
template < typename Key, typename Value>
class Node {
private:
  // ...

public:
  Node *left();
  Node *right();
  const Key& key() const;
  const Value& value() const;
  const int balance_factor() const;
};
```

### answer
```cpp
// Check root, left, and right balance factors
bool is_avl_tree(Node* root) {
    bool balanced = true;
    if (root) {
      if(root->balance_factor <= 1 || root->balance_factor >= 1) {
        if (root->left() != nullptr) {
          balanced = is_avl_tree(root->left());
          if (!balanced) {
            return false;
          }
        } 
        if (root->right() != nullptr) {
          balanced = is_avl_tree(root->right());
          if (!balanced) {
            return false;
          }
        } 
      } else {
        return false;
      }
    } 
    return balanced;
}

// simplier answer
bool is_avl_tree(Node *root) {
  if (root == nullptr) {
    return true;
  }
  if (root->balance_factor <= 1 || root->balance_factor >= 1) {
    return false;
  }
  return is_avl_tree(root->left()) && is_avl_tree(root->right());
}
```

## 3. AVL Tree Height
Write a function that takes a Node *root (see code below) and returns the height of the tree in O(log(n)) time.

```cpp
template <typename Key, typename Value>
class Node {
private:
  // ...

public:
  Node *left();
  Node *right();
  const Key& key() const;
  const Value& value() const;
  const int balance_factor() const;
};
```

### answer
this is wrong for sure
```cpp
int height(Node * root) {
  count = 0;
  if (root != nullptr){
    ++count;
    if (root->balance_factor() == -1) {
      for (Node* cur = root; cur != nullptr; cur = cur->right()) {
        ++count;
      }
    }
    else {
      for (Node* cur = root; cur != nullptr; cur = cur->left()) {
        ++count;
      }
    }
  }
  return count;
}
```
<hr>

## 4. O(no)
What's the big-O of erasing from a balanced binary search tree in terms of N, the number of elements in the tree (assuming that element appears exactly once)?

### answer
O(logn)
<hr>

## 5. Better BST Iterators
The (Unbalanced) Binary Search Tree Iterators from the class lectures could be a little better. What's the big-O of operator!=?
```cpp
class Iterator {
  vector<Node*> stack;
public:
  // constructor
  Iterator() {}
  Iterator(Node* root) {
    for (Node* cur = root; cur != nullptr; cur = cur->left) {
      stack.push_back(cur);
    }
  }
  // compare (!=)
  bool operator!=(const Iterator& rhs) const {
    return stack != rhs.stack;
  }
  // dereference (*)
  pair<Key, Value> operator*() const {
    Node* top = stack.back();
    return pair<Key, Value>(top->key, top->value);
  }
  // increment (++)
  Iterator& operator++() {
    Node* cur = stack.back()->right;
    stack.pop_back();
    for (; cur != nullptr; cur = cur->left) {
      stack.push_back(cur);
    }
    return *this;
  }
};
```

### answer
$$O(n)$$

<hr>

## 6. AVL Tree Manual Insert
What would the AVL Tree below look like after inserting 'm'? What would the new AVL Tree (with 'm' in it) look like after inserting 'n'?

Note: It's not enough to just make a new tree that's balanced. You need to think about exactly how an AVL Tree would rebalance the tree after inserting!
```md
  b
 / \
a   z
   /
  y
```

### answer
```
insert m:      LL rotation   |  insert n:          RL rotation
  b                 b        |     b                   m
 / \               / \       |    / \                 / \
a   z       =>    a   y      |   a   y     =>        b   y
   /                 / \     |      / \             /   / \
  y                 m   z    |     m   z           a   n   z
 /                           |      \
m                            |       n   
```
