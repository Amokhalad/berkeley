#include <iostream>
#include "avl_tree.h"
using namespace std;

int main() {
    AVLTree<int> avl;
    avl[2] = 2;
    avl[1] = 0;
    avl[4] = 0;
    avl[2] = 3;
    avl[3] = 0;
    /*      4
     *    /   \
     *   3     6
     *  / \   / \
     * 1
     *
     */

    avl.print();
}
