/*Path Sum (Easy Version)
Difficulty: EASY | Max Score: 25
You are given the root of Binary tree and an integer target.

Your task is to return true if the tree has a root-to-leaf path such that adding up all the values along the path equals target.



NOTE: A leaf is a node with no children.



 

Example 1:

Input: target = 14
         5
        / \
      -2   9
     /  \   \
    1   2    4
Output: false
Explanation: There is not such path existing in this given tree with sum = 14.


Example 2:

Input: target = 14
         5
        / \
      -2   9
     /  \   \
    11  2    4
Output: true
Explanation: The path with node values - {5,-2,11} is having sum = 14.
 

Constraints:

0 <= Number of Nodes in the tree <=104
-104 <= node values, target <= 104
------------------------------------------------------------------------
*/


// #include<bits/stdc++.h>
// using namespace std;

// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// /*
// Sample structure of the TreeNode:
// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// */
class Solution {
public:
    bool found = false;
    void rec(TreeNode* root, int targetsum, long long cursum){
        if(found) return;
        if (root== NULL) return;

         cursum = root->val + cursum;

        if(root->right == NULL && root->left == NULL){
            if(cursum == targetsum){
                found = true;
            } 
            return;
        }

        rec(root->left,targetsum, cursum);

        rec(root->right, targetsum, cursum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Write your logic here
        rec(root, targetSum, 0);
        return found;
    }
};
// TreeNode* buildTree(const vector<string>& nodes) {
//     if (nodes.empty() || nodes[0] == "null") return nullptr;
    
//     TreeNode* root = new TreeNode(stoi(nodes[0]));
//     queue<TreeNode*> q;
//     q.push(root);
    
//     int i = 1;
//     while (!q.empty() && i < nodes.size()) {
//         TreeNode* curr = q.front();
//         q.pop();
        
//         // Left child
//         if (i < nodes.size() && nodes[i] != "null") {
//             curr->left = new TreeNode(stoi(nodes[i]));
//             q.push(curr->left);
//         }
//         i++;
        
//         // Right child
//         if (i < nodes.size() && nodes[i] != "null") {
//             curr->right = new TreeNode(stoi(nodes[i]));
//             q.push(curr->right);
//         }
//         i++;
//     }
//     return root;
// }

// int main() {
//     int n;
//     if (!(cin >> n)) return 0;
    
//     vector<string> nodes(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nodes[i];
//     }
    
//     int targetSum;
//     if (!(cin >> targetSum)) return 0;
    
//     TreeNode* root = buildTree(nodes);
    
//     Solution solution;
//     if (solution.hasPathSum(root, targetSum)) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }
    
//     return 0;
// }