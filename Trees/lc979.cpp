//leetcode 979
//postorder , keep balance as +ve or -ve, send the remaining balance of its subtree to the parent
//sum of all nodes = n = no of nodes
//moves will be equal to balance recieved by parent

int left = p(node->left);
int right = p(node->right);

moves += abs(left) + abs(right);
return node->val + left + right -1;