# Ch 04. Inheritance, Implements

### Hypernyms, Hyponyms, and Interface Inheritance

**Hypernyms:** “<blank> is what’s called a *hypernym* of …” means hypernym is the **********************superclass********************** of (…)

********************Hyponyms:******************** the (…) above are the *hyponyms* of <blank>, or ******************subclass.******************

As an example from lecture, we created two different data structures `SLList` and `AList`. These are hyponyms of a more general list, we’ll call it `List61B`

using **interfaces**: 

```java
public interface List61B<Item> {
	public void addFirst(Item x);
	public int size();
	...
}
```

************************************interface************************************ defines a type for a general list hypernym. It is essentially a contract that specifies what a list must be able to do, *but it doesn’t provide any implementation for those behaviors.* 

Now to tell Java that `AList` and `SLList` are hyponyms, we use a relationship-defining word: ******************`**implements**`******************

```java
public class AList<Item> implements List61B<Item>{...}
```

`implements List61B<Item>` is essentially a promise. `AList` is saying “I promise I will have and  define all the attributes and behaviors specified in the `List61B` interface”

### Overriding

When fulfilling the promise in the subclass to implement the methods defined in the interface, it’s useful (and actually required in this class) to include `@Override` tag above the method signature. ***********Note if you don’t include this tag, you’re still overriding the method.***********

## Implementation Inheritance

Unlike an interface inheritance which just tells the subclass ***what*** to do, we can do something called implementation inheritance which allows to tell the subclasses *********how******* how to behave,

To do this, we must include `default` keyword in the method signature we define in the super class, where if the subclasses don’t override it, it will default to use its parent method.

Now, when we call an overridden method from an instance of the subclass, Java able know which method to call due to something called **************************************************dynamic method selection.**************************************************

## Dynamic method selection

`List61B<String> lst = new SLList<String>();`

in the above declaration, `lst` is of type `List61B` . This is called the “static type”.

However, object themselves have types as well. The object that `lst` points to is of type `SLList` . (**********Note it’s also a `List61B` because of the “is-a” relationship).* But because the object itself was instantiated using the `SLList` constructor, we call this its “dynamic type.”

We say it’s dynamic type because should `lst` be reassigned to point to an object of another type, say `AList` object, `lst` dynamic type would now be `AList` and not `SLList`! it’s dynamic because it changes based on the type of the object it’s currently referring to.

When Java runs a method that is overridden, it searched for the appropriate method signature in its **dynamic type** and runs it.

However for overloaded methods, Java checks to see which method to call by checking the **********************static type********************** and calls the method with the **parameter of the same type.**

## Questions

- [ ]  What happens when we pass in a superclass to an argument that’s suppose to take a subclass?
- [ ]  What about when we pass in a subclass into an argument that takes in a parent class?
    - This is fine because when you pass in the subclass to a function, it shares an “************is-a************” relationship with it’s parent class, which means that it should be able to fit into the parents box.
- [ ]  What happens when you use `Parent p = new Child();`
- [ ]  What about when you use `Child c = new Parent();`
- [ ]  Or finally? `Child c = new Child();`
- [ ]  Can you use `implements` on a superclass that’s not an interface?