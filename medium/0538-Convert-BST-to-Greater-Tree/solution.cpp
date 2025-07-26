class Solution {
public:
  void helper(TreeNode* root, int &pre) {
    if (!root) return;
    
    helper(root->right, pre); // right
    root->val = root->val + pre; // middle
    pre = root->val;
    
    helper(root->left, pre); // left 
  }

  TreeNode *convertBST(TreeNode *root) {
    if (!root) return nullptr;
    int pre = 0;
    helper(root, pre);
    return root;
  }
};