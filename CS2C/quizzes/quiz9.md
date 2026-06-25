# Quiz 9: Sort
## 1. Big-O
Fill in the **worst-case** big-O's in the table below, for sorting a collection of N elements.
* Assuming Radix Sort is being used to sort N `uint64_t`'s.
  
### answer
|Algorithm|	Worst-case O(...)|
|---------|---------|
|Insertion Sort|$N^2$|
|Heap Sort| $NlogN$|
|Merge Sort|$NlogN$|
|Quick Sort|$N^2$|
|Radix Sort*|$N$|	

<hr>

## 2. Average Big-O
Fill in the **Average-case** big-O's in the table below, for sorting a collection of N elements.
* Assuming Radix Sort is being used to sort N `uint64_t`'s.
### answer
|Algorithm|	Average-case O(...)|
|---------|---------|
|Insertion Sort|N^2|
|Heap Sort| $NlogN$|
|Merge Sort|$NlogN$|
|Quick Sort|$NlogN$|
|Radix Sort*|$N$|	

<hr>

## 3. No Redundant Sorting
Write a (comparison based) sort function that has a best-case big-O of O(N). You may use std::sort as part of your implementation.

### answer

```cpp
template<typename T>
void best_sort(auto begin, auto end) {
  bool is_sorted = true;
  for ( ; begin != end - 1; ++begin) {
    if (*begin > *(begin + 1)) {
        is_sorted = false;
    }
  }

  if (is_sorted) {
    return;
  } else {
    std::sort(begin, end);
  }
}
```
<hr>

## 4. Fastest Possible Search
If you have a vector of N sorted elements, linear search can find an element in O(N) time and binary search can find an element in O(log(N)) time. If the only operation you can use is comparisons that return true or false, what's the minimum number of comparisons you need in the worst case? Why?

### answer

In the worst case, the minium number of comparisons is $log_2N$. In the worst case, the element you want to find is at the end or start of the list or not in the list. In the case where it's not in the list, you will continuously split the list in half until there is 1 element left, this happens $log_2N$ steps.
<hr>

## 5a. Mystery Code
```cpp
#include <iostream>
#include <random>
#include <string>
#include <utility>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::string;
using std::swap;
using std::uniform_int_distribution;

default_random_engine DRE;

// Given two random access iterators, the partition function
//   - picks a random element
//   - partitions the range so that everything to the left of the pivot is less
//     than the pivot and everything to the right is greater than or equal to
//     the pivot
//   - returns an iterator to the pivot
template <typename RandomAccessIt>
RandomAccessIt partition(RandomAccessIt begin, RandomAccessIt end) {
  // Base case: end - begin <= 1
  if (end - begin <= 1) {
    return begin;
  }
  // Randomly pick a pivot
  uniform_int_distribution<int> uniform_dist(0, end - begin - 1);
  int pivot_index = uniform_dist(DRE);
  // Swap the pivot so it's at end - 1.
  RandomAccessIt pivot = end - 1;
  swap(*(begin + pivot_index), *pivot);
  // Partition using the pivot
  RandomAccessIt left = begin, right = pivot - 1;
  while (left <= right) {
    if (*left < *pivot) {
      ++left;
    } else {
      swap(*left, *right);
      --right;
    }
  }
  // Put the pivot in the middle and return an iterator to where the pivot is
  swap(*left, *pivot);
  return left;
}

template <typename RandomAccessIt>
RandomAccessIt foo(RandomAccessIt begin, RandomAccessIt end, int i) {
  if (end - begin <= 0) {
    return end;
  }
  RandomAccessIt pivot = partition(begin, end);
  int pivot_index = pivot - begin;
  if (pivot_index < i) {
    return foo(pivot + 1, end, i - pivot_index - 1);
  } else if (pivot_index > i) {
    return foo(begin, pivot, i);
  } else { // if (pivot_index == i)
    return pivot;
  }
}

int main() {
  string letters = "qwertyuiopasdfghjklzxcvbnm";
  cout << letters << endl;
  for (int i = 0; i < letters.size(); ++i) {
    cout << i << ' ' << *foo(letters.begin(), letters.end(), i) << endl;
  }
    return 0;
}
```
What does the foo function return? (Write a short answer: 20 words or less. I'm looking for a summary, not an explanation of how it works. Don't just say "A RandomAccessIt" or "A random-access iterator".)

For example, if I asked you what does std::min return, a good answer might be "std::min returns whichever of it's inputs is smallest."

### answer
Given in index, i, foo will return that at that a letter at that index if the list given was sorted.
<hr>

## 5b. Mystery Code (part 2)
Let N = `end - begin`. What's the average-case big-O of the `foo` function in the last question? What's the worst-case big-O?

### answer
**Average Case:**
$$
T(0) = 1\\
T(1) = 1\\
T(n) = n + T(n/2)\\
 = n + n/2 + T(n/4)\\
 = O(n)
$$
**Worst-Case:**
$$
T(0) = 1\\
T(1) = 1\\
T(n) = n + T(n-1)\\
 = n + (n-1) + T(n-2)\\
 = n + (n-1) + (n-2) + T(n-3)\\
 = n + (n-1) + (n-2) + (n-3) + T(n-4)\\
 = \sum_{j=1}^nj = (\frac{n^2+n}{2})\\
O(n^2)\\
$$
## 6. Interview Question
What's a data structures and algorithms interview question that you'd like to learn the answer to? (If you're copying the question from a website, please include a link.)