#include <iostream>
#include "bag.h"
#include <set>
#include <ctime>
#include <vector>
#include <utility>


using namespace cs2c;
using namespace std;

// so do the unit tests have to catch all the bugs?
// by the way, why is cout not ouputting the text where it should?
// even in my compiler they are not where they should be

/*
 * size method
 * insert method
 * contains method
 * remove method
 * count method
 * root method
 *      How can I test the root method?
 *      Do I need to test Node left right methods?
 */

pair<bool, int> containsMethod() {
    bool passed = true;
    int numTestPassed = 0;
    Bag<int> bag;
    multiset<int> multiSet;

    // contains on an emtpy list.
    if (bag.contains(10)) {
        passed = false;
        cout << "Contains failed on an empty list" << endl;
    } else {
        numTestPassed++;
    }
    // contains on a list with 1 item
    bag.insert(10);
    if(!bag.contains(10)) {
        passed = false;
        cout << "Contains failed to find a list with 1 item" << endl;

    } else {
        numTestPassed++;
    }

    // contains on a non existing item
    if(bag.contains(20)) {
        passed = false;
        cout << "Contains failed on non existing item" << endl;

    } else {
        numTestPassed++;
    }

    // contains on a duplicate item
    bag.insert(10);
    if(!bag.contains(10)) {
        passed = false;
        cout << "Contains failed on a item with a duplicate" << endl;

    } else {
        numTestPassed++;
    }
    // contains on far right node
    bag.insert(20);
    if(!bag.contains(20)) {
        passed = false;
        cout << "Contains failed far right node" << endl;
    } else {
        numTestPassed++;
    }

    // contains on far left node
    bag.insert(5);
    if(!bag.contains(5)) {
        passed = false;
        cout << "Contains failed on far left node" << endl;

    } else {
        numTestPassed++;
    }

    return make_pair(passed, numTestPassed);
}



pair<bool, int> countMethod() {
    bool passed = true;
    int numTestPassed = 0;
    Bag<int> bag;
    multiset<int> multiSet;
    // Non-existing Item
    int actual_output = bag.count(0);
    int expected_output = multiSet.count(0);
    if (actual_output != expected_output) {
        cout << "count method failed on non existing item: actual output "
             << actual_output << " != expected output " << expected_output << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }

    // existing item
    bag.insert(1);
    multiSet.insert(1);

    actual_output = bag.count(1);
    expected_output = multiSet.count(1);
    if (actual_output != expected_output) {
        cout << "count method failed on existing item: actual output "
             << actual_output << " != expected output " << expected_output << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }

    // duplicate item
    bag.insert(1);
    multiSet.insert(1);

    actual_output = bag.count(1);
    expected_output = multiSet.count(1);
    if (actual_output != expected_output) {
        cout << "count method failed on a duplicate item: actual output "
             << actual_output << " != expected output " << expected_output << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }

    // duplicate item with other items
    Bag<int> new_bag;
    multiset<int> new_set;

    new_bag.insert(0);
    new_bag.insert(6);
    new_bag.insert(6);
    new_bag.insert(6);

    new_set.insert(0);
    new_set.insert(6);
    new_set.insert(6);
    new_set.insert(6);

    actual_output = new_bag.count(6);
    expected_output = new_set.count(6);

    if (actual_output != expected_output) {
        cout << "count method failed on a duplicate item with other items: actual output "
             << actual_output << " != expected output " << expected_output << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }
    return make_pair(passed,numTestPassed);
}





// Check size if inseting a duplicate
pair<bool, int> sizeMethod() {
    bool passed = true;
    int numTestPassed = 0;
    Bag<int> bag;
    multiset<int> multiSet;

    //empty list
    if (bag.size() != 0) {
        cout << "bag.size() failed on an empty list: actual value: "
             << bag.size() << ", expected value: " << 0 << endl;
        passed = false;
    } else {
        numTestPassed++;
    }

    //1 item
    bag.insert(0);

    if (bag.size() != 1) {
        cout << "Test 2 failed: " << bag.size() << " !=" << 1 << endl;
        passed = false;
    } else {
        numTestPassed++;
    }

    bag.remove(0);

    if (bag.size() != 0) {
        cout << "Test 3 failed: " << bag.size() << " !=" << 0 << endl;
        passed = false;
    } else {
        numTestPassed++;
    }

    return make_pair(passed, numTestPassed);
}



