# Ch 22. Tree and Graph Traversals

# Tree Traversals

Sometimes you want to iterate over a tree, for example, maybe you want to find the total sum of all the nodes of the tree (assuming they contain numerical values).

### There are other types of traversals:

************************************Level Order:************************************

- visit top-to-bottem, left-to-right. (like reading in english)

**************************Depth First Traversals**************************

- ***3 types:*** preorder, inorder, postorder
- Basic (rough) idea: Traverse “deep nodes” before shallow ones
- Note: Traversing a node is different than “visiting” a node.

**Types of DFT:**

1. Preorder: “Visit” a node, then traverse its children (pre for before traversing, you visit)
2. Inorder Traversal: Traverse left child, visit, then traverse right child (you go inorder of a binary search tree)
3. Postorder Traversal: Traverse left, traverse right, then visit: **ACBEGFD (**post for after traversing left and right you print.) 

![Untitled](images/Ch%2022%20Tree%20and%20Graph%20Traversals%204afc7b9ac4e94a018315ca18a12a96eb/Untitled.png)

```java
postOrder.     (BSTNode x) {
	if (x == null) return;
	postOrder(x.left);
	postOrder(x.right);
	print(x.key);
}
```

# Graphs

### DFS (Preorder)

The idea is exploring a neighbor’s entire subgraph before moving on to the next neighbor

For example, given nodes `s` and `t` in a graph, lets use DFT to find if they are connected.

```java
isConnected(Node s, Node t) {
	mark(s);
	if (s == t) return true;
	for any unmarked neighbor v, of s:
		if (isConnected(v, t)) return true;
	
	return false;
}
```

Note: we mark the visited node because we don’t want to repeat vertices when we go to it’s neighbor. If we don’t mark the node, we will run into an infinite loop, going back and forth between nodes.

### DFS (Post Order)

### BFS Order

************************************act in order of distance from a node.************************************

- BFS stands for “breadth first search”
- analogous to the “level order” in tree traversals. Search is wide, not deep.