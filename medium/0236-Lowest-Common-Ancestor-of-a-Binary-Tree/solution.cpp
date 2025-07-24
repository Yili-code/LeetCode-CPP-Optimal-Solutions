class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q); // left
    TreeNode* right = lowestCommonAncestor(root->right, p, q); // right 
    
    if (left && right) return root; // middle

    return left ? left : right;
  }
};

