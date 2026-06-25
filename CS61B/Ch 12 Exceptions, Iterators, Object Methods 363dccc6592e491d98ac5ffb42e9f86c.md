# Ch 12. Exceptions, Iterators, Object Methods


## 12.2 Exceptions:

to throw an exception, you can make your own exception by throwing an ****************************actual object,**************************** so you need to instantiate something. If you don’t handle this exception with a ********************************************try catch statement ()********************************************, this will make your program crash/terminate. For example:

`throw new IllegalArguementException("message here")`

With this however, if you have an app and an exception is thrown, you don’t want to your app to crash. You can ************handle************ an exception with a ******************try catch****************** statement (not covered in this chapter.)

## 12.4 Object Methods

all java object **inherit** from the overarching `Object` class. There is a good number of inherited methods but here we focus on only two (`toString`, `equals`)

### `String toString()`

when you call `System.out.print()` on an object, it implicitly calls the objects `toString` and prints the string returned. 

Here is one (bad) implementation of `toString()` for a List:

```java
public String toString() {
    String returnString = "{";
    for (int i = 0; i < size - 1; i += 1) {
        returnString += keys[i];
        returnString += ", ";
    }
		returnString += items[size - 1];
    returnString += "}";
    return returnString;
}
```

Although it seems elegant and simple in that we are “appending” to `returnString` , this is actually not the case. We are creating an entirely new string, making this incredibly inefficient since creating a new string object takes time too. 

To remedy this, Java has a special class called `StringBuilder` , it creates a string that is *mutable* so that we can actually append to it instead of creating a new object each time.

Lets rewrite the above implementation using `StringBuilder`

```java
@Override
public String toString() {
		StringBuilder returnSB = new StringBuilder("{");
		for (int i = 0; i < size - 1; i += 1) {
		    returnSB.append(items[i].toString());
		    returnSB.append(", ");
		}
		returnSB.append(items[size - 1]);
		returnSB.append("}");
		return returnSB.toString();
}
```

## `boolean equals(Object obj)`

`equals()` and `==` have different behaviors in Java. `==` Checks if two objects are actually the same object in memory. Remember, pass-by-value! `==` checks if two boxes hold the same thing. For primitives, this means checking if the values are equal. For objects, this means checking if the address/pointer is equal.

Lets implement `equals` for a `Set` object.

```java
@Override
public boolean equals(Object other) {
		if (other == null) { return false; }
		if (other == this) { return true; }
	
		if (other instanceof ArraySet otherSet) {
				if (otherSet.getClass() != this.getClass()) { return false; }
				for (T item : this) {
						if (!otherSet.contains(item)) {
								return false;
						}
				}
				return true;
		}
		return false;
}

```

***Note:*** the parameter must be of type object otherwise we won't be overriding anything. Moreover this gives us the chance to use `.equals` on iterables of different types, like sets or linked lists. 

the 3rd if statement is added because otherwise if other is not an `instanceOf` `ArraySet` , we should return false immediately. The if statement implicitly does the casting of `other` to the  casting will fail. `getClass` returns the runtime class of an object.