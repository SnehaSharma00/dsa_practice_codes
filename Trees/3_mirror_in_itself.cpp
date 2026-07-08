/*Mirror in itself
Difficulty: EASY | Max Score: 25
You are given Root node of a Binary Tree.

Your task is to find whether it is Symmetric around the axis passing down through the Root node.

 

Example 1:

Input: 
        5
       / \
      3   3
     / \ / \
    4  8 4  8
        
Output: false
Explanation: This tree is not symmetric along thr axis draw below:
        5
       /|\
      3 | 3
     / \|/ \
    4  8|4  8
        |




Example 2:

Input: 
      4
     / \
    1   1

Output: true
Explanation: This tree is symmetric along the axis.
 

Constraints:

0 <= Number of nodes in the tree <= 105*/

//---------------------------------------------------------------------
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
    bool same(TreeNode* p, TreeNode* q){
        if(p==NULL && q== NULL) return true;
        if(p==NULL || q== NULL) return false;

        return(p->val == q->val && same(p->left , q->right) && same(p->right, q->left));

    }
    bool isSymmetric(TreeNode* root) {
        // Write your logic here
        if(root==NULL) return true;
        return same(root->left, root->right);
        
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
    
//     TreeNode* root = buildTree(nodes);
    
//     Solution solution;
//     if (solution.isSymmetric(root)) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }
    
//     return 0;
// }