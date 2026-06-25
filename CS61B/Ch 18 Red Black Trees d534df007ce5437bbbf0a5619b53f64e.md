# Ch 18. Red Black Trees

## Rotations:

rotateLeft(N) brings down the Node, making the right child it’s parent, and the right child left node it’s child.

rotateRight(N) does the inverse of rortateLeft.

## A One-To-One Mapping with 2-3 Trees

- When inserting: Use a red link
- If there is a right leaning “3-node”, we have a ************Left Leaning Violation************
    - ************************rotate left the appropriate node to fix.************************
- if There are two consecutive left links, we have an incorrect 4 node violation.
    - rotate right the appropriate node to fix.
- If there are any nodes with two red children, we have a temporary 4 node.
    - color flip the node to emulate the splitting operation in 2-3 trees.

One last detail: Cascading operations.

- It’s possible that a rotation or flip operation will cause an additional violation that needs fixing.

##