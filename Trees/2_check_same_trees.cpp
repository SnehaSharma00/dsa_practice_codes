/*Same Same
Difficulty: EASY | Max Score: 25
You are given Root nodes of two binary trees.

Your task is to find whether the given two trees are exactly same or not.



 

Example 1:

Input: 
    2              2
   / \            / \
  9   7          9   7 
   \  /\        /   / \
   5 3  8      5   3   8

Output: False
Explanation: Values of nodes are same but not the chirality(directions)


Example 2:

Input: 
   1         1
    \         \   
     3         3
Output: True
Explanation: Everything in both the trees are same.
 

Constraints:

0 <= Number of nodes in the trees <= 105*/

//-------------------------------------------------------------------
// #include <bits/stdc++.h>

// using namespace std;

// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
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
// class Solution {
// public:
// bool rec(TreeNode* p, TreeNode* q){
    
//     if(p->val == q->val){
        
//     }
//}-------------------------------------------------------------------------
//solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Write your logic here
        if(p==NULL && q==NULL) return true;
        if(p == NULL || q== NULL) return false;
        return ((p->val== q->val ) && isSameTree(p->left, q->left)&& isSameTree(p->right, q->right));
    }
};
//-----------------------------------------------------------------------
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
//     // Read first tree
//     if (!(cin >> n)) return 0;
//     vector<string> nodesP(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> nodesP[i];
//     }
    
//     // Read second tree
//     int m;
//     if (!(cin >> m)) return 0;
//     vector<string> nodesQ(m);
//     for (int i = 0; i < m; ++i) {
//         cin >> nodesQ[i];
//     }
    
//     TreeNode* p = buildTree(nodesP);
//     TreeNode* q = buildTree(nodesQ);
    
//     Solution solution;
//     if (solution.isSameTree(p, q)) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }
    
//     return 0;
// }