# Ch 21. Heaps and PQs


A data structure that allows you to interact only with the smallest item (or largest) in the collection.

## Heaps

Binary tree that is a **complete** and obeys ************************************min-heap property************************************

- **Min-Heap property**: Every node is less than or equal to both of its children
- **complete**: missing items only a the bottom level (if any), all nodes are as far left as possible.

Examples Trees:

![Untitled](images/Ch%2021%20Heaps%20and%20PQs%20619daa83184e422abfe5e122c7c9f7ba/Untitled.png)

## **Insertion:**

- Temporarily place node in left as possible in the bottom level
- “percolate” up the tree by swapping the node with it’s parent if the min-heap property is violated.
- note this operation is $O(logN)$ because the height of the tree of N items is $**log(N)$,** so in the worst case, the new node is the new minimum, so it percolates up the levels.

## **********************Delete Min:**********************

- Temporarily swap the left most node in the bottom level with the root (min node)
- Then percolate the new root down to the appropriate position by swapping with it’s smallest child until it can’t percolate down anymore.

### Tree Implementation

There is a number of ways to represent Trees, we will use an array based heap because it takes advantage of the completeness property. (and also takes less memory)

********************************************Array Based Implementation:********************************************

![Untitled](images/Ch%2021%20Heaps%20and%20PQs%20619daa83184e422abfe5e122c7c9f7ba/Untitled%201.png)

Note that at index zero, it’s empty because it makes computation of the parent, leftChild, rightChild easier. However, you don’t need to do it this way.