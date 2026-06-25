#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <ctime>
#include "quick_sort.h"
using namespace std;
using namespace nonstd;
const int NUMS = 100;
const int MIN = 1000;
const int NUM_LOOPS = 10;
/*
 * mergesort:
 * Total copies: 19952
Total comparisons: 7515*/
int main() {
    bool run = true;
    vector<int> test_list;
    srand(time(NULL));

    if (run){
            bool passed = true;
            for (int i = 0; i < NUM_LOOPS; i++) {
                vector<int> letters;
                for (int i = 0; i < NUMS; ++i) {
                    int rand_num = rand() % MIN;
                    letters.push_back(rand_num);
                }
                vector<int> sorted(letters);
                vector<int> notouch(letters);
                nonstd::sort(letters);
                assert(letters.size() == sorted.size());
                std::sort(sorted.begin(), sorted.end());

                int j = letters.size() - 1;
                while (letters[j] == sorted[j] && j > 0) {
                    --j;
                }
                if (j != 0) {
                    passed = false;
                    for (int k = 0; k < notouch.size(); ++k) {
                        cout << notouch[k] << ", ";
                    }
                    cout << endl;
                    cout << "issue at index: " << j << endl;
                    cout << letters[j] << " != " << sorted[j] << endl;
                    return 0;
                }
            }
        }
        if (run) {
            return 0;
        }
        vector<int> letters = {887, 39, };
        vector<int> sorted(letters);

    cout << endl << "Given list" << endl;
    for(const auto ch : letters) {
        cout << ch << " ";
    } cout << endl;
    for(const auto ch : sorted) {
        cout << ch << " ";
    }

    cout << endl << endl <<"Heap Sorted: " << endl;
    nonstd::sort(letters);
    for(const auto ch : letters) {
        cout << ch << " ";
    }
    cout << endl << endl << "Sorted List: " << endl;
    std::sort(sorted.begin(), sorted.end());
    for(const auto w : sorted) {
        cout << w << " ";
    }
    cout << endl << endl;

    int i = letters.size() - 1;
    while (letters[i] == sorted[i] && i > 0) {
        --i;
    }
    if (i != 0) {
        cout << "Issue at Index: " << i << endl;
        cout << letters[i] << " != " << sorted[i] << endl;
    } else {
        cout << "All Good" << endl;
    }

}


//