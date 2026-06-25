
# Requirements
Write a command-line program which takes one command-line argument `(argv[1])` and either builds a filter or uses a filter to filter strings. You may use a Bloom Filter or something more creative.

The first time your program is run, it will output a filter to `cout` which will be copied to a file. The second time your program is run, it will read that filter from a file and use it to filter strings. This is why your filter can have any format you like as long as you can read and write it.

If your program is not passed any arguments:
If your program does not contain `argv[1]`, then read strings from `cin` and output a filter (or another filter of your choosing) to `cout`. The filter must not be more than 1 kilobyte in size.

If your program is passed an argument:
If your program does contain `argv[1]`, then read the filter from that file (it will be the same filter your program output from earlier), read strings from `cin` and output a strings that pass the filter.

## Example:
```shell
$ cat fruits.txt
apple
banana
cherry
$ ./your_program < fruits.txt > filter.bin
$ ./your_program filter.bin < fruits_and_vegetables.txt
apple
banana
cherry
spinach
```

The filter above is not perfect and that's ok. Whatever strings are used to build the filter should always pass the filter. Other strings can pass the filter as well, as long as it's not too many. It is impossible to build a perfect filter but a filter that allows all strings would be useless.

## Example Program:
The example program below is a simple version of a filter... too simple.

It builds the "filter" by just writing all the lines from `cin` to `cout` (filter.bin). This means that when we read the filter later (filter.bin), we know exactly which lines were used to build the filter. It's a perfect filter!

The only problem is that it takes up too much space. Imagine if we wanted to create a filter for spam websites so that your browser could quickly tell if a website you were going to is spam or not. If you used a filter like this, it would be very large because the world is filled with so much spam!

For this assignment, you'll need to come up with a way to store your filter that is guaranteed to never be more than 1 kilobyte! The good news is that your filter does not need to be perfect.

    Example filter program for (Bloom) Filter assignment.
    Note that this filter works but the output filter is too big.
```cpp
#include <iostream>
#include <fstream>
#include <set>
#include <stdexcept>
#include <string>

using namespace std;

void read_lines(istream& is, set<string>* filter) {
    for (string line; getline(is, line); ) {
        filter->insert(line);
    }
    if (!is.eof()) {
        throw runtime_error("Error reading from istream.");
    }
}

int main(int argc, const char *argv[]) {
    if (argc > 1) { // if I've been given a filename
        ifstream filter_file(argv[1]);
        set<string> filter_lines;
        string line;
        // Read in the file to create my filter object
        read_lines(filter_file, &filter_lines);
        // Read lines from std::cin
        //   output the line if it "passes" the filter
        for (string line; getline(cin, line); ) {
            if (filter_lines.find(line) != filter_lines.end()) {
                cout << line << endl;
            }
        }
        if (!cin.eof()) {
            throw runtime_error("Error reading from std::cin.");
        }
    } else { // else I've NOT been given a filename
        // Create an empty filter
        set<string> filter_lines;
        // Read lines from std::cin and add each line to filter
        read_lines(cin, &filter_lines);
        // Output filter to std::cout
        for (const string& filter_line : filter_lines) {
            cout << filter_line << endl;
        }
    }
    return 0;
}
```