# Quiz 4: Binary Search Trees, Sets, and Maps
  
  ## Table of Contents
  - [1a. Binary Search Tree Big-O](#1a-binary-search-tree-big-o)
    - [Answer:](#answer)
  - [1b. Binary Search Tree Big-O](#1b-binary-search-tree-big-o)
    - [Answer:](#answer-1)
  - [2a. Binary Search Tree Height](#2a-binary-search-tree-height)
    - [Answer:](#answer-2)
  - [2b. Binary Search Tree Height](#2b-binary-search-tree-height)
    - [Answer:](#answer-3)
  - [3a. Memoize](#3a-memoize)
    - [Answer:](#answer-4)
  - [3b. Memoize](#3b-memoize)
    - [Answer:](#answer-5)
  - [4. No Capitals](#4-no-capitals)
    - [Answer:](#answer-6)
  - [5. Counting Chars](#5-counting-chars)
    - [Answer:](#answer-7)
  - [6. Subtrees](#6-subtrees)
    - [Answer:](#answer-8)



## 1a. Binary Search Tree Big-O
What's the big-O of inserting an element in an (unbalanced) binary search tree with N nodes?

### Answer:
$$O(n)$$
<hr>

## 1b. Binary Search Tree Big-O
What's the best-case big-O of inserting an element in an (unbalanced) binary search tree with N nodes?
### Answer:
$$
O(log(n))
$$
<hr>

## 2a. Binary Search Tree Height
What's the big-O for the height of an (unbalanced) binary search tree with N nodes?
### Answer:
$$
O(n)
$$
<hr>

## 2b. Binary Search Tree Height
What's the best-case big-O for the height of an (unbalanced) binary search tree with N nodes?


### Answer:
$$
O(log(n))
$$
<hr>

## 3a. Memoize
Memoize this function:
```cpp
#include <cassert>

long fibonacci(int n) {
  assert(n >= 0);
  if (n < 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
```
### Answer:
```cpp
map<int, int> memo;

    long memofib(int n);
    long fibonacci(int n) {
        assert(n >= 0);
        if (n < 2) {
            return n;
        }
        return memofib(n - 1) + memofib(n - 2);
    }

    long memofib(int n){
        auto search = memo.find(n);
        if (search != memo.end()) {
            return memo[n];
        } else {
            memo[n] = fibonacci(n);
            return memo[n];
        }
    }
```
<hr>

## 3b. Memoize
What's the big-O of the function you just memoized?

### Answer:
<hr>

## 4. No Capitals
Write a function that takes a std::set<std::string>* as input and removes all strings that starts with a capital letter, in-place (so the return type is void). For example, "Apple" and "APPLE" should be removed while "aPPLE" and "apple" should remain.

### Answer:
```cpp
void foo(set<string> * set) {
    std::set<string> wordtodelete;
    for (auto x : *set) {
        if (isupper(x[0])) {
            wordtodelete.insert(x);
        }
    }

    for (auto x : wordtodelete) {
        set->erase(x);
    }
}
```
<hr>

## 5. Counting Chars
Write a function that takes an std::ifstream& as input and returns an std::map, mapping from each character in the input to the number of times that character appeared in the input.

### Answer:
```cpp
map<char,int> countingChar (std::ifstream& in) {
    string word;
    string fullWord;
    map<char,int> numChars;

    while(getline(in, word)) {
        fullWord += word;
    }

    for (int i = 0; i < fullWord.length(); ++i) {
        numChars[fullWord[i]]++;
    }
    return numChars;
}
```
<hr>

## 6. Subtrees
How many subtrees are there in a binary search tree with N nodes?

If you're not sure what a subtree is, ask!

### Answer:
$$
N
$$
<hr>

