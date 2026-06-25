# Homework 09. Sort
## Requirements
Write a `sort` function, in a file named nonstd_sort.h, which takes an `std::vector<T>` reference and sorts the elements inside using the comparison operators. You must implement your sorting algorithm from scratch and it must be O(n * log(n)) on average.

You may not use `std::sort` or anything else that goes against the spirit of the assignment. You may not maintain any state between calls to `nonstd::sort` or rely on any global state that would hint to the category of input. (For example: You may not keep track of which categories you've seen but you may use pseudo random number generators like `rand(), even though `rand()` relies on global state.)
```cpp
#pragma once

#include <algorithm>
#include <vector>

namespace nonstd {

template <typename Comparable>
void sort(std::vector<Comparable>& comparables) {
// TODO: Replace std::sort with my own algorithm...
std::sort(comparables.begin(), comparables.end());
}

} // namespace nonstd
```

You may assume that `T` is comparable (overloads the comparison operators), assignable `(T a(...); a = b;` is valid), and copy/move constructable (`T a(...); T b(a);` is valid). However, you can't assume there's a default constructor (`T a; and T a() are not valid`) or other public methods. These are similar requirements to the real `std::sort`.

## Grading
Your sorting algorithm will be run with different "categories" of input:

- All unique elements
- Not unique elements
- Mostly sorted elements
- Randomly shuffled elements
- Reverse-ordered elements

The algorithm that consistently uses fewer comparisons and move/copy operations in each category will earn 10% extra credit. The next top algorithm will earn 5% credit. If you algorithm is the top in multiple categories, you'll only get the extra credit once.

## Submission
Submit your code on gradeoven.com.