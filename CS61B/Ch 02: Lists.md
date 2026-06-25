# Lecture 3: References, Recursion, and Lists
_Jan 23, 2023_

## Declaring a Variable 
When you declare a var of a certain type in Java, Java maps the variable name to their location in
memory where the information is stored in bits. 

## Reference Types
When instantiating an Object: 
- Java first allocates a box of bits for each instance variable of the class and fills them with a default value(e,g, 0, null)
- The constructor then usually fills every such box with some other value.

`new`: you can think of it as a function that takes a parameter (Object), and returns the address of that object which is 64 bits.
- note `new`: does not return the bits of what the object contains, only the address of where the object is stored in memory.


Therefore, when you do Object assignment:
```Java
Obj a;
Obj b;
a = new Obj();
b = a;
```
`a` contains the address of the location of where the new object is, and when we assign `b = a`, the address the object is copied over. This is why they point to the same object

**C++ Note: For function calls, Java is a language that always does pass by value, even for objects. When passing in objects, it's the address that's passed in to a function.**


# Lecture 4: SLLists, Nested Classes, Sentinel Nodes
_Jan 25, 2023_

