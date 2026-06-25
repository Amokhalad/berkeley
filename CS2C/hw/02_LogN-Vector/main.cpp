#include <iostream>
#include "SimpleTimer.h"
#include "log_n_vector.h"
#include <vector>
#include <list>
#include <algorithm>
#include <map>
using std::cout;
using std::endl;

const int num_of_loops = 100000;

int main()
{
    SimpleTimer T_logN;
    SimpleTimer T_vector;
    SimpleTimer T_list;

    LogNVector<int> C_logN;
    vector<int> C_vector;
    list<int> C_list;

    map<int, double> LogNTime;
    T_logN.start();
    for (int i = 0; i < num_of_loops; ++i)
    {
        if (i % 100 == 0) {
            LogNTime[i] = T_logN.elapsed_seconds();
            T_logN.start();
        }
        C_logN.push_back(i);
    }

    map<int, double> VectorTime;
    T_vector.start();
    for (int i = 0; i < num_of_loops; ++i)
    {
        if (i % 100 == 0) {
            VectorTime[i] = T_vector.elapsed_seconds();
            T_vector.start();
        }
        C_vector.push_back(i);
    }

    map<int, double> ListTime;
    T_list.start();
    for (int i = 0; i < num_of_loops; ++i)
    {
        if (i % 100 == 0) {
            ListTime[i] = T_list.elapsed_seconds();
            T_list.start();
        }
        C_list.push_back(i);
    }

    SimpleTimer T_nothing;
    map<int, double> nothing;
    T_nothing.start();
    for (int i = 0; i < num_of_loops; ++i)
    {
        if (i % 100 == 0) {
            nothing[i] = T_nothing.elapsed_seconds();
            T_nothing.start();
        }
    }

    cout << "n,logN push_back,std::vector push_back,std::list insert,nothing" << endl;
    for (int i = 0; i < num_of_loops; i+=100)
    {
            cout << i << "," << LogNTime[i] << "," << VectorTime[i] << "," << ListTime[i] << "," << nothing[i] << endl;
    }
}
