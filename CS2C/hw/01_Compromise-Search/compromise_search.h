#ifndef INC_01_COMPROMISE_SEARCH_COMPROMISE_SEARCH_H
#define INC_01_COMPROMISE_SEARCH_COMPROMISE_SEARCH_H

#include <iostream>
#include <string>
#include <chrono>
using namespace std;
class SimpleTimer {
    std::chrono::time_point<std::chrono::steady_clock> start_time;
public:
    void start() {
        start_time = std::chrono::steady_clock::now();
    }

    double elapsed_seconds() const {
        std::chrono::duration<double> diff(std::chrono::steady_clock::now() - start_time);
        return diff.count();
    }
};

template<class RandomAccessIt, class T>
RandomAccessIt compromise_search(RandomAccessIt& low, const RandomAccessIt& high, const T& value, const int& small_size) {
    RandomAccessIt end = high;

    for (auto size = end - low; size > small_size; size = end - low) {
        RandomAccessIt middle = low + (end - low) / 2;
        if (*middle == value)
            return middle;
        else if (value < *middle)
            end = middle;
        else
            low = middle + 1;
    }

    auto iterator = std::find(low, end, value);
    if (iterator == end) {
        return high;
    } else {
        return iterator;
    }
}




template<class RandomAccessIt, class T>
RandomAccessIt r_compromise_search(RandomAccessIt low, RandomAccessIt high, const T& value, const int& small_size) {

    auto abs_high = high;

    if (low == high) {
        return high;
    }
    const RandomAccessIt middle = low + (high - low) / 2;

    if (*middle == value)
        return middle;
    else if (value < *middle)
        high = middle;
    else
        low = middle + 1;


    auto word = r_compromise_search(low, high, value, small_size);
    if (word == high) {
        return abs_high;
    } else {
        return word;
    }
}










#endif //INC_01_COMPROMISE_SEARCH_COMPROMISE_SEARCH_H

