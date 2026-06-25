#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/* Heapsort
 * Phase 1, build the heap, inserting at the end, percolating it up.
 * Phase 2: deleteMax, swap max with the last element, percolate the last element down. put it at the end, and increment boundary*/
namespace nonstd {
    int parent(int i) {
        return (i - 1) / 2;
    }

    template <typename Comparable>
    void percUp(std::vector<Comparable>& arr) {
        int i = arr.size() - 1;
        while(arr[i] > arr[parent(i)]) {
            std::swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    int leftC(int i) {
        return (2 * i) + 1;
    }
    int rightC(int i) {
        return (2 * i) + 2;
    }
    template <typename Comparable>
    void percDown(std::vector<Comparable>& arr, int boundary) {

        for(int curr = 0; curr < boundary && leftC(curr) < boundary; ) {
            if (rightC(curr) >= boundary) {
                if (arr[curr] < arr[leftC(curr)]) {
                    std::swap(arr[curr], arr[leftC(curr)]);
                    curr = leftC(curr);
                }
                break;
            } else {
                if (arr[leftC(curr)] < arr[rightC(curr)] ) {
                    if (arr[curr] < arr[rightC(curr)]) {
                        std::swap(arr[curr], arr[rightC(curr)]);
                        curr = rightC(curr);
                    }
                } else {
                    if (arr[curr] < arr[leftC(curr)]) {
                        std::swap(arr[curr], arr[leftC(curr)]);
                        curr = rightC(curr);
                    }
                }
            }
        }
    }

    bool hasC(int i, int boundary) {
        return leftC(i) < boundary;
    }
    template <typename Comparable>
    int lci(std::vector<Comparable> arr, int i, int boundary) {
        if (rightC(i) < boundary) {
            int l = leftC(i);
            int r = rightC(i);
            return arr[l] > arr[r] ? l : r;
        } else {
            return leftC(i);
        }
    }
    template <typename Comparable>
    void perccDown(std::vector<Comparable>& arr, int boundary) {
        int lc = lci(arr, 0, boundary);
        for(int curr = 0; curr < boundary && hasC(curr, boundary) && lc <= boundary && arr[curr] < arr[lc] ; ) {
            std::swap(arr[curr], arr[lc]);
            curr = lc;
            lc = lci(arr, curr, boundary);
        }
    }
    template <typename Comparable>
    void sort(std::vector<Comparable>& comparables) {
        vector<Comparable> heap;
        for (int i = 0; i < comparables.size(); ++i) {
            heap.push_back(comparables[i]);
            percUp(heap);
        }

        for (int boundary = heap.size() - 1; boundary > 0 ; --boundary) {
            std::swap(heap[0], heap[boundary]);
            perccDown(heap, boundary);
        }
        comparables = std::move(heap);
    }
}