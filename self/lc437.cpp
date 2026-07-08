//path sum 3 
class Solution {
public:
    void rec(TreeNode* root, int targetSum, map<int, int> &freq , int prefsum){
        if(root->right == nullptr && root->right == nullptr){
            
        }
        int prefsum = root->val + prefsum;
        freq[prefsum]++;
        rec(root->left, targetSum, freq, prefsum);
        rec(root->right, targetSum, freq, prefsum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        map<int,int>prefsum;
        

    }
};