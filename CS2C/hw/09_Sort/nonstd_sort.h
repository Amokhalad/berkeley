#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Merge Sort Algorithm
namespace nonstd {
    template <typename Comparable>
    void domerge(vector<Comparable> & a, const int & low, const int & mid, const int & high) {
        int topPtr = low; // pointer to the top half of array
        int midPtr = mid + 1; // pointer to the middle; start of bottom half
        int resultPtr = 0; // pointer to merged array
        vector<Comparable> tempArr;
        tempArr.reserve(a.size());
        while (topPtr <= mid && midPtr <= high) {
            if (a[topPtr] < a[midPtr]) {
                tempArr.push_back(std::move(a[topPtr]));
                ++topPtr;
            } else {
                tempArr.push_back(std::move(a[midPtr]));
                ++midPtr;
            }
        }
        /*Copy Remaining Elements
         * at most one of these two loops will execute*/
        while (topPtr <= mid) {
            tempArr.push_back(std::move(a[topPtr]));
            ++topPtr;
        }
        while (midPtr <= high) {
            tempArr.push_back(std::move(a[midPtr]));
            ++midPtr;
        }
//        Now copy back to original array
        topPtr = low;
        resultPtr = 0;
        while (topPtr <= high) {
            a[topPtr] = std::move(tempArr[resultPtr]);
            ++topPtr;
            ++resultPtr;
        }
    }

    template <typename Comparable>
    void mergesort( vector<Comparable> & a, const int & low, const int & high) {
        if (low < high) {
//        Find midpoint.
            int mid = (low + high) / 2;
//        merge left half
            mergesort(a, low, mid);
//        merge right half
            mergesort(a, mid + 1, high);
//        combine both halves.
            domerge(a, low, mid, high);
        }
    }
    template <typename Comparable>
    void sort( vector<Comparable> & a ) {
//        Initiate the merge sort
        mergesort(a, 0, a.size() - 1);
    }
}