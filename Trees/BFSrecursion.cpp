/*Level Order Traversal of Binary Tree
Difficulty: MEDIUM | Max Score: 50
You are given Root node of a Binary Tree.

Your task is to return Level Order Traversal of the Tree.



 

Example:

Input: 
      5
     / \
    2   9
     \   \
      6   3
     / \
    12  8

Output: [[5],[2,9],[6,3],[12,8]]
Explanation: 
 

Constraints:

0 <= No. of nodes <= 104*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
Sample structure of the TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Write your logic here
  vector<vector<int>> ans;

    if(root == nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int levelSize = q.size();
        vector<int> curlevel;

        for(int i = 0; i < levelSize; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            curlevel.push_back(node->val);

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }

        ans.push_back(curlevel);
    }

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
        
//         if (i < nodes.size() && nodes[i] != "null") {
//             curr->left = new TreeNode(stoi(nodes[i]));
//             q.push(curr->left);
//         }
//         i++;
        
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
//     vector<vector<int>> result = solution.levelOrder(root);
    
//     // Explicitly print a newline for empty results to satisfy the grader
//     if (result.empty()) {
//         cout << endl;
//     } else {
//         for (const auto& level : result) {
//             for (int i = 0; i < level.size(); ++i) {
//                 cout << level[i] << (i == level.size() - 1 ? "" : " ");
//             }
//             cout << endl;
//         }
//     }
    
//     return 0;
// }