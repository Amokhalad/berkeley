#pragma once

#include <vector>
#include <utility>
using namespace std;

// Does not work.

namespace nonstd {
    template<typename Comparable>
    void partition( vector<Comparable> & a, int low, int high, int & pivotPoint) {
        pivotPoint = low;
        while (low <= high) {
            if (a[low] <= a[pivotPoint])
                ++low;
            else if (a[high] >= a[pivotPoint])
                --high;
            else {
                std::swap(a[high], a[low]);
                ++low;
                --high;
            }
        }
        std::swap(a[high], a[pivotPoint]);
        pivotPoint = high;
    }
    template<typename Comparable>
    void quicksort(vector<Comparable> & a, int  low, int  high) {
        int pivotPoint;
        if (low < high) {
//            partition the array
            partition(a, low, high, pivotPoint);
//            sort the top half
            quicksort(a, low, pivotPoint - 1);
//            sort the bottom half
            quicksort(a, pivotPoint + 1, high);
        }
    }

    template<typename Comparable>
    void sort(vector<Comparable> & a) {
//        Initiate the sort
        quicksort( a, 0, a.size() - 1 );
    }
};