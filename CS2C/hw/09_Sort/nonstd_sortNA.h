#pragma once

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

namespace nonstd {
    bool has_left_child(int index, int heap_size) {
        return (2 * index + 1) < heap_size;
    }
    bool has_right_child(int index, int heap_size) {
        return (2 * index + 2) < heap_size;

    }
    bool has_child(int index, int heap_size){
        return (2 * index) < heap_size;
    }
    int left_child_index(int index) {
        return 2 * index + 1;
    }
    int right_child_index(int index) {
        return 2 * index + 2;
    }
    int parent_index(int index) {
        return (index - 1) / 2;
    }
    template<typename Comparable>
    void percolate_up(std::vector<Comparable>& heap) {
        int current = heap.size() - 1;
        int p_i = parent_index(current);

        while ( heap[current] > heap[p_i]) {
            std::swap(heap[current], heap[p_i]);
            current = p_i;
            p_i = parent_index(current);
        }
    }
    template<typename Comparable>
    void heap_insert(std::vector<Comparable>& heap, Comparable value) {
        heap.push_back(value);
        percolate_up(heap);
    }

    template <typename Comparable>
    int largest_child_i(std::vector<Comparable> heap, int index, int boundary) {
        if (has_right_child(index, boundary - index)) {
            int l = left_child_index(index);
            int r = right_child_index(index);
            return heap[l] > heap[r] ? l : r;
        } else {
            return left_child_index(index);
        }
    }

    template <typename Comparable>
    void percolate_down(std::vector<Comparable>& heap, int boundary) {
        int current = 0;
        int lc = largest_child_i(heap, current, boundary);

        while (has_child(current, boundary) && heap[current] < heap[lc] && lc <= boundary) {
            std::swap(heap[current], heap[lc]);
            current = lc;
            lc = largest_child_i(heap, current, boundary);
        }
    }
    template <typename Comparable>
    void sort(std::vector<Comparable>& comparables) {
        // Phase one: build max heap
        // insert from head of comparables to end of heap
        std::vector<Comparable> heap;
        for (int i = 0; i < comparables.size(); ++i) {
            heap_insert(heap, comparables[i]);
        }
        comparables = heap;

        for (int i = 0, l = 2 * i + 1, r = 2 * i + 2; i < comparables.size() && r < comparables.size(); ++i, l = 2 * i + 1, r = 2 * i + 2) {
            if ( (comparables[i] < comparables[l] || comparables[i] < comparables[r])) {
                if (comparables[i] < comparables[l]) {
                    cout << "Left Issue" << endl;
                } else if (comparables[i] < comparables[r]) {
                    cout << "Right issue" << endl;
                }
                cout << "parent:[" << i << "]: " << comparables[i] << endl;
                cout << "left:[" << l << "]: " << comparables[l] << endl;
                cout << "right[" << r << "]: " << comparables[r] << endl;
                cout << endl;
            }
            l = 2 * i + 1;
            r = 2 * i + 2;
        }
//         Phase two: swap, pop, percolate down.
        int boundary = comparables.size() - 1;
        while (boundary != 0) {

            std::swap(comparables[0], comparables[boundary]);
            // percolate down
            percolate_down(comparables, boundary);
            boundary--;
        }
    }
}