pair<bool, int> removeMethod() {
    bool passed = true;
    int numTestPassed = 0;
    Bag<int> bag1;
    multiset<int> multiSet1;

    // Remove on an empty list
    int bagDelete1 = bag1.remove(0);
    int multiDelete1 = multiSet1.count(0);

    if (bagDelete1 != multiDelete1) {
        passed = false;
        cout << "Delete failed on an empty list" << endl;
    } else {
        cout << "Pass1" << endl;
        numTestPassed++;
    }
    // Remove on a list with 1 item
    Bag<int> bag2;
    multiset<int> multiSet2;
    bag2.insert(0);
    multiSet2.insert(0);
    int bagDelete2 = bag2.remove(0);
    int multiDelete2 = multiSet2.count(0);

    if (bagDelete2 != multiDelete2) {
        passed = false;
        cout << "Delete failed a list with 1 item" << endl;
    } else {
        cout << "Pass2" << endl;

        numTestPassed++;
    }

    // Remove on a list with duplicate item
    Bag<int> bag3;
    multiset<int> multiSet3;
    bag3.insert(0);
    bag3.insert(0);
    multiSet3.insert(0);
    multiSet3.insert(0);

    int bagDelete3 = bag3.remove(0);
    int multiDelete3 = multiSet3.count(0);

    if (bagDelete3 != multiDelete3) {
        passed = false;
        cout << "Delete failed on a list with 1 item/duplicate" << endl;
    } else {
        cout << "Pass3" << endl;

        numTestPassed++;
    }
    // Remove right child
    Bag<int> bag4;
    multiset<int> multiSet4;
    bag4.insert(0);
    bag4.insert(1);
    multiSet4.insert(0);
    multiSet4.insert(1);

    int bagDelete4 = bag4.remove(1);
    int multiDelete4 = multiSet4.count(1);

    if (bagDelete4 != multiDelete4) {
        passed = false;
        cout << "Delete failed to remove a list with 1 right child" << endl;
    } else {
        cout << "Pass4" << endl;

        numTestPassed++;
    }
    // remove left child
    Bag<int> bag5;
    multiset<int> multiSet5;
    bag5.insert(4);
    bag5.insert(0);
    multiSet5.insert(4);
    multiSet5.insert(0);
    int bagDelete5 = bag5.remove(0);
    int multiDelete5 = multiSet5.count(0);
    if (bagDelete5 != multiDelete5) {
        passed = false;
        cout << "Delete failed to remove a list with 1 right child" << endl;
    } else {
        cout << "Pass5" << endl;

        numTestPassed++;
    }

    // remove node with two children
    Bag<int> bag6;
    multiset<int> multiSet6;
    bag6.insert(6);
    bag6.insert(3);
    bag6.insert(2);
    bag6.insert(5);

    multiSet6.insert(6);
    multiSet6.insert(3);
    multiSet6.insert(2);
    multiSet6.insert(5);

    int bagDelete6 = bag6.remove(3);
    int multiDelete6 = multiSet6.count(3);

    if (bagDelete6 != multiDelete6) {
        passed = false;
        cout << "Delete failed to remove a list with 1 right child" << endl;
    } else {
        cout << "Pass6" << endl;
        cout << bag6.root()->value() << endl;
        cout << bag6.root()->left()->value() << endl;
        cout << bag6.root()->left()->right()->value() << endl;

        numTestPassed++;
    }

    // remove node with duplicate and two children
    Bag<int> bag7;
    multiset<int> multiSet7;
    bag7.insert(6);
    bag7.insert(3);
    bag7.insert(2);
    bag7.insert(3);
    bag7.insert(5);

    multiSet7.insert(6);
    multiSet7.insert(3);
    multiSet7.insert(2);
    multiSet7.insert(3);
    multiSet7.insert(5);

    int bagDelete7 = bag7.remove(3);
    int multiDelete7 = multiSet7.count(3);
    cout << "root: " << bag7.root()->value() << endl;
    cout << "Child of root: " << bag7.root()->left()->value() << endl;
    cout << "right child of root left child: " << bag7.root()->left()->right()->value() << endl;
    cout << "left child of root left child: " << bag7.root()->left()->left() << endl;

    if (bagDelete7 != multiDelete7) {
        passed = false;
        cout << "Delete failed to remove a list with 1 right child" << endl;
    } else {
        cout << "Pass7" << endl;

        numTestPassed++;
    }
    return make_pair(passed, numTestPassed);
}


pair<bool, int> insertMethod() {
    bool passed = true;
    int numTestPassed = 0;
    Bag<int> bag;
    multiset<int> multiSet;

    bag.insert(0);
    if (bag.size() != 1) {
        cout << "Test 1: insert failed to insert on empty list: actual value: " << bag.size() << ", expected value: " << 1 << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }

    // Duplicate Test
    bag.insert(0);
    if (bag.size() != 2) {
        cout << "Test 3: insert failed on a duplicate item: actual value: " << bag.size() << ", expected value: " << 2 << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }

    // Regulat Test
    bag.insert(1);
    if (bag.size() != 3) {
        cout << "Test 3: insert failed: actual value: " << bag.size() << ", expected value: " << 2 << endl;
        passed = false;
    } else {
        ++numTestPassed;
    }

    return make_pair(passed, numTestPassed);
}






int main () {
    cout << "Testing Size Method" << endl;
    pair<bool,int> sizeTest = sizeMethod();
    if (!sizeTest.first) cout << "Failed" << endl;

    cout << "Numbers of tests passed: " << sizeTest.second << " out of 3" << endl << endl;

    cout << "Testing Insert Method" << endl;
    pair<bool,int> insertTest = insertMethod();
    if (!insertTest.first) cout << "Failed" << endl;

    cout << "Numbers of tests passed: " << insertTest.second << " out of 3" << endl << endl;

    cout << "Testing Remove Method" << endl;
    pair<bool,int> removeTest = removeMethod();
    if (!removeTest.first) cout << "Failed" << endl;

    cout << "Numbers of tests passed: " << removeTest.second << " out of 8" << endl << endl;

    cout << "Testing Count Method" << endl;
    pair<bool,int> countTest = countMethod();
    if (!countTest.first) cout << "Failed" << endl;
    cout << "Numbers of tests passed: " << countTest.second << " out of 4" << endl << endl;

    cout << "Testing Contains Method" << endl;
    pair<bool,int> containsTest = containsMethod();
    if (!containsTest.first) cout << "Failed" << endl;
    cout << "Numbers of tests passed: " << containsTest.second << " out of 6" << endl << endl;

    Bag<int> ms;
    ms.insert(614);
    ms.insert(614);
    ms.insert(626);
    ms.insert(609);
    ms.remove(614);


    cout << ms.remove(609) << endl;
    if (countTest.first && removeTest.first && insertTest.first && sizeTest.first && containsTest.first) {
        return 0;
    } else {
        return 1;
    }
}
