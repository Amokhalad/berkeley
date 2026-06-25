# Description
Uh Oh! A biologist implemented an unbalanced binary search tree cs2c::Bag class which behaves similarly to std::multiset but it's full of bugs! 🐝🐝🐝🐛🦟 Eww. Your job is to fix the cs2c::Bag class and to write unit tests.

## Part 1: Fix bag.h
Fix all the bugs you can find in bag.h.

Any members or methods in the private sections can be modified however you like, as long as it is still in the spirit of the assignment. For example, you can use regular pointers instead of std::unique_ptr but don't use an std::multiset as part of your implementation.

All public method signatures should not be modified. You can change what's inside the public methods but not the method signature.

Note that in a more realistic implementation, you might not have getters and setters for the cs2c::Bag<T>::Node's left and right children but I have them in this assignment so it's easier for Grade Oven to test your code.

### bag.h (with bugs)
```cpp
#include <memory>
#include <cassert>

namespace cs2c {

template <typename T>
class Bag {
public:
  class Node {
  private:
    T value_;
    std::unique_ptr<Node> left_, right_;
    Node(const T& value) : value_(value) {}

  public:
    ~Node() {
      left_.release();
      right_.release();
    }
    // left getter
    Node *left() {
      return left_.get();
    }
    
    Node *right() {
      return right_.get();
    }
    // value getter
    const T& value() const {
      return value_;
    }

    friend class Bag<T>;
  };

private:
  std::unique_ptr<Node> root_;
  int size_;

  int count(Node *cur, const T& value) const {
    if (cur == nullptr) {
      return 0;
    } else if (value == cur->value_) {
      return count(cur->left_.get(), value) + count(cur->right_.get(), value);
    } else if (value < cur->value_) {
      return count(cur->left_.get(), value);
    } else {
      return count(cur->right_.get(), value);
    }
  }

  // Remove the node with the greatest value in the left subtree and return a
  // unique_ptr to it.
  static std::unique_ptr<Node> extract_greatest_in_left_subtree(Node *cur) {
    std::unique_ptr<Node> greatest;
    Node *c, *p;  // previous and current pointers
    for (p = cur, c = cur->left_.get();
         c->right_ != nullptr;
         p = c, c = c->right_.get());
    if (p->left_.get() == c) {
      greatest.reset(p->left_.release());
      p->left_.reset(c->left_.release());
    } else {
      greatest.reset(p->right_.release());
      p->right_.reset(c->left_.release());
    }
    return greatest;
  }

  // Remove the node with the smallest value in the right subtree and return a
  // unique_ptr to it.
  static std::unique_ptr<Node> extract_least_in_right_subtree(Node *cur) {
    std::unique_ptr<Node> least;
    Node *c, *p;  // previous and current pointers
    for (p = cur, c = cur->right_.get();
         c->left_ != nullptr;
         p = c, c = c->left_.get());
    if (p->left_.get() == c) {
      least.reset(p->left_.release());
      p->left_.reset(c->right_.release());
    } else {
      least.reset(p->right_.release());
      p->right_.reset(c->right_.release());
    }
    return least;
  }

  int remove(Node *prev, Node *cur, const T& value) {
    if (cur == nullptr) {
      return 0;  // base case
    } else if (value == cur->value_) {
      // We need to remove cur and any children  with the same value...
      int num_removed = (
          remove(cur, cur->left_.get(), value) +
          remove(cur, cur->right_.get(), value));

      // Find a replacement leaf node, unless cur is a leafnode.
      std::unique_ptr<Node> replacement;
      if (cur->left_ == nullptr) {
        replacement = extract_least_in_right_subtree(cur);
      } else if (cur->right_ == nullptr) {
        replacement = extract_greatest_in_left_subtree(cur);
      }

      // If there is a replacement, then move cur's children to the replacement
      if (replacement != nullptr) {
        assert(replacement->left_ == nullptr);
        assert(replacement->right_ == nullptr);
        replacement->left_.reset(cur->left_.release());
        replacement->right_.reset(cur->right_.release());
      }

      // Make cur's parent node (prev) point to the replacement
      if (prev == nullptr) {
        root_.reset(replacement.release());
      } else if (prev->left_.get() == cur) {
        prev->left_.reset(replacement.release());
      } else {  // if (prev->right_.get() == cur)
        prev->right_.reset(replacement.release());
      }
      assert(replacement == nullptr);
      return num_removed;
    } else if (value < cur->value_) {
      return remove(cur, cur->left_.get(), value);
    } else {  // if (value > cur->value_)
      return remove(cur, cur->right_.get(), value);
    }
  }

public:
  Bag() : size_(0) {}

  void insert(const T& value) {
    std::unique_ptr<Node> *cur;
    for (cur = &root_;
         cur->get() != nullptr;
         cur = value < (*cur)->value_ ? &(*cur)->left_ : &(*cur)->right_);
    cur->reset(new Node(value));  // actually insert the value
  }

  int remove(const T& value) {
    return remove(nullptr, root_.get(), value);
  }

  int count(const T& value) {
    return count(root_.get(), value);
  }

  bool contains(const T& value) const {
    return count(value);
  }

  int size() {
    return size_;
  }

  Node *root() {
    return root_.get();
  }
};

} // namespace cs2c
```

## Part 2: bag.h Unit Tests
Your unit tests should be in a single file ending in ".cpp" that includes bag.h (#include "bag.h"). Your main function should return 0 on success and return any value > 0 on if any test failed. Make sure you have one (or more) unit tests per public cs2c::Bag method. You're allowed to write unit tests for private methods too but you do not need to.

Try to make your output easy to read:

- Output a summary of how many tests succeeded and/or did not work.
- When a unit test fails, output the name of the failed unit test. (The "name" can be anything you like.)

You are allowed to talk about and share your unit test code with other students!

You can use `std::multiset` as part of your unit tests. You might also find it useful to test `std::multiset` to make sure all your tests pass correctly and then switch to testing cs2c::Bag.