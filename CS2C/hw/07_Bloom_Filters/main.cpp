#include <iostream>
#include <fstream>
#include <set>
#include <stdexcept>
#include <string>
#include <bitset>
#include <vector>
#include <utility>
using namespace std;

const int num_bits = 1024;
template <size_t NUM_BITS>
struct BloomFilter {
    vector<bool> bits;
    BloomFilter() : bits(NUM_BITS) {
        for (int i = 0; i < NUM_BITS; ++i) {
            bits[i] = 0;
        }
    }

    BloomFilter(const BloomFilter<NUM_BITS>& rhs) : BloomFilter() {
        for (int i = 0; i < NUM_BITS; ++i) {
            bits[i] = rhs.bits[i];
        }
    }
    void insert(const string& value) {
        size_t h = std::hash<string>{}(value) % bits.size();
        bits[h] = 1;
    }
    bool contains(const string& value) {
        size_t h = std::hash<string>{}(value) % bits.size();
        return bits[h];
    }

    void print() const {
        for (const auto& x : bits) {
            cout << x;
        }
    }
};


void read_lines(istream& is, BloomFilter<num_bits>* filter) {
    for (string line; getline(is, line); ) {
        filter->insert(line);
    }
    if (!is.eof()) {
        throw runtime_error("Error reading from istream.");
    }
}

void read_lines2(istream& is, BloomFilter<num_bits>* filter) {
    
    char ch;
    is.get(ch);
    
    for(int i = 0; is; ++i) {
        filter->bits[i] = (ch == '0' ? 0 : 1);
        is.get(ch);
    }
    if (!is.eof()) {
        throw runtime_error("Error reading from istream.");
    }
}

bool check_if_fruit(const string& word) {
    ifstream fruits("fruits.txt");
    string line;
    while (getline(fruits, line)) {
        if (line == word) {
            return true;
        }
    }
    return false;
}


int main(int argc, const char* argv[]) {
    if (argc > 1) { // if I've been given a filename
        ifstream filter_file(argv[1]);
        BloomFilter<num_bits> filter_lines;
        string line;

        read_lines2(filter_file, &filter_lines);
        for (string line; getline(cin, line); ) {
            if (filter_lines.contains(line)) {
                //cout << line << (check_if_fruit(line) ? " is a fruit" : "") << endl;
                cout << line << endl;
            }
        }
        if (!cin.eof()) {
            throw runtime_error("Error reading from std::cin.");
        }
    } else {
        BloomFilter<num_bits> filter_lines;
        read_lines(cin, &filter_lines);
        filter_lines.print();
    }
}