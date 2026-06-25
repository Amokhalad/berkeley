# Quiz 3: Recurrence Relations, Stacks, 

## Table of Contents
- [Quiz 3: Recurrence Relations, Stacks,](#quiz-3-recurrence-relations-stacks)
  - [Table of Contents](#table-of-contents)
  - [1. String Comparisons Big-O](#1-string-comparisons-big-o)
    - [answer](#answer)
  - [2. Three Way Search Big-O](#2-three-way-search-big-o)
    - [answer:](#answer-1)
  - [3. Concatenation](#3-concatenation)
    - [answer](#answer-2)
  - [4. Recurrence Relation](#4-recurrence-relation)
    - [answer](#answer-3)
  - [General formula](#general-formula)
  - [5. Unit Tests](#5-unit-tests)
    - [answer](#answer-4)
  - [6. Stacks vs Queues](#6-stacks-vs-queues)
    - [answer](#answer-5)
  - [7. for-each loops](#7-for-each-loops)
    - [answer](#answer-6)

## 1. String Comparisons Big-O

What's the big-O of comparing two strings, ```e``` and ```p```? Please write your answer in terms of ```e.size()``` and/or ```p.size()```.

<hr>

```cpp
// Case where .size() is equal
e = "abcd";
p = "abcd";
O(e.size())

//Case where words size is differet
e = "abcd";
p = "ab";
O(std::min(e.size(),p.size())
```
### answer
in total:
the  big O is: `O(std::min(e.size(),p.size())`

<hr>

## 2. Three Way Search Big-O

Use recurrence relations to solve the big-O of three_way_search. Assume comparing T objects to each other is O(1). Show your work.

```cpp
// Return the index in array where value is found.
// If value is not in array, then return -1.
template <typename T>
int three_way_search(const T* array, const T& value, int low, int high) {
  // Base case:
    //O(1)
  if (high <= low)
    return -1;

  // General case:
  int one_3rd = low + (high - low) / 3;
  int two_3rds = low + 2 * (high - low) / 3;
    //O(1 + T/3)
  if (array[one_3rd] > value) {  // if we should recurse on the 1st third
    return three_way_search(array, value, low, one_3rd);
  }
    //O(1)
  else if (array[one_3rd] == value) {  // if value is at the first third
    return one_3rd;
  } 
    //
  else if (array[two_3rds] > value) {  // if we should recurse on 2nd third
    return three_way_search(array, value, one_3rd + 1, two_3rds);
  } 
  else if (array[two_3rds] == value) {  // if value is at the 2nd third
    return two_3rds;
  } 
  else {  // else we should recurse on the last third
    return three_way_search(array, value, two_3rds + 1, high);
  }
}
```
### answer:

$T(0) = 1$\
$T(1) = 1$\
$T(n) = 1 + T(n/3)$

**first iteration**\
$=1 + (1+T(n/9))$\
$=2+T(n/9)$

 second iteration
$=2+(1 + T(n/27))$\
$=3 + T(n/27)$

**third iteration**\
$=3 + (1 + T(n/81))$\
$=4 + T(n/81)$

**general case**\
$=k + T(n/3^k)$

**solving for $n/3^k$**\
$n/3^k = 1$\
$3^k = n$\
$k = log_3n$

**plugging $k = log_3n$ back into general case formula**\
$= log_3n + T(n/3^{log_3n})$\
$= log_3n + T(1)$

$$O(log_3n + T(1)) = O(log n)$$
<hr>

## 3. Concatenation 

let's say I have two int vectors, k and t. What's the best possible big-O of concatenating t to the end of k? For example, if k was {10, 20, 30} and t was {40, 50}, then k would become {10, 20, 30, 40, 50}. What if k and t were singly linked lists of int instead?

### answer
- if k and t were vectors, the big O of concatenating t to k would be **O(t.size())**

- if they were singly-linked lists, it would be an O(1) operation because you can just link ks' last element to t's head and, erase t's head and make k's tail point to t the last element.

<hr>

## 4. Recurrence Relation
Solve the following recurrence relation and show your work:

$T(0) = O(1)$\
$T(1) = O(1)$\
$T(n) = T(n / 2) + T(n / 2)  + O(n) + O(1)$
<hr>

### answer

**rewriting**\
$T(n) = 2T(n / 2) + n + 1$

**1st iteration**\
$= 2(2T(n/4) + n/2 + 1) + n + 1)$\
$= 4T(n/4) + 3n +5$

**2nd iteration**\
$= 4(2T(n/8) + n/4 + 1) + 3n + 5$\
$= 8T(n/8) + 4n + 9$

**3rd iteration**\
$= 8(2T(n/16) + n/8 + 1) + 4n + 9$\
$16T(n/16) +5n + 15$

## General formula
$2^{k + 1}T(n/2^{k + 1}) + (k+2)n + (2^{k + 1} - 1)$

<br>

**solving for $n/2^{k + 1} = 1$**\
$n/2^{k + 1} = 1$\
$2^{k + 1} = n$\
$k+1 = log_2n$\
$k = -1 + log_2n$

<br>

**plugging what we found back into general formula**
$2^{log_2n}T(n/2^{log_2n}) + (1 + log_2n)n + (2^{log_2n} - 1)$\
$nT(n/n) + n + nlog_2n + n - 1$\
$nT(1) + nlog_2n + 2n - 1$\
$nlog_2n + 3n - 1$\

$$O(nlog_2n + 3n - 1) = O(nlogn + n)$$

<hr>

## 5. Unit Tests

What is a unit test?

### answer
a unit test is a piece of code used to test a function or an object. Unit tests can be used to test small parts of an object to make sure it's method work properly before continuing.

<hr>

## 6. Stacks vs Queues

What's the difference between a stack and a queue?

### answer
- a stack is a last in first out data structure. The only element that is visible in a stack is the last inserted element. Some of it's methods are `pop` which pops at the end of the list, and `insert` which inserts at the end of the list.
-  a queue is a first in first out data structure. Some of it's method are `dequeue` which pops at the head of the list `enqueue` which inserts at the end of the list.


## 7. for-each loops

What are the minimum set of methods and overloaded operators MyIterator needs for the following code to work, assuming that Foo has .begin() and .end() methods that return a MyIterator?
```cpp
Foo foo(...);
for (const auto& x : foo) { ... }
```

### answer
```cpp
My iterator needs 4 methods. Copy constructor, equality checker, dereference, incrementor.

it = foo.begin()
it1 != it2
*it
++it
```