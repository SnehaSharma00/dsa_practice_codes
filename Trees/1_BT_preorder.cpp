/*Binary Tree Preorder Traversal
Difficulty: EASY | Max Score: 25
Given Root node of a binary Tree.

Return the Preorder traversal order of that tree.



Example:

Input: 
     1
    / \
   2   3
      / \
     4   5
Output: [1,2,3,4,5]
Explanation: Given output is the Preorder traversal order of the given binary tree
 

Constraints:

0 <= Number of Nodes <= 105*/


//-----------------------------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;

// class TreeNode {
//     public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// /*
// Sample structure of the TreeNode:
// class TreeNode {
//     public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
// */

class Solution {
    public:
    void preorder(TreeNode* node , vector<int>&ans){
        if(node==NULL)return;
        
        ans.push_back(node->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // Write your logic here
        vector<int>ans;
        preorder(root, ans);
        return ans;

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

//     if (n == 0) {
//         cout << endl;
//         return 0;
//     }

//     vector<string> nodes(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nodes[i];
//     }

//     TreeNode* root = buildTree(nodes);

//     Solution solution;
//     vector<int> result = solution.preorderTraversal(root);

//     // Print the result array space-separated
//     for (int i = 0; i < result.size(); ++i) {
//         cout << result[i] << (i == result.size() - 1 ? "" : " ");
//     }
//     cout << endl;

//     return 0;
// }