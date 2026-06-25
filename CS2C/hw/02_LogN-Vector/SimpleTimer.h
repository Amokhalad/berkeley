#include <iostream>
#include <chrono>
using namespace std;
#ifndef INC_02_LOGN_VECTOR_SIMPLETIMER_H
#define INC_02_LOGN_VECTOR_SIMPLETIMER_H

class SimpleTimer {
    std::chrono::time_point<std::chrono::steady_clock> start_time;

public:
    void start() {
        start_time = std::chrono::steady_clock::now();
    }

    // Return the number of seconds since .start() was called
    double elapsed_seconds() const {
        std::chrono::duration<double> diff(std::chrono::steady_clock::now() - start_time);
        return diff.count();
    }
};

#endif //INC_02_LOGN_VECTOR_SIMPLETIMER_H
