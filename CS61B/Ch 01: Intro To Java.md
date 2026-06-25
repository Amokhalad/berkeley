# Lecture 1
_Jan 18, 2023_

Instructors: 
- Josh Hug -- hug@cs.berkeley.edu -- 779 Soda
- Justin Yokota -- jyokota@berkeley.edu -- 329 Soda

# Lecture Notes
1. Unlike python, you can concatenate ints and strings together. But Why? 
2. if functions are defined in the same class of main and are used in main must be defined as ``static``. But why?
3. Running Java code: compile first with `javac` then interpret the .class file with `java`
   1. The .class file has been type checked, and 'simpler' for machine to execute.
4. 


### Questions
1. What does var do in Java.
   1. initialized the type of the variable at run-time. Like `auto` in C++.

# Objects
## Static vs. Non-Static Methods
Instance methods are actions that can be taken only by a specific instance of a class. Static methods are actions 
that are taken by the class itself.


**Static Variables** are properties inherent to the class itself, rather than the instance. Static variables 
should be accessed using the name of the class rather than a specific instance, e.g. you should use `Dog.binomen`, not `d.binomen`.


## Java Lists
There are [multiple types](https://docs.oracle.com/en/java/javase/17/docs/api/java.base/java/util/List.html) of `List` 
objects in Java. To create an `ArrayList` of strings:
```java
import java.util.List;
import java.util.ArrayList;

List<String> lst = new ArrayList<>();
```

## Java Arrays
Java arrays are like Java Lists but more restirected in that:
1. The size of the collection must be declared at the time the array is created
2. Size cannot change
3. No methods.
4. Syntax for accessing elements is similar to Python (e.g. `arr[0]`)

Arrays are more performant than lists (more in 61C):
- Reading and writing from them is faster.
- Use less memory.

## Maps
In programming languages, a map is collection of key-value pairs. Each key is guaranteed to be unique. Also called: Dictionary (in Python).



