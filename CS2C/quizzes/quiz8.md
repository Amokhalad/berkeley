# Quiz 8: Priority Queues and Heap Sort

## 1. Compact Representation
The compact binary tree representation used for (min and max) heaps uses less memory and is faster than node classes with left and right pointers. Why don't we use the compact binary tree representation for all binary trees?

### answer
using a compact binary tree representation is only a good idea for balances binary trees, like AVL trees or heaps. Otherwise, there can be a lot of memory wasted. For example, if we were to represent a left skewed tree as a array, all right child's of each node will be represented as an empty space in the array. In addition, all the empty nodes will have at least 2 other empty node children. The children can have empty nodes as well and so on..

<nr>

## 2. N-ary Compact Representation Child

The compact binary representation allows you to calculate the index of a "left" child (the 0th child) and "right" child (the 1st child). What if we used the same compact representation for an N-ary tree? Note: In a binary tree, N = 2.

How would we calculate the `j`th child (where `0 <= j && j < N`) in an N-ary tree, given an index i?

### answer
$i*N + j + 1$
<hr>

## 3. N-ary Compact Representation Parent
The compact binary representation allows you to calculate the index of the parent. What if we used the same compact representation for an N-ary tree? Note: In a binary tree, N = 2.

How would we calculate the index of the parent, given an index `i`?
### answer
$\lfloor\dfrac{i - 1}{N}\rfloor$
<hr>

## 4. Min vs Max Heap
What's the difference between a min heap and a max heap?

### answer
in a max heap, the thing of highest priority, or the key that's greater than all the other keys is placed at the root. In a min heap, the key that's the smallest key is placed at the root.
<hr>

## 5. std::priority_queue
Complete the function below:
```cpp
#include <queue>
#include <vector>

// Given a vector of elements in any order, return the 5th smallest element
// For example:
//   std::vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
//   assert(fifth_smallest_element(chars) == 'e');
template <typename T>
const T& fifth_smallest_element(const std::vector<T>& elements) {
  // Fill in this part of the function, using an std::priority_queue
}
```
### answer
```cpp
template <typename T>
const T& fifth_smallest_element(const std::vector<T>& elements) {
    std::priority_queue<T> q;
    for (auto el : elements) {
        q.push(el);
    }
    int range = q.size() - 5;
    for (int i = 0; i < range; i++) {
        q.pop();
    }
    return q.top();
}
```
<hr>

## 6. Heap Sort Space Big-O
Heap sort takes an array (or vector or other similar container) and sorts it in place. What's the big-O of the amount of memory it uses (not including the memory of the input/array/vector/etcetera itself)?

### answer
O(1)
<hr>

## 7. Big-O
What operations do all max heaps support? What's the big-O of each operation?

### answer
- push()
  - O(logn)
    - O(1) for inserting at the end
    - O(logn) for percolating up
- pop()
  - O(logn)
    - O(1) for swapping top and back element
    - O(logn) for percolating new top element down.
- top()
  - O(1)








