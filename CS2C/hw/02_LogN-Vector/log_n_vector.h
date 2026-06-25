#ifndef INC_2__LOGN_VECTOR_LOG_N_VECTOR_H
#define INC_2__LOGN_VECTOR_LOG_N_VECTOR_H

#include <cmath>
#include <memory>
#include <vector>
#include <string>
using namespace std;


template<typename T>
class LogNVector {
private:
    vector<unique_ptr<T[]> > arrays_;
    int size_, curr_array_capacity, capacity_;
public:
    LogNVector();
    LogNVector(initializer_list<T> ilist);
    LogNVector(const LogNVector& other);


    const T& operator[](int index) const;
    T& operator[](int index);

    int size() const noexcept;
    int capacity() const noexcept;
    int Curr_array_capacity() const noexcept;

    void push_back(const T& value);
};






template<typename T>
LogNVector<T>::LogNVector() : size_(0), curr_array_capacity(0), capacity_(0) { }

template<typename T>
LogNVector<T>::LogNVector(initializer_list<T> ilist) : size_(ilist.size()), capacity_(0){

    //O(n)
    int max_first = log2(ilist.size());
    int i = 0;
    for(; i <= max_first; ++i) {
        int new_array_size = pow(2,i);
        capacity_ += new_array_size;
        arrays_.push_back(make_unique<T[]>(new_array_size));
    }
    curr_array_capacity = capacity_ - size_;
    int index = 0;
    int first;
    int second;
    for (T x : ilist) {
        first = log2(index + 1);
        second = index - pow(2,first) + 1;
        arrays_[first][second] = x;
        ++index;
    }
}



template<typename T>
LogNVector<T>::LogNVector(const LogNVector<T>& other) :size_(other.size_),capacity_(other.capacity_),
                                                 curr_array_capacity(other.curr_array_capacity)  {

    int max_first = log2(capacity_ + 1) - 1;

    //O(logn * n)
    for (int i = 0; i <= max_first; ++i) {
        int new_array_size = pow(2,i);
        this->arrays_.push_back(make_unique<T[]>(new_array_size));
        for (int j = 0; j < new_array_size; j++) {
            this->arrays_[i][j] = other.arrays_[i][j];
        }
    }
}


template<typename T>
int LogNVector<T>::capacity() const noexcept {
    return capacity_;
}
template<typename T>
int LogNVector<T>::Curr_array_capacity() const noexcept{
    return curr_array_capacity;
}
template<typename T>
int LogNVector<T>::size() const noexcept {
    return size_;
}


template<typename T>
T& LogNVector<T>::operator[](int index) {
    int first = log2(index + 1);
    int second = index - pow(2,first) + 1;

    return arrays_[first][second];
}


template<typename T>
const T& LogNVector<T>::operator[](int index) const {
    int first = log2(index + 1);
    int second = index - pow(2,first) + 1;

    return arrays_[first][second];
}


template<typename T>
void LogNVector<T>::push_back(const T& value) {

    if (curr_array_capacity == 0) {
        int new_array_size = capacity_ + 1;
        capacity_ += new_array_size;
        curr_array_capacity = new_array_size;
        arrays_.push_back(make_unique<T[]>(new_array_size));
    }

// O(1)
    ++size_;
    curr_array_capacity--;
    int new_capacity = (capacity_ + 1) / 2;
    int first = log2(size_);
    int second = size_ - new_capacity;
    arrays_[first][second] = value;
}

#endif
