# Quiz 7: Hash Tables

## 1a. Bad Hash Function
Here's a bad hash function for strings:
```cpp
int myHash(std::string x) {
  return x[0];
}
```
Eww.

What are the problems with myHash?

### Answer:
It does not distribute different string values well because say you want to have a group of people that start with the name m – mikel, moe, micky –, they will all hash to the same value. In addition, it returns an int rather than an unsigned int/long.


## 1b. Bad Hash Function
Write a good version of myHash that addresses all the problems you found.

### Answer:
```cpp
unsigned int myHash(std::string word){
    unsigned int hashVal = 0;
    for (char ch : word) {
        hashVal = 37 * hashVal + ch;
    }
    return hashVal % 6689;
    // 6689 is a prime number.
}
```
<hr>

## 2. Load Factor

What are the trade-offs for having a hash table with a smaller or larger load factor?

### Answer:
a hash table with a small load factor will have faster times inserting because data will be less clumped, but the rehash function will be called more often, and maybe even wasting space with all the empty buckets.

A hash table with a large load factor will have all the opposite effects.
<hr>

## 3. Probing
Why is quadratic probing better than linearly probing one bucket at a time?

### Answer:
with quadratic probing, it reduces the issue of clumping,
were as linear probing, if you try to insert an into the table, and the item hashes to a value that's at the start of a clump of size n, inserting will take O(n).
<hr>

## 4. Bloom Filters
Bloom filters have false positives: When you check if something is in a bloom filter, it might say that some is in the bloom filter when it is not.

If I have a small bloom filter (that only uses 1 hash function) with 16 bits and insert 2 elements (A and B), then I check if C is in the bloom filter, what is the probability that I will get a false positive?

Give the exact answer, not an approximation.
### Answer
False positive rate is 1/16 * 1/16 + 15/16 * 1/8 = 31 / 256 = **0.12109375**
<hr>

## 5. Buckets vs Probing
What are the trade-offs between using a bucket hash table vs a probing hash table?

### answer
a bucket hash big O is dependent on the type of bucket used, for example, finds in a bucket that uses binary search trees is o(logn). Finds in a bucket that uses a vector is O(n). It also requires more memory. The big O of Insertion in a probing hash table is not guaranteed as you might begin inserting at the front of a big clump.
<hr>

## 6. Big-O correct
What is the big-O (worst case) of inserting or searching in a bucket-based hash table with N elements in it?

### answer
O(n)
because if there is a really big clump, of size n, and your value hashes to the start of the clump, it will take O(n).