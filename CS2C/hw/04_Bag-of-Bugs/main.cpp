#include <iostream>
#include "bag.h"
using namespace cs2c;
using namespace std;

int main() {
    Bag<int> bag;
    bag.insert(1);
    cout << bag.root() << endl;
}
