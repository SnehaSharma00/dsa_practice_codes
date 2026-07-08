/*Path Sum (Hard Version)
Difficulty: HARD | Max Score: 75
You are given the Root of a Binary tree.

Your task is to return the maximum path sum of any non-empty path.



NOTE: A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root or leaf node.

The path sum of a path is the sum of the node's values in the path.

 

Example 1:

Input: 
      1
     / \
    2   3

Output: 6
Explanation: 2->1->3 path gives sum 6.


Example 2:

Input:
   -10
   /  \
  9   20
     /  \
    15   7

Output: 42
Explanation: 15->20->7 gives sum 42.
 

Constraints:

1 <= Number of Nodes <= 104
-1000 <= Node values <= 1000 will this be soled using inorder traversal */
class Solution {
public:
    int rec(TreeNode* root, int &ans) {
        if(root == NULL) return 0;

        int left = max(0, rec(root->left, ans));
        int right = max(0, rec(root->right, ans));

        ans = max(ans, root->val + left + right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        rec(root, ans);
        return ans;
    }
};