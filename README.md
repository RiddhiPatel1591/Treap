# Treap

<h2>Problem Statement</h2>
The binary search tree that results from using TREE-INSERT to insert a set of n items could end up being dreadfully out of balance. However, as we observed that 
randomly constructed binary search trees will be balanced. Therefore, we could randomly permute the items and then put them 
in that order into the tree if we wanted to create an expected balanced tree for a fixed set of elements. 
What if we don't have everything available at once? Can we still randomly construct a binary search tree from the items if we receive them one at a time? 
We'll look at a data structure that provides a resounding yes to this query. A treap is a binary search tree with an altered method 
of node ordering. A treap is a combination of a binary search tree (BST) and a heap. Treap Contains two values a KEY and a PRIORITY. 
Key follows BST ordering (left is smaller and right is bigger). Priority randomly assigns value that follows Max-Heap property.


<h2>Algorithm:</h2>
<h4>BST</h4>Divides all its sub-trees into two segments; the left sub-tree and the right sub-tree. Every node’s value is strictly higher than 
the value of its left child and strictly lower than the value of its right child. The following characteristics of a binary search tree, 
a node-based binary tree data structure, are present:
• Only nodes with keys lower than the node's key are found in the left subtree of a node.
• A node's right subtree only has nodes with keys higher than the node itself.
• Additionally, the left and right subtrees must also be binary search trees.
There cannot be any redundant nodes.

<h4>Heap</h4>Is a Complete Binary Tree which means that tree must be filled from left to right. Treap uses 
rotations to maintain Max-Heap property during insertion and deletion.

<h4>Rotation</h4>

Like other self-balancing Binary Search Trees, Treap uses rotations to maintain Max-Heap property during insertion and deletion.
