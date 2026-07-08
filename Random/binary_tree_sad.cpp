/*Binary Tree SAD
Difficulty: EASY | Max Score: 25
Given a binary tree print its SAD.

SAD of a binary tree is the sum of AD of every node in the tree.

AD of a node is the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values.



Input:

The first line contains a single integer N denoting the number of values provided.
The next line contains N space-separated strings - the value of the ith node. The values of the nodes are given in level-order traversal. if the ith string is null it means that node does not exist.


Output:

Print a single integer - SAD of the tree.


Constraints:

N lies in the range of [0,104]
value of nodes lie in the range of [-1000, 1000]


Sample input 1:

Input:
3
1 2 3

Output: 1

Explanation:
Tree would look like: 

         1   
        / \
       2   3*/